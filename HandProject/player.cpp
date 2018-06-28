#include "player.hpp"

//_________________________________________________________________________________
#ifdef __linux__
void Player::msleep(int ms){
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}
#endif

void Player::WaitKeyOS(int ms){
#ifdef __linux__
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#else
    if(flagVideo){
        Sleep(ms);
    }else{
        waitKey(ms);
    }
#endif
}

void Player::hisShow(Mat frame){
    Mat framecp;
    QImage img;
    frame.copyTo(framecp);
    resize(framecp, framecp, cv::Size(), 1, 1);
    if (frame.channels()== 3){
        cv::cvtColor((framecp), RGBframe, CV_BGR2RGB);
        img = QImage((const unsigned char*)(RGBframe.data),
                          RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
    }
    else
    {
        img = QImage((const unsigned char*)(framecp.data),
                             framecp.cols,framecp.rows,QImage::Format_Indexed8);
    }
    emit processedHistogram(img);
}

void Player::arrowShow(Mat frame){
    Mat framecp;
    QImage img;
    frame.copyTo(framecp);
    resize(framecp, framecp, cv::Size(), 1, 1);
    if (frame.channels()== 3){
        cv::cvtColor((framecp), RGBframe, CV_BGR2RGB);
        img = QImage((const unsigned char*)(RGBframe.data),
                          RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
    }
    else
    {
        img = QImage((const unsigned char*)(framecp.data),
                             framecp.cols,framecp.rows,QImage::Format_Indexed8);
    }
    emit processedArrow(img);
}

void Player::mouseShow(Mat frame){
    Mat framecp;
    QImage img;
    frame.copyTo(framecp);
    resize(framecp, framecp, cv::Size(), 1, 1);
    if (frame.channels()== 3){
        cv::cvtColor((framecp), RGBframe, CV_BGR2RGB);
        img = QImage((const unsigned char*)(RGBframe.data),
                          RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
    }
    else
    {
        img = QImage((const unsigned char*)(framecp.data),
                             framecp.cols,framecp.rows,QImage::Format_Indexed8);
    }
    emit processedMouse(img);
}

void Player::percentShow(int per,double fps){
    emit processedPercent(per,fps);
}

void Player::handShow(int lr){
    emit processedHand(lr);
}

void Player::mouseCtrlShow(int ctrl){
    emit processedMouseCtrl(ctrl);
}

void Player::videoStop(bool flagVideoStop){
    emit processVideoStop(flagVideoStop);
}

void Player::numShow(int num){
    emit processedNum(num);
}

void Player::imShow(Mat frame){
    Mat framecp;
    QImage img;
    frame.copyTo(framecp);
    resize(framecp, framecp, cv::Size(), 1, 1);
    if (frame.channels()== 3){
        cv::cvtColor((framecp), RGBframe, CV_BGR2RGB);
        img = QImage((const unsigned char*)(RGBframe.data),
                          RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
    }
    else
    {
        img = QImage((const unsigned char*)(framecp.data),
                             framecp.cols,framecp.rows,QImage::Format_Indexed8);
    }
    emit processedImage(img);
}

void Player::bgShow(Mat frame){
    Mat framecp;
    QImage img;
    frame.copyTo(framecp);
    resize(framecp, framecp, cv::Size(), 1, 1);
    if (frame.channels()== 3){
        cv::cvtColor((framecp), RGBframe, CV_BGR2RGB);
        img = QImage((const unsigned char*)(RGBframe.data),
                          RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
    }
    else
    {
        img = QImage((const unsigned char*)(framecp.data),
                             framecp.cols,framecp.rows,QImage::Format_Indexed8);
    }
    emit processedBackground(img);
}

//______________________________________________________
Player::Player(QObject *parent)
 : QThread(parent)
{
    stop = true;
    resetProcess = true;
}

bool Player::loadVideo(String filename) {
    return false;
}

void Player::Play()
{
    if (!isRunning()) {
        if (isStopped()){
            stop = false;
        }
        start(LowPriority);
    }
}

int Player::isReseted()const{
    return this->resetProcess;
}

Player::~Player()
{
    mutex.lock();
    stop = true;
    condition.wakeOne();
    mutex.unlock();
    wait();
}
void Player::Stop()
{
    stop = true;
}
bool Player::isStopped() const{
    return this->stop;
}
//________________________________________________________________
void Player::waitStartProgress(MyImage m){
    while (flagOn != 1){
        m.cap >> m.src;
        convertCamera(m.src);
        vector <MyRoi> roi7;
        //vẽ ra 7ROI để lấy mẫu màu da để tính toán ra các tham số HLS
        roi7.push_back(MyRoi(Point(m.src.cols / 3 - 40, m.src.rows / 6), Point(m.src.cols / 3 - 40 + square_len, m.src.rows / 6 + square_len), m.src)); // o so 1
        roi7.push_back(MyRoi(Point(m.src.cols / 2.5 - 40, m.src.rows / 2.5), Point(m.src.cols / 2.5 - 40 + square_len, m.src.rows / 2.5 + square_len), m.src));//o so 2
        roi7.push_back(MyRoi(Point(m.src.cols / 4 - 40, m.src.rows / 2), Point(m.src.cols / 4 - 40 + square_len, m.src.rows / 2 + square_len), m.src)); // o so 3
        roi7.push_back(MyRoi(Point(m.src.cols / 2 - 40, m.src.rows / 2), Point(m.src.cols / 2 - 40 + square_len, m.src.rows / 2 + square_len), m.src));// o so 4
        roi7.push_back(MyRoi(Point(m.src.cols / 2.5 - 40, m.src.rows / 1.8), Point(m.src.cols / 2.5 - 40 + square_len, m.src.rows / 1.8 + square_len), m.src)); // o 5
        roi7.push_back(MyRoi(Point(m.src.cols / 3 - 40, m.src.rows / 1.5), Point(m.src.cols / 3 - 40 + square_len, m.src.rows / 1.5 + square_len), m.src));// o so 6
        roi7.push_back(MyRoi(Point(m.src.cols / 2 - 40, m.src.rows / 1.5), Point(m.src.cols / 2 - 40 + square_len, m.src.rows / 1.5 + square_len), m.src));//o so 7

        for (int j = 0; j < NSAMPLES; j++){
            roi7[j].drawRect(m.src);
        }
//        imshow("Wait", m.src);
        imShow(m.src);
//        if (cv::waitKey(30) == char('q')) break;
        WaitKeyOS(30);
        if(flagClose){
            break;
        }
        roi7.clear();
    }
}

void Player::convertCamera(Mat &image){
#ifdef __linux__
    flip(image, image, 1);
#else
    flip(image, image, 1);
#endif
}

Mat Player::returnImagePrev(VideoCapture cap){
    Mat framePrev;
    Mat src;
    for (int i = 0; i < 40; i++){
        cap >> src;
        //video.write(src);
        convertCamera(src);
        if (i <= 20){
            putText(src, "Sample image", Point(src.cols / 5, src.rows / 2), FONT_HERSHEY_PLAIN, 1.5f, Scalar(41, 0, 223), 2);
        }
        else{
            putText(src, "Sample image", Point(src.cols / 5, src.rows / 2), FONT_HERSHEY_PLAIN, 1.5f, Scalar(191, 178, 0), 2);
        }
        if (i == 20){
            cap >> framePrev;
            //video.write(framePrev);
            convertCamera(framePrev);
        }
        imShow(src);
//        if (cv::waitKey(30) == char('q')) break;
        WaitKeyOS(30);
    }
//    destroyWindow("Sample Image");
    return framePrev;
}
void Player::waitForPalmCover(MyImage *m){

    m->cap >> m->src; // truyen anh tu camera vao;
    convertCamera(m->src);

    mySelection.x = Point(m->src.cols / 4 - 40, m->src.rows / 2).x;
    mySelection.y = Point(m->src.cols / 3 - 40, m->src.rows / 6).y;
    mySelection.width = std::abs(Point(m->src.cols / 2 - 60 + square_len, m->src.rows / 1.5 + square_len).x - Point(m->src.cols / 4 - 40, m->src.rows / 2).x);
    mySelection.height = std::abs(Point(m->src.cols / 2 - 60 + square_len, m->src.rows / 1.5 + square_len).y - Point(m->src.cols / 3 - 40, m->src.rows / 6).y);

    //Vẽ 7 khung ảnh nhỏ ddeeer nhận mẫu
    roi.push_back(MyRoi(Point(m->src.cols / 3 - 40, m->src.rows / 6), Point(m->src.cols / 3 - 40 + square_len, m->src.rows / 6 + square_len), m->src)); //1
    roi.push_back(MyRoi(Point(m->src.cols / 2.5 - 40, m->src.rows / 2.5), Point(m->src.cols / 2.5 - 40 + square_len, m->src.rows / 2.5 + square_len), m->src));//2
    roi.push_back(MyRoi(Point(m->src.cols / 4 - 40, m->src.rows / 2), Point(m->src.cols / 4 - 40 + square_len, m->src.rows / 2 + square_len), m->src));//3
    roi.push_back(MyRoi(Point(m->src.cols / 2 - 40, m->src.rows / 2), Point(m->src.cols / 2 - 40 + square_len, m->src.rows / 2 + square_len), m->src));//4
    roi.push_back(MyRoi(Point(m->src.cols / 2.5 - 40, m->src.rows / 1.8), Point(m->src.cols / 2.5 - 40 + square_len, m->src.rows / 1.8 + square_len), m->src));//5
    roi.push_back(MyRoi(Point(m->src.cols / 3 - 40, m->src.rows / 1.5), Point(m->src.cols / 3 - 40 + square_len, m->src.rows / 1.5 + square_len), m->src));//6
    roi.push_back(MyRoi(Point(m->src.cols / 2 - 40, m->src.rows / 1.5), Point(m->src.cols / 2 - 40 + square_len, m->src.rows / 1.5 + square_len), m->src));//7

    for (int i = 0; i < 30; i++){
        m->cap >> m->src;
        convertCamera(m->src);
        for (int j = 0; j < NSAMPLES; j++){
            roi[j].drawRect(m->src);
        }
        //hiển thị thông tin
        string imgText = string("Cover rectangles with palm");
        printText(m->src, imgText);
        imShow(m->src);
//        if (cv::waitKey(30) >= 0) break;
        WaitKeyOS(30);
    }
}

Mat Player::cropHand(Mat &imageHand, Rect trackBox){
    Size rect_size = trackBox.size();
    Point2f centerBox((trackBox.tl().x + trackBox.br().x) / 2, (trackBox.tl().y + trackBox.br().y) / 2);
    Mat M = getRotationMatrix2D(centerBox, 0, 1.0);
    Mat rotatedMask;
    Mat croppedMask;
    warpAffine(imageHand, rotatedMask, M, imageHand.size(), INTER_CUBIC);
    getRectSubPix(rotatedMask, rect_size, centerBox, croppedMask);
    resize(croppedMask, croppedMask, cv::Size(100,120));
    arrowShow(croppedMask);
    return croppedMask;
}

Rect Player::camShiftDemo(Mat &src, Mat &imageHLS, Mat& maskHLS, Mat &hue, Mat &hist, const float * phranges, int &hsize, Rect &trackWindow, bool &flagCam){

    Mat backproj;
    int ch[] = { 0, 0 };
    hue.create(imageHLS.size(), imageHLS.depth());
    mixChannels(&imageHLS, 1, &hue, 1, ch, 1);

    if (flagCam){
        Mat mroi(hue, mySelection), maskroi(maskHLS, mySelection);
        calcHist(&mroi, 1, 0, maskroi, hist, 1, &hsize, &phranges);
        normalize(hist, hist, 0, 255, CV_MINMAX);
        trackWindow = mySelection;
        flagCam = false;
    }

    calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
    backproj &= maskHLS;
    CamShift(backproj, trackWindow, TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1));
    if (trackWindow.area() <= 1)
    {
        int cols = backproj.cols;
        int rows = backproj.rows;
        int r = (MIN(cols, rows) + 5) / 6;
        trackWindow = Rect(trackWindow.x - r, trackWindow.y - r, trackWindow.x + r, trackWindow.y + r) & Rect(0, 0, cols, rows);
    }
    Rect window(Point(trackWindow.tl().x - 40, trackWindow.tl().y - 40), Point(trackWindow.br().x + 40, trackWindow.br().y + 40));
    rectangle(src, trackWindow, Scalar(216, 220, 15), 2, 8);
    if (window.area() > 0){
        cropHand(src, window);
    }
    return trackWindow;
}


int Player::getMedian(vector<int> val){
    int median;
    size_t size = val.size();
    sort(val.begin(), val.end());
    if (size % 2 == 0)  {
        median = val[size / 2 - 1];
    }
    else{
        median = val[size / 2];
    }
    return median;
}
void Player::getAvgColor(MyRoi roi, int avg[3]){
    Mat r;
    roi.roiPtr.copyTo(r); //copy 1 ROI vao r
    vector<int> hm;
    vector<int> sm;
    vector<int> lm;

    for (int i = 0; i < r.rows; i++){
        for (int j = 0; j < r.cols; j++){
            Vec3b hsv = r.at<Vec3b>(i, j);
            hm.push_back(hsv.val[0]);
            sm.push_back(hsv.val[1]);
            lm.push_back(hsv.val[2]);
        }
    }

    avg[0] = getMedian(hm);
    avg[1] = getMedian(sm);
    avg[2] = getMedian(lm);
}

void Player::average(MyImage *m){
    m->cap >> m->src;
    convertCamera(m->src);
    for (int i = 0; i < 10; i++){
        m->cap >> m->src;
        convertCamera(m->src);
        cvtColor(m->src, m->src, ORIGCOL2COL);// chuyển từ RGB sang HLS để tách ra tham số HLS // cho doi mau cua o tu xanh la thanh trang
        for (int j = 0; j < NSAMPLES; j++){
            getAvgColor(roi[j], avgColor[j]); //avgColor[NSAMPLES][3]
            roi[j].drawRect(m->src);
        }
        cvtColor(m->src, m->src, COL2ORIGCOL);
        string imgText = string("Finding average color of hand");
        printText(m->src, imgText);
        imShow(m->src);
//        if (cv::waitKey(30) >= 0) break;
        WaitKeyOS(30);
    }
}

void Player::printText(Mat src, string text){
    int fontFace = FONT_HERSHEY_PLAIN;
    putText(src, text, Point(src.cols / 2, src.rows / 10), fontFace, 1.2f, Scalar(200, 0, 0), 2);
}
void Player::inittrackbar(){

    //các tham số cơ bản của màu da tay
    for (int i = 0; i < NSAMPLES; i++){
        c_lower[i][0] = 20;
        c_upper[i][0] = 40;
        c_lower[i][1] = 30;
        c_upper[i][1] = 255;
        c_lower[i][2] = 15;
        c_upper[i][2] = 255;
    }

    threshold_bar_static = 150;
    createTrackbar("H-Upper", "trackb_n", &c_upper[0][0], 180);
    createTrackbar("H-Lower", "trackb_n", &c_lower[0][0], 180);
    createTrackbar("S-Upper", "trackb_n", &c_upper[0][1], 255);
    createTrackbar("S-Lower", "trackb_n", &c_lower[0][1], 255);
    createTrackbar("L-Upper", "trackb_n", &c_upper[0][2], 255);
    createTrackbar("L-Lower", "trackb_n", &c_lower[0][2], 255);
    createTrackbar("Threshsold", "trackb_n", &threshold_bar_static, 255);
}
void Player::normalizeColors(){
    // copy all boundaries read from trackbar
    // to all of the different boundaries
    for (int i = 1; i < NSAMPLES; i++){ // tại vì các giá trị vào được để trong 0
        for (int j = 0; j < 3; j++){
            c_lower[i][j] = c_lower[0][j];
            c_upper[i][j] = c_upper[0][j];
        }
    }
    // normalize all boundaries so that
    // threshold is within 0-255
    for (int i = 0; i < NSAMPLES; i++){
        //lower: avgColor - c_lower < 0		thì sẽ bằng 0
        if ((avgColor[i][0] - c_lower[i][0]) < 0){
            c_lower[i][0] = avgColor[i][0];
        }
        if ((avgColor[i][1] - c_lower[i][1]) < 0){
            c_lower[i][1] = avgColor[i][1];
        }
        if ((avgColor[i][2] - c_lower[i][2]) <0){
            c_lower[i][2] = avgColor[i][2];
        }

        //upper: avgColor + c_upper > 255	thì sẽ bằng 255
        if ((avgColor[i][0] + c_upper[i][0]) >255){
            c_upper[i][0] = 255 - avgColor[i][0];
        }
        if ((avgColor[i][1] + c_upper[i][1]) > 255){
            c_upper[i][1] = 255 - avgColor[i][1];
        }
        if ((avgColor[i][2] + c_upper[i][2]) > 255){
            c_upper[i][2] = 255 - avgColor[i][2];
        }
    }
}

void Player::produceBinaries(MyImage *m){
    Scalar lowerBound;
    Scalar upperBound;
    for (int i = 0; i < NSAMPLES; i++){
        normalizeColors();
        //avgColor - c_lower < 0	thì sẽ bằng 0
        //avgColor + c_upper > 255	thì sẽ bằng 255
        // còn lại nếu thỏa mãn thì lấy giá trị
        lowerBound = Scalar(avgColor[i][0] - c_lower[i][0], avgColor[i][1] - c_lower[i][1], avgColor[i][2] - c_lower[i][2]);
        upperBound = Scalar(avgColor[i][0] + c_upper[i][0], avgColor[i][1] + c_upper[i][1], avgColor[i][2] + c_upper[i][2]);
        //chứa các ảnh nhị phân có kích thước bẳng 1 nửa thôi
        m->bwList.push_back(Mat(m->srcLR.rows, m->srcLR.cols, CV_8U));
        //tách ra màu cần thiết dựa vào giá trị của trackbar
        inRange(m->srcLR, lowerBound, upperBound, m->bwList[i]);
    }

    //m->bw là tổng của tất cả các bwList
    m->bwList[0].copyTo(m->bw);
    for (int i = 1; i < NSAMPLES; i++){
        m->bw += m->bwList[i];
    }
    medianBlur(m->bw, m->bw, NSAMPLES); // làm mờ để lọc nhiễu
}
int* Player::findBiggestContour(vector<vector<Point> > contours){
    static int index[2];
    int indexOfBiggestContour = -1;
    int indexOfBiggerContour = -1;
    int sizeOfBiggestContour = 0;
    int sizeOfBiggerContour = 0;

    for (int i = 0; i < contours.size(); i++){
        if (contours[i].size() > sizeOfBiggestContour){
            sizeOfBiggestContour = contours[i].size();
            indexOfBiggestContour = i;
        }
    }
    index[0] = indexOfBiggestContour;
    return index;
}

void Player::analyContour(Mat src, Shape *sh, int idxSh, HandGesture *hg, Rect boxCheckHand){
    Rect bRectSh = boundingRect(Mat(sh->contourShape[idxSh]));
    // Find the convex hull object for each contour
    //Tìm phần vỏ lồi của một điểm đặt.
    //tìm tập hợp hullPoint
    convexHull(Mat(sh->contourShape[idxSh]), sh->hullPoint[idxSh], false, true);
    //tìm tập hợp hullInt--được sử dụng để tìm convexityDefects
    convexHull(Mat(sh->contourShape[idxSh]), sh->hullInt[idxSh], false, false);

    //Hàm xấp xỉ 1 đa giác từ những đường cong , kín
    approxPolyDP(Mat(sh->hullPoint[idxSh]), sh->hullPoint[idxSh], 18, true);

    //tìm kiếm ra convexityDefects từ convexHull Int
    if (sh->hullInt[idxSh].size() > 3){
        //Bất kỳ độ lệch nào của vật thể từ conour này có thể được coi là khiếm khuyết lồi.
        convexityDefects(sh->contourShape[idxSh], sh->hullInt[idxSh], sh->defectShape[idxSh]);
    }
    //thiết lập tham số cơ bản cho việc defect bàn tay
    hg->setHandGesture(sh->contourShape[idxSh],
        sh->hullInt[idxSh],
        sh->hullPoint[idxSh],
        sh->defectShape[idxSh],
        bRectSh);
    bool ishand = hg->detectIfHand(src);
    Point center = hg->getPointCenter();
    bool hand = false;
    if (center.x > boxCheckHand.tl().x && center.x < boxCheckHand.br().x){
        if (center.y > boxCheckHand.tl().y && center.y < boxCheckHand.br().y){
            hand = true;
        }
    }
    if (ishand && hand){
        ISHAND = true;
        hg->getFingerNumber(src);
        //putText(m->src, bool2string(ishand), Point(80, 80), fontFace, 2.0f, Scalar(255, 255, 255));
        vector <Point> p = hg->getFingerTips(src);
        //ve cac diem dau ngon tay
        sh->drawFingerTips(src, sh, idxSh, p);
        //ve duong convex hull
        //drawContours(src, sh->hullPoint, idxSh, cv::Scalar(200, 0, 0), 2, 8, vector<Vec4i>(), 0, Point());
        //ve duong bao
        //drawContours(src, sh->contourShape, idxSh, cv::Scalar(0, 200, 0), 2, 8, vector<Vec4i>(), 0, Point());
        //ve o vuong bao tay
        rectangle(src, bRectSh.tl(), bRectSh.br(), Scalar(0, 0, 200));
    }else{
        ISHAND = false;
    }
}

void Player::makeContours(Mat src, Mat bw, Shape * sh, HandGesture *hg1, Rect boxCheckHand){
    Mat aBw;
    double currentArea;
    vector<Vec4i> hierarchy;
    //tao 1 ban sao cua anh nhi phan la aBw
    bw.copyTo(aBw);
    GaussianBlur(aBw, aBw, Size(11, 11), 3.5, 3.5);
    threshold(aBw, aBw, threshold_bar_static, 255, THRESH_BINARY);
    cv::erode(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    cv::dilate(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    cv::dilate(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    cv::erode(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

    //hàm định biên
    findContours(aBw, sh->contourShape, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    int *a;
    a = new int(sizeof(int));
    a = findBiggestContour(sh->contourShape);
    sh->initVectors();
    sh->cIdxShape = *a;//tim duong vien lon nhat co the y la ban tay

    Mat imgClone;
    src.copyTo(imgClone);

    if (sh->cIdxShape != -1){
        //lấy diện tích của đường định biên
        currentArea = contourArea(sh->contourShape[sh->cIdxShape]);
        if (currentArea > 2000){ //2500
            analyContour(src, sh, sh->cIdxShape, hg1,boxCheckHand);
        }
        else{
            hg1->mostFrequentFingerNumber = 0;
        }
    }
}
void Player::showWindows(Mat src, Mat bw){
    pyrDown(bw, bw);
    pyrDown(bw, bw);
    Rect roi(Point(3 * src.cols / 4, 0), bw.size());
    vector<Mat> channels;
    Mat result;
    for (int i = 0; i < 3; i++)
        channels.push_back(bw);
    merge(channels, result);
    result.copyTo(src(roi));
    imShow(src);
}

int Player::normWindowX(Point center){
    int tam = center.x;
    if (tam < 80){
        return 1;
    }
    if (tam < 160 && tam >= 80){
        if (tam < 200 && tam >= 120){
            return 5;
        }
        return 2;
    }
    if (tam < 240 && tam >= 160){
        if (tam < 200 && tam >= 120){
            return 5;
        }
        return 3;
    }
    if (tam >= 240){
        return 4;
    }
}
int Player::normWindowY(Point center){
    int tam = center.y;
    if (tam < 120){
        if (tam >90){
            return 3;
        }
        return 1;
    }
    else{
        if (tam < 150){
            return 3;
        }
        return 2;
    }
}
Mat Player::returnSubBackgroundStatic(Mat frameCurrent, Mat framePrev,Rect box){

    cv::Mat diffImage;
    Mat anhGrab;
    cv::absdiff(framePrev, frameCurrent, diffImage);
    Rect newBox;
    newBox = box;
    cv::Mat foregroundMask = cv::Mat::zeros(frameCurrent.rows, frameCurrent.cols, CV_8UC1);

    float threshold1 = 30.0f;
    float dist;
    Point center;
    center.x = (box.br().x + box.tl().x) / 2;
    center.y = (box.br().y + box.tl().y) / 2;

    int kq1 = normWindowX(center);
    int kq2 = normWindowY(center);
    int start_x = 0;
    int end_x = 0;
    int start_y = 0;
    int end_y = 0;
    switch (kq1){
    case 1: start_x = 0; end_x = 159; break;
    case 2: start_x = 0; end_x = 199; break;
    case 5: start_x = 80; end_x = 239; break;
    case 3: start_x = 120; end_x = 319; break;
    case 4: start_x = 160; end_x = 319; break;
    }
    switch (kq2){
    case 1: start_y = 0; end_y = 179; break;
    case 3: start_y = 30; end_y = 209; break;
    case 2: start_y = 60; end_y = 239; break;
    }

    for (int j = start_y; j < end_y; ++j)
    for (int i = start_x; i < end_x; ++i)
    {
        cv::Vec3b pix = diffImage.at<cv::Vec3b>(j, i);

        dist = (pix[0] * pix[0] + pix[1] * pix[1] + pix[2] * pix[2]);
        dist = sqrt(dist);

        if (dist> threshold1)
        {
            foregroundMask.at<unsigned char>(j, i) = 255;
        }
    }
    //cv::threshold(diffImage, foregroundMask, 30, 255.0, CV_THRESH_BINARY);
    //adaptiveThreshold(foregroundMask, foregroundMask, 255,/* ADAPTIVE_THRESH_MEAN_C*/ ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 15, 0);
    GaussianBlur(foregroundMask, foregroundMask, Size(11, 11), 3.5, 3.5, 4);
    threshold(foregroundMask, foregroundMask, threshold_bar_static, 255, THRESH_BINARY);
    cv::erode(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    cv::dilate(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    cv::dilate(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    cv::erode(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
    frameCurrent.copyTo(anhGrab, foregroundMask);
    return anhGrab;
}
Mat Player::canBangHistogram(Mat &imageSrc){
    Mat imageHsv, imageDst;

    cvtColor(imageSrc, imageHsv, CV_BGR2HSV);

    vector<Mat> hsvChannels;
    // Tách imageHsv thành 3 kênh màu
    split(imageHsv, hsvChannels);

    // Cân bằng histogram kênh màu v (Value)
    equalizeHist(hsvChannels[2], hsvChannels[2]);

    // Trộn ảnh
    merge(hsvChannels, imageHsv);

    // Chuyển đổi HSV sang RGB để hiển thị
    cvtColor(imageHsv, imageDst, CV_HSV2BGR);

    return imageDst;
}
void Player::drawHist(String name, Mat src){

    /// Separate the image in 3 places ( B, G and R )
    vector<Mat> bgr_planes;
    Mat src1;
    src.copyTo(src1);
    split(src1, bgr_planes);

    /// Establish the number of bins
    int histSize = 256;

    /// Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 };
    const float* histRange = { range };

    bool uniform = true; bool accumulate = false;

    Mat b_hist, g_hist, r_hist;

    /// Compute the histograms:
    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

    // Draw the histograms for B, G and R
    int hist_w = 320; int hist_h = 240;
    int bin_w = cvRound((double)hist_w / histSize);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    /// Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    /// Draw for each channel
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
            Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
            Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
            Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
            Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }
    hisShow(histImage);
}
float Player::returnPercentDiff(Mat src_base, Mat src_test1){
    float per = 0;
    Mat hsv_base, hsv_test1;

    /// Convert to HSV
    cvtColor(src_base, hsv_base, COLOR_BGR2HSV);
    cvtColor(src_test1, hsv_test1, COLOR_BGR2HSV);

    /// Using 50 bins for hue and 60 for saturation
    int h_bins = 50; int s_bins = 60;
    int histSize[] = { h_bins, s_bins };

    // hue varies from 0 to 179, saturation from 0 to 255
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };

    const float* ranges[] = { h_ranges, s_ranges };

    // Use the o-th and 1-st channels
    int channels[] = { 0, 1 };

    /// Histograms
    Mat hist_base;
    Mat hist_test1;
    /// Calculate the histograms for the HSV images
    calcHist(&hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false);
    normalize(hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat());

    calcHist(&hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
    normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat());

    /// Apply the histogram comparison methods
    per = compareHist(hist_base, hist_test1, 0);
    return per;
}

#ifdef __linux__
#else
void Player::SetArrowLeft(BOOL bState)
{
    BYTE keyState[256];

    GetKeyboardState((LPBYTE)&keyState);
    if ((bState && !(keyState[VK_LEFT] & 1)) ||
        (!bState && (keyState[VK_LEFT] & 1)))
    {
        // Simulate a key press
        keybd_event(VK_LEFT,
            0x45,
            KEYEVENTF_EXTENDEDKEY | 0,
            0);

        // Simulate a key release
        keybd_event(VK_LEFT,
            0x45,
            KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
            0);
    }
}

void Player::SetArrowRight(BOOL bState)
{
    BYTE keyState[256];

    GetKeyboardState((LPBYTE)&keyState);
    if ((bState && !(keyState[VK_RIGHT] & 1)) ||
        (!bState && (keyState[VK_RIGHT] & 1)))
    {
        // Simulate a key press
        keybd_event(VK_RIGHT,
            0x45,
            KEYEVENTF_EXTENDEDKEY | 0,
            0);

        // Simulate a key release
        keybd_event(VK_RIGHT,
            0x45,
            KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
            0);
    }
}
// Positive dx value means move right, Negative dx value means move left
// Positive dy value means move down, Negative dy value means move right
void Player::MouseMove(int dx, int dy)
{
    INPUT  Input = { 0 };
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_MOVE; //|MOUSEEVENTF_ABSOLUTE;
    Input.mi.dx = dx;
    Input.mi.dy = dy;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void Player::MouseLeftBtnDown()
{
    INPUT    Input = { 0 };
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void Player::MouseLeftBtnUp()
{
    INPUT    Input = { 0 };
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void Player::MouseRightBtnDown()
{
    INPUT    Input = { 0 };
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void Player::MouseRightBtnUp()
{
    INPUT Input = { 0 };
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
}

void Player::controlCursor(int &flagC, int & flagLC, int xx, int yy, int xcu, int ycu, HandGesture hg1){
    //move
    if (hg1.isHand && hg1.mostFrequentFingerNumber == 1){
        int dx = xx - xcu;
        int dy = yy - ycu;
        if (!(abs(dx) <= 3 && abs(dy) <= 3))
            MouseMove(3 * dx, 3 * dy);
        //reset flag click
        flagC = 0;
    }

    //press down mouse
    if (hg1.mostFrequentFingerNumber == 2 && hg1.isHand){
        //reset flag longclick
        Sleep(50);
        MouseLeftBtnUp();
        flagLC = 0;
    }

    //rightclick
    if (hg1.mostFrequentFingerNumber == 4 && hg1.isHand && flagC == 0){
        flagC = 1;
        MouseRightBtnDown();
        cout << "click right mouse " << endl;
        Sleep(50);
        MouseRightBtnUp();
    }

    //leftclick
    if (hg1.mostFrequentFingerNumber == 3 && hg1.isHand && flagC == 0){
        flagC = 1; // them co de xac dinh la muon click thi phai tro ve 1 moi click dc
        MouseLeftBtnDown();
        cout << "click left mouse " << endl;
        Sleep(50);
        MouseLeftBtnUp();
    }

    //longclick
    if (hg1.mostFrequentFingerNumber == 5 && hg1.isHand && flagLC == 0){
        MouseLeftBtnDown();
        cout << "long click left mouse " << endl;
        flagLC = 1;
    }

}
#endif

double Player::getOrientation(vector<Point> &contours, Mat &img)
{
    //Construct a buffer used by the pca analysis
    Mat data_pts = Mat(contours.size(), 2, CV_64FC1);
    for (int i = 0; i < data_pts.rows; ++i)
    {
        data_pts.at<double>(i, 0) = contours[i].x;
        data_pts.at<double>(i, 1) = contours[i].y;
    }
    //Perform PCA analysis
    PCA pca_analysis(data_pts, Mat(), CV_PCA_DATA_AS_ROW);

    //biến lưu giá trị riêng và vector riêng
    //Store the eigenvalues and eigenvectors
    vector<Point2d> eigen_vecs(2);
    vector<double> eigen_val(2);
    for (int i = 0; i < 2; ++i)
    {
        eigen_vecs[i] = Point2d(pca_analysis.eigenvectors.at<double>(i, 0),pca_analysis.eigenvectors.at<double>(i, 1));
        eigen_val[i] = pca_analysis.eigenvalues.at<double>(i, 0);
    }
    //Store the position of the object
    Point pos = Point(pca_analysis.mean.at<double>(0, 0),pca_analysis.mean.at<double>(0, 1));
    //Draw the principal components
//    circle(img, pos, 3, CV_RGB(255, 0, 255), 2);
//    line(img, pos, pos + 0.02 * Point(eigen_vecs[0].x * eigen_val[0], eigen_vecs[0].y * eigen_val[0]), CV_RGB(255, 255, 0));
//    line(img, pos, pos + 0.02 * Point(eigen_vecs[1].x * eigen_val[1], eigen_vecs[1].y * eigen_val[1]), CV_RGB(0, 255, 255));
    //cout << "goc " << atan2(eigen_vecs[0].y, eigen_vecs[0].x) << endl;
    return atan2(eigen_vecs[0].y, eigen_vecs[0].x);
}
#ifdef __linux__
void Player::sig_handler(int signo){
    if (signo == SIGINT){
        cout << "Quit program clear GPIO" << endl;
        digitalWrite(LED1, 0);
        digitalWrite(LED2, 0);
        digitalWrite(LED3, 0);
        digitalWrite(LED4, 0);
        digitalWrite(LED5, 0);
        digitalWrite(LED_NO, 0);

        pinMode(LED1, INPUT);
        pinMode(LED2, INPUT);
        pinMode(LED3, INPUT);
        pinMode(LED4, INPUT);
        pinMode(LED5, INPUT);
        pinMode(LED_NO, INPUT);
    }
}

void Player::error(const char *msg)
{
    perror(msg);
    exit(0);
}
#endif
//___________________________________________________
void Player::run()
{
#ifdef __linux__
        system("sudo modprobe bcm2835-v4l2");
        wiringPiSetupGpio();
        pinMode(LED1, OUTPUT);
        pinMode(LED2, OUTPUT);
        pinMode(LED3, OUTPUT);
        pinMode(LED4, OUTPUT);
        pinMode(LED5, OUTPUT);
        pinMode(LED_NO, OUTPUT);

//        if (signal(SIGINT, sig_handler) == SIG_ERR){
//            cout << "Not clear GPIO" << endl;
//        }

        int sockfd;
        sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        struct sockaddr_in serv;
        serv.sin_family = AF_INET;
        serv.sin_port = htons(2222);
        serv.sin_addr.s_addr = inet_addr(ipComputer);
        socklen_t m_server = sizeof(serv);
        struct PointCenter pointCenter;
#endif

    while(!stop){
       cout<<"ip connect "<<ipComputer<<endl;
       MyImage m;
       if(flagVideo){
           m.setCam(fileName);
       }else{
           m.setCam(0);
       }
        while(1){
            resetProcess = 0;
            square_len = 15;
            Shape sh;
            HandGesture hg1;
            m.cap >> m.src;

            if(flagVideo){
                WaitKeyOS(30);
            }

            Mat framePrev;
            framePrev = returnImagePrev(m.cap);
            bgShow(framePrev);
            resetProcess = 1;
            waitStartProgress(m);
            flagOn = 0;
            if(flagClose) break;
            m.cap >> m.src;

            if(flagVideo){
                WaitKeyOS(30);
            }

            waitForPalmCover(&m);
            average(&m);
            float per;
            namedWindow("trackb_n", CV_WINDOW_KEEPRATIO);
            inittrackbar();
            int xcu, ycu, xx, yy;
            xcu = ycu = xx = yy = 0;
            int flagC = 1;
            int flagLC = 1;
            int flagC1 = 1;
            int flagLC1 = 1;
            int pressArrowKeyLeft = 0;
            int pressArrowKeyRight = 0;

            ////////////////////////////////////////////////
            Rect trackWindow;
            int hsize = 16;
            float hranges[] = { 0, 180 };
            const float* phranges = hranges;
            Mat hue, hist;
            bool flagCam = true;
            mySelection &= Rect(0, 0, 320, 240);
            ////////////////////////////////////////////////
            int fr_count = 0;
            time_t t_start;
            time_t t_stop;
            time(&t_start);
            Rect boxCheckHand(0,0,0,0);
            flagVideo = false;
            while(1){
                resetProcess = -1;
                hg1.frameNumber++;
    //            waitKey(5);
                WaitKeyOS(time_wait);
                m.cap >> m.src;
                if (m.src.empty()){
                    flagVideo = false;
                    flagClose = true;
                    videoStop(true);
                    break;
                }
                convertCamera(m.src);
                m.src.copyTo(m.srcLR);

                if (flag2){
                    m.srcLR = canBangHistogram(m.srcLR);
                    imshow("CanBangHistogram", m.srcLR);
                }
                else{
                    cvDestroyWindow("CanBangHistogram");
                }

                if (flag3){
                    drawHist("Histogram", m.srcLR);
                }
                if (flag0){
                    m.srcLR = returnSubBackgroundStatic(m.src, framePrev, boxCheckHand);
                }

                if (flag1){
                    framePrev = returnImagePrev(m.cap);
                    bgShow(framePrev);
                    flag1 = !flag1;
                }

                if (flag4){
                    per = returnPercentDiff(framePrev, m.src);
                    per = per * 100;
//                    if (per < 30.0f){
//                        framePrev = returnImagePrev(m.cap);
//                    }
                }
                pyrDown(m.srcLR, m.srcLR);
                blur(m.srcLR, m.srcLR, Size(3, 3));
                cvtColor(m.srcLR, m.srcLR, ORIGCOL2COL);
                produceBinaries(&m);
                pyrUp(m.bw, m.bw);
                pyrUp(m.srcLR, m.srcLR);
                boxCheckHand=camShiftDemo(m.src, m.srcLR, m.bw, hue, hist, phranges, hsize, trackWindow, flagCam);
                cvtColor(m.srcLR, m.srcLR, COL2ORIGCOL);
                makeContours(m.src, m.bw, &sh, &hg1,boxCheckHand);
    #ifdef __linux__
                pointCenter.arrowKeyLeft = false;
                pointCenter.arrowKeyRight = false;
                pointCenter.x = -1;
                pointCenter.y = -1;
                pointCenter.fingerNum = -1;
    #endif
                if (flag5){
    #ifdef __linux__
                    pointCenter.x = hg1.getPointCenter().x;
                    pointCenter.y = hg1.getPointCenter().y;
                    pointCenter.fingerNum = hg1.mostFrequentFingerNumber;
    #else
                    xx = hg1.getPointCenter().x;
                    yy = hg1.getPointCenter().y;
                    controlCursor(flagC, flagLC, xx, yy, xcu, ycu, hg1);

                    ///////////////////////////////////////////////////////////////////////
                    if (hg1.isHand && hg1.mostFrequentFingerNumber == 1){
                        int dx = xx - xcu;
                        int dy = yy - ycu;
                        if (!(abs(dx) <= 3 && abs(dy) <= 3)){
                            mouseCtrlShow(1);
                        }
                        flagC1 = 0;
                    }
                    //rightclick
                    if (hg1.mostFrequentFingerNumber == 4 && hg1.isHand && flagC1 == 0){
                        mouseCtrlShow(4);
                        flagC1 = 1;
                    }

                    //leftclick
                    if (hg1.mostFrequentFingerNumber == 3 && hg1.isHand && flagC1 == 0){
                        mouseCtrlShow(3);
                        flagC1 = 1; // them co de xac dinh la muon click thi phai tro ve 1 moi click dc
                    }

                    //longclick
                    if (hg1.mostFrequentFingerNumber == 5 && hg1.isHand && flagLC1 == 0){
                        mouseCtrlShow(5);
                        flagLC1 = 1;
                    }

                    xcu = xx;
                    ycu = yy;
    #endif

                    cv::Mat mouseImg(240, 320, CV_8UC3, Scalar(0, 0, 0));
                    cv::circle(mouseImg,hg1.getPointCenter(), 8, Scalar(0, 200, 0), 4);
                    mouseShow(mouseImg);
                }
                if (flag6 && ISHAND){
                    double rl = getOrientation(hg1.contours, m.src);
                    if (rl < 1.1){
    //                    putText(m.src, "<--", Point(250, 220), FONT_HERSHEY_PLAIN, 1.5f, Scalar(41, 0, 223), 2);
                        pressArrowKeyLeft++;
                        pressArrowKeyRight = 0;
                        if (pressArrowKeyLeft == 15){
    #ifdef __linux__
                            pointCenter.arrowKeyLeft = true;
    #else
                            SetArrowLeft(true);
                            SetArrowLeft(false);
    #endif
                            pressArrowKeyLeft = 0;
                            handShow(-1);
                        }

                    }
                    if (rl > 1.9){
    //                    putText(m.src, "-->", Point(250, 220), FONT_HERSHEY_PLAIN, 1.5f, Scalar(41, 0, 223), 2);
                        pressArrowKeyRight++;
                        pressArrowKeyLeft = 0;
                        if (pressArrowKeyRight == 15){
    #ifdef __linux__
                            pointCenter.arrowKeyRight = true;
    #else
                            SetArrowRight(true);
                            SetArrowRight(false);
    #endif
                            pressArrowKeyRight = 0;
                            handShow(1);
                        }
                    }
                    if(rl<=1.9 && rl>=1.1){
                        handShow(0);
                    }
                }

    #ifdef __linux__

                if (flag5 || flag6){
                    sendto(sockfd, (char*)&pointCenter, sizeof(pointCenter), 0, (struct sockaddr *)&serv, m_server);
                }
                memset(&pointCenter, 0, sizeof(pointCenter));
    #endif
                numShow(hg1.mostFrequentFingerNumber);
                showWindows(m.src, m.bw);
                if(flagClose){
                    break;
                }
                if(flagReset){
                    break;
                }
//#ifdef __linux__
//                fr_count = m.cap.get(CV_CAP_PROP_FPS);
//                percentShow(per,fr_count);
//#else
                fr_count++;
                time(&t_stop);
                if ((t_stop - t_start) == 1){
                    time(&t_start);
                    percentShow(per,fr_count);
                    fr_count = 0;
                }
//#endif

            }//while process
            for (int i = 0; i < NSAMPLES; i++){
                c_lower[i][0] = 20;
                c_upper[i][0] = 40;
                c_lower[i][1] = 30;
                c_upper[i][1] = 255;
                c_lower[i][2] = 15;
                c_upper[i][2] = 255;
                avgColor[i][0] = 0;
                avgColor[i][1] = 0;
                avgColor[i][2] = 0;
            }

#ifdef __linux__
            cout << "program finished clear GPIO" << endl;
            digitalWrite(LED1, 0);
            digitalWrite(LED2, 0);
            digitalWrite(LED3, 0);
            digitalWrite(LED4, 0);
            digitalWrite(LED5, 0);
            digitalWrite(LED_NO, 0);

            pinMode(LED1, INPUT);
            pinMode(LED2, INPUT);
            pinMode(LED3, INPUT);
            pinMode(LED4, INPUT);
            pinMode(LED5, INPUT);
            pinMode(LED_NO, INPUT);
#endif
            roi.clear();
            cout << "reset" << endl;
            destroyAllWindows();
            if(flagClose)
                break;

        }//while reset
        m.cap.release();
        flagClose = false;
    }// while run
}
