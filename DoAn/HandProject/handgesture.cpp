#include "handGesture.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#ifdef __linux__

#include <wiringPi.h>
#define LED1 17
#define LED2 27
#define LED3 22
#define LED4 13
#define LED5 19
#define LED_NO 26

#endif

using namespace cv;
using namespace std;

//hàm set trạng thái của LED
#ifdef __linux__
void setLED(int num, int onoff){
    switch (num){
    case 1: digitalWrite(LED1, onoff); break;
    case 2: digitalWrite(LED2, onoff); break;
    case 3: digitalWrite(LED3, onoff); break;
    case 4: digitalWrite(LED4, onoff); break;
    case 5: digitalWrite(LED5, onoff); break;
    default: cout << "Pin error" << endl; break;
    }
    //digitalWrite(LED_NO, 1);
    //delay(250);
    //digitalWrite(LED_NO, 0);
}
#endif

//hàm khởi tạo giá trị
HandGesture::HandGesture(){
    frameNumber = 0;
    nrNoFinger = 0;
    giatricu = 0;
    giatrimoi = 0;
    for (int i = 0; i < 5; i++){
        stateLight[i] = 0;
    }
    mostFrequentFingerNumber = 0;
    fontFace = FONT_HERSHEY_PLAIN;
}

//khởi tạo giá trị
void HandGesture::setHandGesture(vector<Point> contourShape, vector<int> hullInt, vector<Point> hullPoint,
    vector<Vec4i> defectShape, Rect bRectShape){

    initVectors();
    contours = contourShape;
    hullI = hullInt;
    hullP = hullPoint;
    defects = defectShape;
    bRect = bRectShape;
    fontFace = FONT_HERSHEY_PLAIN;

    bRect_height = bRect.height;
    bRect_width = bRect.width;

}

//trả về điểm trung tâm của đường biên bàn tay
Point HandGesture::getPointCenter(){
    Point p;
    cv::Moments mo;
    mo = cv::moments(contours);
    Point center;
    center = cv::Point(mo.m10 / mo.m00, mo.m01 / mo.m00);
    return center;
}

Point HandGesture::getPointHighest(){
    return pointHighest;
}

//khởi tạo các giá trị
void HandGesture::initVectors(){
    hullI = vector<int>(contours.size());
    hullP = vector<Point>(contours.size());
    defects = vector<Vec4i>(contours.size());
}

//ô vuông bao ngoài đường viền tay
void HandGesture::analyzeContours(){
    bRect_height = bRect.height;
    bRect_width = bRect.width;
}

//chuyển dạng dữ liệu bool sang string
string HandGesture::bool2string(bool tf){
    if (tf)
        return "true";
    else
        return "false";
}

//chuyển đổi dữ liệu từ int sang string
string HandGesture::intToString(int number){
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

//kiểm tra có phải là bàn tay
bool HandGesture::detectIfHand(Mat src){
    analyzeContours();
    double h = bRect_height;
    double w = bRect_width;
    isHand = true;
    if (fingerTips.size() > 5){
        isHand = false;
    }
    else if (4 * w >= 3 * src.rows)
    {
        isHand = false;
    }
    else if (8 * h >= 7 * src.cols)
    {
        isHand = false;
    }
    else if (h == 0 || w == 0){
        isHand = false;
    }
    else if (h < 30 && w < 30){
        isHand = false;
    }
    else if (h / w > 4 || w / h >4){
        isHand = false;
    }
    else if (bRect.x < 20){
        isHand = false;
    }
    else if (w > h){
        isHand = false;
    }
    return isHand;

}

//hàm tính toán khoảng cách của 2 điểm
float HandGesture::distanceP2P(Point a, Point b){
    float d = sqrt(fabs(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
    return d;
}

//tính toán góc giữa 3 điểm
float HandGesture::getAngle(Point s, Point f, Point e){
    float l1 = distanceP2P(f, s);
    float l2 = distanceP2P(f, e);
    float dot = (s.x - f.x)*(e.x - f.x) + (s.y - f.y)*(e.y - f.y);
    float angle = acos(dot / (l1*l2));
    angle = angle * 180 / PI;
    return angle;
}
//tính toán số ngón tay xuât hiện nhiều nhất
void HandGesture::computeFingerNumber(){

    //sắp xếp theo thứ tự
    std::sort(fingerNumbers.begin(), fingerNumbers.end());
    int frequentNr;
    int thisNumberFreq = 1;
    int highestFreq = 1;

    frequentNr = fingerNumbers[0];

    for (int i = 1; i<fingerNumbers.size(); i++){
        if (fingerNumbers[i - 1] != fingerNumbers[i]){
            if (thisNumberFreq>highestFreq){

                frequentNr = fingerNumbers[i - 1];
                highestFreq = thisNumberFreq;

            }
            thisNumberFreq = 0;
        }
        thisNumberFreq++;
    }

    if (thisNumberFreq > highestFreq){
        frequentNr = fingerNumbers[fingerNumbers.size() - 1];
    }

    mostFrequentFingerNumber = frequentNr;
}

void HandGesture::addFingerNumberToVector(){
    int i = fingerTips.size();
    fingerNumbers.push_back(i);
}

// calculate most frequent numbers of fingers
// over 20 frames
// tính toán số ngón tay trên 20 khung
void HandGesture::getFingerNumber(Mat src){
    //removeRedundantFingerTips();
    giatricu = mostFrequentFingerNumber;
    //giá trị mới sẽ được hiển thị trong 10 frame
    //lấy giá trị trong 10 frame rồi tính xem số ngón tay hiển thị nhiều nhất
    if (nrNoFinger > 6){
        numberColor = Scalar(0, 0, 0); // gia tri cu
        //lấy số ngón tay trong 10 frame
        addFingerNumberToVector(); //sẽ lấy 10 ảnh để tính ra ảnh xuất hiện nhiều nhất
        if (frameNumber > 6){
            nrNoFinger = 0;
            frameNumber = 0;
            //tính toán số ngón tay xuât hiện nhiều lần nhất
            computeFingerNumber();
#ifdef __linux__
            giatrimoi = mostFrequentFingerNumber;
            if (giatricu == giatrimoi){
            }
            else{
                /*if (giatricu == 0 && giatrimoi != 0){
                    setLED(giatrimoi, 1);
                    }
                    if (giatricu != 0 && giatrimoi != 0){
                    setLED(giatrimoi, 1);
                    }
                    if (giatricu != 0 && giatrimoi == 0){
                    setLED(giatricu, 0);
                    }
                */
                if(giatricu != giatrimoi){
                    if (giatrimoi !=0)
                        setLED(giatrimoi, 1);
                    if (giatricu !=0)
                        setLED(giatricu, 0);
                }
            }
#endif
            fingerNumbers.clear();
        }
        else{
            frameNumber++;
        }
    }
    else{
        nrNoFinger++;
        numberColor = Scalar(255, 255, 0); // gia tri moi cap nhat
    }
    addNumberToImg(src);
}
//hiển thị số ngón tay xuất hiện nhiều nhất
void HandGesture::addNumberToImg(Mat src){
    int xPos = 10;
    int yPos = 10;
    int offset = 30;
    float fontSize = 1.5f;
    int fontFace = FONT_HERSHEY_PLAIN;
    cv::Moments mo;
    mo = cv::moments(contours);
    Point center;
    center = cv::Point(mo.m10 / mo.m00, mo.m01 / mo.m00);
    putText(src, intToString(mostFrequentFingerNumber), Point(center.x, center.y + 30), fontFace, 2.0f, numberColor, 2);
}
//hàm trả về tọa độ các ngón tay
vector<Point> HandGesture::getFingerTips(Mat src){
    vector<Vec4i> newDefects = defects;
    int startidx, endidx, faridx;//diem dau diem cuoi diem giua
    vector<Vec4i>::iterator d = newDefects.begin();
    vector<Vec4i> clone;
    vector<Point> fingerTipsTest;
    cv::Moments mo;
    mo = cv::moments(contours);
    Point center;
    center = cv::Point(mo.m10 / mo.m00, mo.m01 / mo.m00);
    int i = 0;
    while (d != newDefects.end()) {
        Vec4i& v = (*d);
        startidx = v[0];	Point ptStart(contours[startidx]);
        endidx = v[1];		Point ptEnd(contours[endidx]);
        faridx = v[2];		Point ptFar(contours[faridx]);
        int depth = v[3] / 256;
        if (depth > 20 && depth < 80)
        {
            clone.push_back(v);
        }
        d++;
    }
    newDefects.swap(clone);
    d = newDefects.begin();
    while (d != newDefects.end()) {
        Vec4i& v = (*d);
        int startidx = v[0]; Point ptStart(contours[startidx]);
        int endidx = v[1]; Point ptEnd(contours[endidx]);
        int faridx = v[2]; Point ptFar(contours[faridx]);
        if (i != 0){
            fingerTipsTest.push_back(ptEnd);
        }
        else{
            if (distanceP2P(ptStart, ptEnd) < 30 || getAngle(ptStart, center, ptEnd)<30){}
            else{
                fingerTipsTest.push_back(ptStart);
                fingerTipsTest.push_back(ptEnd);
            }
        }
        d++;
        i++;
    }
    Point ptStartOld;
    if (fingerTipsTest.size()<3){
        fingerTipsTest.clear();
        i = 0;
        d = newDefects.begin();
        while (d != newDefects.end()) {
            Vec4i& v = (*d);
            int startidx = v[0]; Point ptStart(contours[startidx]);
            int endidx = v[1]; Point ptEnd(contours[endidx]);
            int faridx = v[2]; Point ptFar(contours[faridx]);
            if (i != 0){
                if (ptEnd.x >= (bRect.br().x - 20) && ptEnd.y >= (bRect.tl().y + bRect.height / 3)){
                }
                else{
                    if ((distanceP2P(ptStartOld, ptEnd) < 15 || getAngle(ptStartOld, center, ptEnd) < 10)){
                    }
                    else{
                        fingerTipsTest.push_back(ptEnd);
                    }
                }
            }
            else{
                if (!(ptStart.x >= (bRect.br().x - 20) && ptStart.y >= (bRect.tl().y + bRect.height / 3))){
                    if (!(ptEnd.x >= (bRect.br().x - 20) && ptEnd.y >= (bRect.tl().y + bRect.height / 3))){
                        if (!((int)distanceP2P(center, ptStart) < 40 || (int)distanceP2P(center, ptStart) < 40)){
                            if ((distanceP2P(ptStart, ptEnd) < 15 || getAngle(ptStart, center, ptEnd) < 10)){
                                fingerTipsTest.push_back(ptStart);
                            }
                            else{
                                fingerTipsTest.push_back(ptStart);
                                ptStartOld = ptStart;
                                fingerTipsTest.push_back(ptEnd);
                            }
                        }
                    }
                }
            }
            d++;
            i++;
        }
    }

    fingerTips.swap(fingerTipsTest);

    if (fingerTips.size() == 1){
        fingerTips.clear();
        checkForOneFinger(src);
    }
    else{
        if (fingerTips.size() > 0){
            checkFingerPoint();
        }
        else{
            checkForOneFinger(src);
        }
    }
    if (fingerTips.size() > 5){
        fingerTips.clear();
    }
    return fingerTips;
}

void HandGesture::checkFingerPoint(){
    cv::Moments mo;
    mo = cv::moments(contours);
    Point center;
    center = cv::Point(mo.m10 / mo.m00, mo.m01 / mo.m00);
    for (int i = 0; i < fingerTips.size() - 1; i++){
        if (getAngle(fingerTips[i], center, fingerTips[i + 1]) > 110){
            fingerTips.clear();
            break;
        }
        if (fingerTips[i].y > (bRect.y + bRect.height / (1.5))){
            fingerTips.clear();
            break;
        }
    }
}

void HandGesture::checkForOneFinger(Mat src){

    int yTol = bRect.height / 6;
    Point highestP;
    highestP.y = src.rows;
    vector<Point>::iterator d = contours.begin();
    while (d != contours.end()) {
        Point v = (*d);
        if (v.y < highestP.y){
            highestP = v;
        }
        d++;
    }int n = 0;
    d = hullP.begin();
    while (d != hullP.end()) {
        Point v = (*d);
        if (v.y < highestP.y + yTol && v.y != highestP.y && v.x != highestP.x){
            n++;
        }
        d++;
    }if (n == 0){
        pointHighest = highestP;
        fingerTips.push_back(highestP);
    }
}

