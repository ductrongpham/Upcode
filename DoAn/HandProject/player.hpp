#ifndef PLAYER_HPP
#define PLAYER_HPP

#ifdef __linux__
#else

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <process.h>
#include <ctime>
#define _WIN32_WINNT 0x0501
#include <winuser.h>
#pragma comment(lib,"ws2_32.lib" )
unsigned int __stdcall ServClient(void *data);

#endif

#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "handGesture.hpp"
#include "shape.hpp"
#include "myImage.hpp"
#include "roi.hpp"
#include <opencv2/core/utility.hpp>
#define ORIGCOL2COL CV_BGR2HLS
#define COL2ORIGCOL CV_HLS2BGR
#define NSAMPLES 7 //7 Diem lay mau mau da.
#define PI 3.14159265358979323846 //su dung de tinh goc

#include <math.h>
#include <string>
#include <vector>
#include <cmath>

#ifdef __linux__

#include <wiringPi.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define LED1 17
#define LED2 27
#define LED3 22
#define LED4 13
#define LED5 19
#define LED_NO 26

#endif
using namespace std;
using namespace cv;
class Player : public QThread
{    Q_OBJECT
 private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
//    VideoCapture capture;
    Mat RGBframe;
    QImage img;
 signals:
 //Signal to output frame to be displayed
      void processedImage(const QImage &image);
      void processedBackground(const QImage &image);
      void processedHistogram(const QImage &image);
      void processedMouse(const QImage &image);
      void processedArrow(const QImage &imge);
      void processedPercent(const int &per,const double &fps);
      void processedHand(const int &lr);
      void processedNum(const int &num);
 protected:
     void run();
 #ifdef __linux__
     void msleep(int ms);   
 #endif
 public:
//_________________________________
      bool flag0 = false;
      bool flag1 = false;
      bool flag2 = false;
      bool flag3 = false;
      bool flag4 = false;
      bool flag5 = false;
      bool flag6 = false;
      bool flag7 = false;
      bool flagClose = false;
      bool ISHAND = false;
       int time_wait = 5;
    Rect mySelection; //selection chon
    int flagOn = 0; //cờ thông báo bắt đàu thực hiện sau khi nhấn start
    int fontFace = FONT_HERSHEY_PLAIN; //font chữ
    int square_len; //kich thước của 1 ROI
    int avgColor[NSAMPLES][3]; // chưa lần lượt bộ 3 tham số HLS của từng ô mẫu màu
    int c_lower[NSAMPLES][3]; //chỉ số lơn nhất lần lượt của các tham số HLS
    int c_upper[NSAMPLES][3]; //chỉ số tối thiểu lần lượt của các tham số HLS
    int threshold_bar_static = 0;
    int threshold_bar_dynamic = 0;
    vector <MyRoi> roi;
    void waitForPalmCover(MyImage* m);
    void average(MyImage *m);
    void initWindows();
    void inittrackbar();
    void produceBinaries(MyImage *m);
    int* findBiggestContour(vector<vector<Point> > contours);
    int getMedian(vector<int> val);
    void printText(Mat src, string text);
    void getAvgColor(MyRoi roi, int avg[3]);
    void normalizeColors();
    void showWindows(Mat src, Mat bw);
    void makeContours(Mat src,Mat bw, Shape *sh, HandGesture *hg1,Rect boxCheckHand);
    void analyContour(Mat src, Shape *sh, int idxSh, HandGesture *hg,Rect boxCheckHand);
    float returnPercentDiff(Mat src_base, Mat src_test1);
    string bool2string(bool tf);
    void CallBackFunc(int event, int x, int y, int flags, void* userdata);
    Mat returnSubBackgroundStatic(Mat frameCurrent, Mat framePrev);
    Mat returnSubBackgroundDynamic(Ptr<BackgroundSubtractor> bg_model, Mat img);
    Mat returnImagePrev(VideoCapture cap);
    void waitStartProgress(MyImage m);
    void convertCamera(Mat &image);
    void drawHist(String name, Mat src);
    Mat canBangHistogram(Mat &imageSrc);
    double getOrientation(vector<Point> &contours, Mat &img);
    Rect camShiftDemo(Mat &src, Mat &imageHLS, Mat& maskHLS, Mat &hue, Mat &hist, const float * phranges, int &hsize, Rect &trackWindow, bool &flagCam);
    Mat cropHand(Mat &imageHand, Rect trackBox);
    #ifdef __linux__
    void sig_handler(int signo);
    void error(const char *msg);
    struct PointCenter
    {
     int x; //Tọa độ x
     int y; //Tọa độ y
     int fingerNum; //Số ngón tay
     bool arrowKeyLeft;
     bool arrowKeyRight;
    };
    #else
    void SetArrowLeft(BOOL bState);
    void SetArrowRight(BOOL bState);
    void MouseMove(int dx, int dy);
    void MouseLeftBtnDown();
    void MouseLeftBtnUp();
    void MouseRightBtnDown();
    void MouseRightBtnUp();
    void controlCursor(int &flagC, int&flagLC, int xx, int yy, int xcu, int ycu, HandGesture hg1);
    #endif
//_________________________________
    //Constructor
    Player(QObject *parent = 0);
    //Destructor
    ~Player();
    //Load a video from memory
    bool loadVideo(String filename);
    //Play the video
    void Play();
    //Stop the video
    void Stop();
    //check if the player has been stopped
    bool isStopped() const;
    int isReseted() const;

    bool flagReset = false;
    int resetProcess = 0;

    void imShow(Mat frame);
    void bgShow(Mat frame);
    void hisShow(Mat frame);
    void mouseShow(Mat frame);
    void percentShow(int per,double fps);
    void arrowShow(Mat frame);
    void handShow(int lr);
    void numShow(int num);
    void WaitKeyOS(int ms);
     bool flagVideo = false;
     String fileName;
};
#endif // PLAYER_HPP
