﻿//#include "main.hpp"
//int flagReset = 0;
//int threshold1 = 30;
////hàm sử lí sự kiện khi t nhấp chuột vào start
//void CallBackFuncReset(int event, int x, int y, int flags, void* userdata)
//{
//	MyImage* m = (MyImage*)userdata;
//	Point p;
//	if (event == EVENT_LBUTTONDOWN)
//	{
//		p.x = x;
//		p.y = y;
//		if (p.x <= (m->src.cols) && p.x >= (m->src.cols - 40))
//		{
//			if (p.y <= (m->src.rows) && p.y >= (m->src.rows-40)){
//				flagReset = 1;
//			}
//		}
//		else{
//			cout << "chua nhap dung cho reset" << endl;
//		}
//	}
//}
//
//void canBangHistogram(Mat &imageSrc){
//	Mat imageHsv, imageDst;
//
//	cvtColor(imageSrc, imageHsv, CV_BGR2HSV);
//
//	vector<Mat> hsvChannels;
//	// Tách imageHsv thành 3 kênh màu
//	split(imageHsv, hsvChannels);
//
//	// Cân bằng histogram kênh màu v (Value)
//	equalizeHist(hsvChannels[2], hsvChannels[2]);
//
//	// Trộn ảnh
//	merge(hsvChannels, imageHsv);
//
//	// Chuyển đổi HSV sang RGB để hiển thị
//	cvtColor(imageHsv, imageDst, CV_HSV2BGR);
//}
//
//
//int main(int argc, char *argv[]){
//
//RESET:
//	//định nghĩa I/O cho các GPIO của Raspberry
//#ifdef __linux__
//	progressLinux(argc, argv);
//#else
//	progressWindows();
//#endif
//	return 0;
//}
//
//void waitForPalmCover(MyImage *m){
//
//	m->cap >> m->src; // truyen anh tu camera vao;
//
//#ifdef __linux__
//	flip(m->src, m->src, 0); // sử dụng để lật hình với trục y(1)
//#else
//	flip(m->src, m->src, 1); // sử dụng để lật hình với trục y(1)
//#endif
//
//	//Vẽ 7 khung ảnh nhỏ ddeeer nhận mẫu
//	roi.push_back(MyRoi(Point(m->src.cols / 3 - 40, m->src.rows / 6), Point(m->src.cols / 3 - 40 + square_len, m->src.rows / 6 + square_len), m->src));
//	roi.push_back(MyRoi(Point(m->src.cols / 4 - 40, m->src.rows / 2), Point(m->src.cols / 4 - 40 + square_len, m->src.rows / 2 + square_len), m->src));
//	roi.push_back(MyRoi(Point(m->src.cols / 3 - 40, m->src.rows / 1.5), Point(m->src.cols / 3 - 40 + square_len, m->src.rows / 1.5 + square_len), m->src));
//	roi.push_back(MyRoi(Point(m->src.cols / 2 - 40, m->src.rows / 2), Point(m->src.cols / 2 - 40 + square_len, m->src.rows / 2 + square_len), m->src));
//	roi.push_back(MyRoi(Point(m->src.cols / 2.5 - 40, m->src.rows / 2.5), Point(m->src.cols / 2.5 - 40 + square_len, m->src.rows / 2.5 + square_len), m->src));
//	roi.push_back(MyRoi(Point(m->src.cols / 2 - 40, m->src.rows / 1.5), Point(m->src.cols / 2 - 40 + square_len, m->src.rows / 1.5 + square_len), m->src));
//	roi.push_back(MyRoi(Point(m->src.cols / 2.5 - 40, m->src.rows / 1.8), Point(m->src.cols / 2.5 - 40 + square_len, m->src.rows / 1.8 + square_len), m->src));
//
//	for (int i = 0; i < 30; i++){
//		m->cap >> m->src;
//
//#ifdef __linux__
//		flip(m->src, m->src, 0);
//#else
//		flip(m->src, m->src, 1);
//#endif
//
//		for (int j = 0; j < NSAMPLES; j++){
//			roi[j].drawRect(m->src);
//		}
//		//hiển thị thông tin
//		string imgText = string("Cover rectangles with palm");
//		printText(m->src, imgText);
//		imshow("WaitPalm", m->src);
//		if (cv::waitKey(30) >= 0) break;
//	}
//}
//
//int getMedian(vector<int> val){
//	int median;
//	size_t size = val.size();
//	sort(val.begin(), val.end());
//	if (size % 2 == 0)  {
//		median = val[size / 2 - 1];
//	}
//	else{
//		median = val[size / 2];
//	}
//	return median;
//}
//
////laấy ra giá trị trung bình của HLS
//void getAvgColor(MyRoi roi, int avg[3]){
//	Mat r;
//	roi.roiPtr.copyTo(r); //copy 1 ROI vao r
//	vector<int> hm;
//	vector<int> sm;
//	vector<int> lm;
//	//// generate vectors
//	//// truyền lần lượt các giá trị của H L S vào 
//	//for (int i = 2; i < r.rows - 2; i++){
//	//	for (int j = 2; j < r.cols - 2; j++){
//	//		hm.push_back(r.data[r.channels()*(r.cols*i + j) + 0]);
//	//		sm.push_back(r.data[r.channels()*(r.cols*i + j) + 1]);
//	//		lm.push_back(r.data[r.channels()*(r.cols*i + j) + 2]);
//	//	}
//	//}
//	for (int i = 0; i < r.rows; i++){
//		for (int j = 0; j < r.cols; j++){
//			Vec3b hsv = r.at<Vec3b>(i, j);
//			hm.push_back(hsv.val[0]);
//			sm.push_back(hsv.val[1]);
//			lm.push_back(hsv.val[2]);
//		}
//	}
//	//int H = hsv.val[0]; //hue
//	//int S = hsv.val[1]; //saturation
//	//int V = hsv.val[2]; //value
//
//	avg[0] = getMedian(hm);
//	avg[1] = getMedian(sm);
//	avg[2] = getMedian(lm);
//}
//
//// tính toán ra giá trị H L S của 7 ô đc lưu trong avgColor
//// khi tính toán xong 7 ô sẽ chuyển sang màu trắng
//void average(MyImage *m){
//	m->cap >> m->src;
//
//#ifdef __linux__
//	flip(m->src, m->src, 0);
//#else
//	flip(m->src, m->src, 1);
//#endif
//
//	for (int i = 0; i < 10; i++){
//		m->cap >> m->src;
//
//#ifdef __linux__
//		flip(m->src, m->src, 0);
//#else
//		flip(m->src, m->src, 1);
//#endif
//
//		cvtColor(m->src, m->src, ORIGCOL2COL);// chuyển từ RGB sang HLS để tách ra tham số HLS // cho doi mau cua o tu xanh la thanh trang
//		for (int j = 0; j < NSAMPLES; j++){
//			getAvgColor(roi[j], avgColor[j]); //avgColor[NSAMPLES][3]
//			roi[j].drawRect(m->src);
//		}
//		cvtColor(m->src, m->src, COL2ORIGCOL);
//		string imgText = string("Finding average color of hand");
//		printText(m->src, imgText);
//		imshow("WaitPalm", m->src);
//		if (cv::waitKey(30) >= 0) break;
//	}
//}
//
//void initWindows(){
//	namedWindow("trackbar", CV_WINDOW_AUTOSIZE);
//}
//
//void inittrackbar(){
//
//	//các tham số cơ bản của màu da tay
//	for (int i = 0; i < NSAMPLES; i++){
//		c_lower[i][0] = 11;
//		c_upper[i][0] = 12;
//		c_lower[i][1] = 30;
//		c_upper[i][1] = 255;
//		c_lower[i][2] = 15;
//		c_upper[i][2] = 255;
//	}
//	threshold_bar = 150;
//	createTrackbar("H-Upper", "trackbar", &c_upper[0][0], 180);
//	createTrackbar("H-Lower", "trackbar", &c_lower[0][0], 180);
//	createTrackbar("S-Upper", "trackbar", &c_upper[0][1], 255);
//	createTrackbar("S-Lower", "trackbar", &c_lower[0][1], 255);
//	createTrackbar("L-Upper", "trackbar", &c_upper[0][2], 255);
//	createTrackbar("L-Lower", "trackbar", &c_lower[0][2], 255);
//	createTrackbar("Threshsold", "trackbar", &threshold_bar, 255);
//	createTrackbar("Threshsold1", "trackbar", &threshold1, 255);
//
//}
//
////tiêu chuẩn màu sắc
//void normalizeColors(){
//	// copy all boundaries read from trackbar
//	// to all of the different boundaries
//	for (int i = 1; i < NSAMPLES; i++){ // tại vì các giá trị vào được để trong 0
//		for (int j = 0; j < 3; j++){
//			c_lower[i][j] = c_lower[0][j];
//			c_upper[i][j] = c_upper[0][j];
//		}
//	}
//	// normalize all boundaries so that 
//	// threshold is within 0-255
//	for (int i = 0; i < NSAMPLES; i++){
//		//lower: avgColor - c_lower < 0		thì sẽ bằng 0
//		if ((avgColor[i][0] - c_lower[i][0]) < 0){
//			c_lower[i][0] = avgColor[i][0];
//		}
//		if ((avgColor[i][1] - c_lower[i][1]) < 0){
//			c_lower[i][1] = avgColor[i][1];
//		}
//		if ((avgColor[i][2] - c_lower[i][2]) <0){
//			c_lower[i][2] = avgColor[i][2];
//		}
//
//		//upper: avgColor + c_upper > 255	thì sẽ bằng 255
//		if ((avgColor[i][0] + c_upper[i][0]) >255){
//			c_upper[i][0] = 255 - avgColor[i][0];
//		}
//		if ((avgColor[i][1] + c_upper[i][1]) > 255){
//			c_upper[i][1] = 255 - avgColor[i][1];
//		}
//		if ((avgColor[i][2] + c_upper[i][2]) > 255){
//			c_upper[i][2] = 255 - avgColor[i][2];
//		}
//	}
//}
//
//void produceBinaries(MyImage *m){
//	Scalar lowerBound;
//	Scalar upperBound;
//	for (int i = 0; i < NSAMPLES; i++){
//
//		normalizeColors();
//
//		//avgColor - c_lower < 0	thì sẽ bằng 0
//		//avgColor + c_upper > 255	thì sẽ bằng 255
//		// còn lại nếu thỏa mãn thì lấy giá trị
//		lowerBound = Scalar(avgColor[i][0] - c_lower[i][0], avgColor[i][1] - c_lower[i][1], avgColor[i][2] - c_lower[i][2]);
//		upperBound = Scalar(avgColor[i][0] + c_upper[i][0], avgColor[i][1] + c_upper[i][1], avgColor[i][2] + c_upper[i][2]);
//
//		//chứa các ảnh nhị phân có kích thước bẳng 1 nửa thôi
//		m->bwList.push_back(Mat(m->srcLR.rows, m->srcLR.cols, CV_8U));
//
//		//tách ra màu cần thiết dựa vào giá trị của trackbar
//		inRange(m->srcLR, lowerBound, upperBound, m->bwList[i]);
//	}
//
//	//m->bw là tổng của tất cả các bwList
//	m->bwList[0].copyTo(m->bw);
//	for (int i = 1; i < NSAMPLES; i++){
//		m->bw += m->bwList[i];
//	}
//	medianBlur(m->bw, m->bw, NSAMPLES); // làm mờ để lọc nhiễu
//}
//
//// tim 2 đường viền lớn nhất
//int* findBiggestContour(vector<vector<Point> > contours){
//	static int index[2];
//	int indexOfBiggestContour = -1;
//	int indexOfBiggerContour = -1;
//	int sizeOfBiggestContour = 0;
//	int sizeOfBiggerContour = 0;
//
//	for (int i = 0; i < contours.size(); i++){
//		if (contours[i].size() > sizeOfBiggestContour){
//			sizeOfBiggestContour = contours[i].size();
//			indexOfBiggestContour = i;
//		}
//	}
//	//for (int i = 0; i < contours.size(); i++){
//	//	if (contours[i].size() > sizeOfBiggerContour){
//	//		if (i == indexOfBiggestContour){
//	//			continue;
//	//		}
//	//		else{
//	//			sizeOfBiggerContour = contours[i].size();
//	//			indexOfBiggerContour = i;
//	//		}
//	//	}
//	//}
//	index[0] = indexOfBiggestContour;
//	//index[1] = indexOfBiggerContour;
//	return index;
//}
//
//void analyContour(MyImage *m, Shape *sh, int idxSh, int &fr, HandGesture *hg){
//	Rect bRectSh = boundingRect(Mat(sh->contourShape[idxSh]));
//
//	// Find the convex hull object for each contour
//	//Tìm phần vỏ lồi của một điểm đặt.
//	//tìm tập hợp hullPoint
//	convexHull(Mat(sh->contourShape[idxSh]), sh->hullPoint[idxSh], false, true);
//	//tìm tập hợp hullInt--được sử dụng để tìm convexityDefects
//	convexHull(Mat(sh->contourShape[idxSh]), sh->hullInt[idxSh], false, false);
//
//	//Hàm xấp xỉ 1 đa giác từ những đường cong , kín
//	approxPolyDP(Mat(sh->hullPoint[idxSh]), sh->hullPoint[idxSh], 18, true);
//
//	//tìm kiếm ra convexityDefects từ convexHull Int
//	if (sh->hullInt[idxSh].size() > 3){
//		//Bất kỳ độ lệch nào của vật thể từ conour này có thể được coi là khiếm khuyết lồi.
//		convexityDefects(sh->contourShape[idxSh], sh->hullInt[idxSh], sh->defectShape[idxSh]);
//	}
//	//thiết lập tham số cơ bản cho việc defect bàn tay
//	hg->setHandGesture(m, sh->contourShape[idxSh],
//		sh->hullInt[idxSh],
//		sh->hullPoint[idxSh],
//		sh->defectShape[idxSh],
//		bRectSh,
//		fr);
//
//	hg->eliminateDefects();
//
//	bool ishand = hg->detectIfHand(m);
//
//	if (ishand){
//		hg->getFingerNumber(m, fr);
//
//		//putText(m->src, bool2string(ishand), Point(80, 80), fontFace, 2.0f, Scalar(255, 255, 255));
//		vector <Point> p = hg->getFingerTips(m);
//		//ve cac diem dau ngon tay
//		sh->drawFingerTips(m, sh, idxSh, p);
//		//ve duong convex hull
//		drawContours(m->src, sh->hullPoint, idxSh, cv::Scalar(200, 0, 0), 2, 8, vector<Vec4i>(), 0, Point());
//		//ve duong bao
//		drawContours(m->src, sh->contourShape, idxSh, cv::Scalar(0, 200, 0), 2, 8, vector<Vec4i>(), 0, Point());
//		//ve o vuong bao tay
//		rectangle(m->src, bRectSh.tl(), bRectSh.br(), Scalar(0, 0, 200));
//	}
//}
//
//void makeContours(MyImage *m, Shape * sh, HandGesture *hg1, HandGesture *hg2){
//	Mat aBw;
//	double currentArea;
//	vector<Vec4i> hierarchy;
//
//	//zoom anh nhi phan co kich thuoc nhu ban dau
//	pyrUp(m->bw, m->bw);
//
//	//tao 1 ban sao cua anh nhi phan la aBw
//	m->bw.copyTo(aBw);
//
//	GaussianBlur(aBw, aBw, Size(11, 11), 3.5, 3.5);
//	threshold(aBw, aBw, threshold_bar, 255, THRESH_BINARY);
//
//	cv::erode(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//	cv::dilate(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//	cv::dilate(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//	cv::erode(aBw, aBw, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//
//	//hàm định biên
//	findContours(aBw, sh->contourShape, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	int *a;
//	a = new int(sizeof(int));
//	a = findBiggestContour(sh->contourShape);
//	if (*a == (-1)){
//		hg1->mostFrequentFingerNumber = 0;
//	}
//	sh->initVectors();
//	sh->cIdxShape = *a;//tim duong vien lon nhat co the y la ban tay
//
//	Mat imgClone;
//	m->src.copyTo(imgClone);
//
//	if (sh->cIdxShape != -1){
//		//lấy diện tích của đường định biên
//		currentArea = contourArea(sh->contourShape[sh->cIdxShape]);
//		if (currentArea > 2500){
//			analyContour(m, sh, sh->cIdxShape, sh->frNumber, hg1);
//		}
//	}
//
//	//sh->cIdxShape2 = *(a + 1); //ban tay thu 2
//	/*
//	if (sh->cIdxShape2 != -1){
//	currentArea = contourArea(sh->contourShape[sh->cIdxShape2]);
//	if (currentArea > 5000){
//	analyContour(m, sh, sh->cIdxShape2, sh->frNumber2, hg2);
//	}
//	}
//	*/
//}
//
//void showWindows(MyImage m){
//	pyrDown(m.bw, m.bw);
//	pyrDown(m.bw, m.bw);
//	Rect roi(Point(3 * m.src.cols / 4, 0), m.bw.size());
//	vector<Mat> channels;
//	Mat result;
//	for (int i = 0; i < 3; i++)
//		channels.push_back(m.bw);
//	merge(channels, result);
//	result.copyTo(m.src(roi));
//	
//	MyRoi roiReset(Point(m.src.cols - 40, m.src.rows - 40), Point(m.src.cols, m.src.rows), m.src);
//	roiReset.drawRect(m.src);
//	//putText(m.src, "START", Point(m.src.cols - 92, 70), fontFace, 1.5f, Scalar(200, 0, 0), 2);
//
//	imshow("HandDetect", m.src);
//}
//
//void printText(Mat src, string text){
//	int fontFace = FONT_HERSHEY_PLAIN;
//	putText(src, text, Point(src.cols / 2, src.rows / 10), fontFace, 1.2f, Scalar(200, 0, 0), 2);
//}
//
//#ifdef __linux__
//#else
//// Positive dx value means move right, Negative dx value means move left
//// Positive dy value means move down, Negative dy value means move right
//void MouseMove(int dx, int dy)
//{
//	INPUT  Input = { 0 };
//	Input.type = INPUT_MOUSE;
//	Input.mi.dwFlags = MOUSEEVENTF_MOVE; //|MOUSEEVENTF_ABSOLUTE;
//	Input.mi.dx = dx;
//	Input.mi.dy = dy;
//	::SendInput(1, &Input, sizeof(INPUT));
//}
//
//void MouseLeftBtnDown()
//{
//	INPUT    Input = { 0 };
//	Input.type = INPUT_MOUSE;
//	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
//	::SendInput(1, &Input, sizeof(INPUT));
//}
//
//void MouseLeftBtnUp()
//{
//	INPUT    Input = { 0 };
//	::ZeroMemory(&Input, sizeof(INPUT));
//	Input.type = INPUT_MOUSE;
//	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
//	::SendInput(1, &Input, sizeof(INPUT));
//}
//
//void MouseRightBtnDown()
//{
//	INPUT    Input = { 0 };
//	Input.type = INPUT_MOUSE;
//	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
//	::SendInput(1, &Input, sizeof(INPUT));
//}
//
//void MouseRightBtnUp()
//{
//	INPUT Input = { 0 };
//	::ZeroMemory(&Input, sizeof(INPUT));
//	Input.type = INPUT_MOUSE;
//	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
//	::SendInput(1, &Input, sizeof(INPUT));
//}
//#endif
//
////Hàm trả về tỉ lệ sai lệch giữa ảnh nền và ảnh hiện tại (tỉ lệ phần trăm càng cao độ sai lệch càng ít)
//float returnPercentDiff(Mat src_base, Mat src_test1){
//	float per = 0;
//	Mat hsv_base, hsv_test1;
//
//	/// Convert to HSV
//	cvtColor(src_base, hsv_base, COLOR_BGR2HSV);
//	cvtColor(src_test1, hsv_test1, COLOR_BGR2HSV);
//
//	/// Using 50 bins for hue and 60 for saturation
//	int h_bins = 50; int s_bins = 60;
//	int histSize[] = { h_bins, s_bins };
//
//	// hue varies from 0 to 179, saturation from 0 to 255
//	float h_ranges[] = { 0, 180 };
//	float s_ranges[] = { 0, 256 };
//
//	const float* ranges[] = { h_ranges, s_ranges };
//
//	// Use the o-th and 1-st channels
//	int channels[] = { 0, 1 };
//
//	/// Histograms
//	MatND hist_base;
//	MatND hist_test1;
//	/// Calculate the histograms for the HSV images
//	calcHist(&hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false);
//	normalize(hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat());
//
//	calcHist(&hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
//	normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat());
//
//	/// Apply the histogram comparison methods
//	per = compareHist(hist_base, hist_test1, 0);
//	return per;
//}
//
////tạo hàm bắt sự kiện khi nhấn Ctrl+C
//#ifdef __linux__
//void sig_handler(int signo){
//	if (signo == SIGINT){
//		cout << "Quit program clear GPIO" << endl;
//		digitalWrite(LED1, 0);
//		digitalWrite(LED2, 0);
//		digitalWrite(LED3, 0);
//		digitalWrite(LED4, 0);
//		digitalWrite(LED5, 0);
//		digitalWrite(LED_NO, 0);
//
//		pinMode(LED1, INPUT);
//		pinMode(LED2, INPUT);
//		pinMode(LED3, INPUT);
//		pinMode(LED4, INPUT);
//		pinMode(LED5, INPUT);
//		pinMode(LED_NO, INPUT);
//	}
//}
//
//void error(const char *msg)
//{
//	perror(msg);
//	exit(0);
//}
//#endif
//
////hàm đổi bool thành string
//string bool2string(bool tf){
//	if (tf)
//		return "true";
//	else
//		return "false";
//}
//
////hàm sử lí sự kiện khi t nhấp chuột vào start
//void CallBackFunc(int event, int x, int y, int flags, void* userdata)
//{
//	MyImage* m = (MyImage*)userdata;
//	Point p;
//	if (event == EVENT_LBUTTONDOWN)
//	{
//		p.x = x;
//		p.y = y;
//		int gioihan;
//
//#ifdef __linux__
//		gioihan = 80;
//#else
//		gioihan = 120;
//#endif
//
//		if (p.x <= (m->src.cols) && p.x >= (m->src.cols - gioihan))
//		{
//			if (p.y <= (gioihan) && p.y >= (0)){
//				flagOn = 1;
//				rectangle(m->src, Point(m->src.cols - gioihan, 0), Point(m->src.cols, gioihan), Scalar(249, 244, 0), CV_FILLED);
//#ifdef __linux__
//				putText(m->src, "START", Point(m->src.cols - 70, 50), fontFace, 1.2f, Scalar(255, 255, 255), 2);
//#else
//				putText(m->src, "START", Point(m->src.cols - 92, 70), fontFace, 1.5f, Scalar(255, 255, 255), 2);
//#endif
//				imshow("Wait", m->src);
//
//				waitKey(350);
//				destroyWindow("Wait");
//
//			}
//		}
//		else{
//			cout << "not start" << endl;
//		}
//	}
//}
//Mat returnImage(Mat frameCurrent, Mat framePrev){
//
//	cv::Mat diffImage;
//	Mat anhGrab;
//	cv::absdiff(framePrev, frameCurrent, diffImage);
//
//	cv::Mat foregroundMask = cv::Mat::zeros(frameCurrent.rows, frameCurrent.cols, CV_8UC1);
//
//	threshold1 = 30.0f;
//	float dist;
//
//	for (int j = 0; j < diffImage.rows; ++j)
//	for (int i = 0; i<diffImage.cols; ++i)
//	{
//		cv::Vec3b pix = diffImage.at<cv::Vec3b>(j, i);
//
//		dist = (pix[0] * pix[0] + pix[1] * pix[1] + pix[2] * pix[2]);
//		dist = sqrt(dist);
//
//		if (dist>(float)threshold1)
//		{
//			foregroundMask.at<unsigned char>(j, i) = 255;
//		}
//	}
//
//	//adaptiveThreshold(foregroundMask, foregroundMask, 255,/* ADAPTIVE_THRESH_MEAN_C*/ ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 15, 0);
//	GaussianBlur(foregroundMask, foregroundMask, Size(11, 11), 3.5, 3.5);
//	threshold(foregroundMask, foregroundMask, threshold_bar, 255, THRESH_BINARY);
//	cv::erode(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//	cv::dilate(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//	cv::dilate(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//	cv::erode(foregroundMask, foregroundMask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//
//	frameCurrent.copyTo(anhGrab, foregroundMask);
//	imshow("anh grab", anhGrab);
//	return anhGrab;
//}
//
////hàm lấy ảnh nền
//Mat returnImagePrev(MyImage *m){
//	Mat framePrev;
//	for (int i = 0; i < 40; i++){
//		m->cap >> m->src;
//		flip(m->src, m->src, 1);
//		if (i <= 20){
//			putText(m->src, "Sample image", Point(m->src.cols / 5, m->src.rows / 2), fontFace, 1.5f, Scalar(41, 0, 223), 2);
//		}
//		else{
//			putText(m->src, "Sample image", Point(m->src.cols / 5, m->src.rows / 2), fontFace, 1.5f, Scalar(191, 178, 0), 2);
//		}
//		if (i == 20){
//			m->cap >> framePrev;
//			flip(framePrev, framePrev, 1);
//		}
//		imshow("Laymau", m->src);
//		if (cv::waitKey(30) == char('q')) break;
//	}
//	destroyAllWindows();
//	return framePrev;
//}
//
////Hàm chờ khi nhấn start để bắt đầu xu li
//void waitStartProgress(MyImage m){
//	while (flagOn != 1){
//		m.cap >> m.src;
//
//#ifdef __linux__
//		flip(m.src, m.src, 0);
//		MyRoi roiStart(Point(m.src.cols - 80, 0), Point(m.src.cols, 80), m.src);
//		vector <MyRoi> roi7;
//		roiStart.drawRect(m.src);
//		putText(m.src, "START", Point(m.src.cols - 70, 50), fontFace, 1.2f, Scalar(200, 0, 0), 2);
//#else
//		flip(m.src, m.src, 1);
//		MyRoi roiStart(Point(m.src.cols - 120, 0), Point(m.src.cols, 120), m.src);
//		vector <MyRoi> roi7;
//		roiStart.drawRect(m.src);
//		putText(m.src, "START", Point(m.src.cols - 92, 70), fontFace, 1.5f, Scalar(200, 0, 0), 2);
//#endif
//		//vẽ ra 7ROI để lấy mẫu màu da để tính toán ra các tham số HLS
//		roi7.push_back(MyRoi(Point(m.src.cols / 3 - 40, m.src.rows / 6), Point(m.src.cols / 3 - 40 + square_len, m.src.rows / 6 + square_len), m.src));
//		roi7.push_back(MyRoi(Point(m.src.cols / 4 - 40, m.src.rows / 2), Point(m.src.cols / 4 - 40 + square_len, m.src.rows / 2 + square_len), m.src));
//		roi7.push_back(MyRoi(Point(m.src.cols / 3 - 40, m.src.rows / 1.5), Point(m.src.cols / 3 - 40 + square_len, m.src.rows / 1.5 + square_len), m.src));
//		roi7.push_back(MyRoi(Point(m.src.cols / 2 - 40, m.src.rows / 2), Point(m.src.cols / 2 - 40 + square_len, m.src.rows / 2 + square_len), m.src));
//		roi7.push_back(MyRoi(Point(m.src.cols / 2.5 - 40, m.src.rows / 2.5), Point(m.src.cols / 2.5 - 40 + square_len, m.src.rows / 2.5 + square_len), m.src));
//		roi7.push_back(MyRoi(Point(m.src.cols / 2 - 40, m.src.rows / 1.5), Point(m.src.cols / 2 - 40 + square_len, m.src.rows / 1.5 + square_len), m.src));
//		roi7.push_back(MyRoi(Point(m.src.cols / 2.5 - 40, m.src.rows / 1.8), Point(m.src.cols / 2.5 - 40 + square_len, m.src.rows / 1.8 + square_len), m.src));
//
//		for (int j = 0; j < NSAMPLES; j++){
//			roi7[j].drawRect(m.src);
//		}
//		imshow("Wait", m.src);
//		if (cv::waitKey(30) == char('q')) break;
//		roi7.clear();
//	}
//}
//
//#ifdef __linux__
//void progressLinux(int argc, char *argv[]){
//	system("sudo modprobe bcm2835-v4l2");
//	wiringPiSetupGpio();
//	pinMode(LED1, OUTPUT);
//	pinMode(LED2, OUTPUT);
//	pinMode(LED3, OUTPUT);
//	pinMode(LED4, OUTPUT);
//	pinMode(LED5, OUTPUT);
//	pinMode(LED_NO, OUTPUT);
//
//	if (signal(SIGINT, sig_handler) == SIG_ERR){
//		cout << "Not clear GPIO" << endl;
//	}
//
//	square_len = 15;
//
//	//truyen nhan du lieu
//
//	int sockfd, portno, n;
//	struct sockaddr_in serv_addr;
//	struct hostent *server;
//
//	//char buffer[256];
//	if (argc < 3) {
//		fprintf(stderr, "usage %s hostname port\n", argv[0]);
//		exit(0);
//	}
//
//	portno = atoi(argv[2]);
//	sockfd = socket(AF_INET, SOCK_STREAM, 0);
//	if (sockfd < 0)
//		error("ERROR opening socket");
//	server = gethostbyname(argv[1]);
//
//	if (server == NULL) {
//		fprintf(stderr, "ERROR, no such host\n");
//		exit(0);
//	}
//
//	bzero((char *)&serv_addr, sizeof(serv_addr));
//	serv_addr.sin_family = AF_INET;
//	bcopy((char *)server->h_addr,
//		(char *)&serv_addr.sin_addr.s_addr,
//		server->h_length);
//	serv_addr.sin_port = htons(portno);
//	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
//		error("ERROR connecting");
//	struct PointCenter point;
//	////////////////////////////////////////////////////////////////////////////////////////
//
//	MyImage m(0);
//	m.cap >> m.src; // chuyen anh tu cam qua anh nguon
//	/////////////////////////////////
//	Mat framePrev;
//	framePrev = returnImagePrev(&m);
//	////////////////////////////////
//	namedWindow("Wait", 1);
//	setMouseCallback("Wait", CallBackFunc, &m);
//	///////////////////////////////////////////////////
//	waitStartProgress(m);
//	///////////////////////////////////////////////////
//
//	Shape sh;
//	HandGesture hg1;
//	HandGesture hg2;
//
//	m.cap >> m.src;
//	namedWindow("HandDetect", CV_WINDOW_KEEPRATIO);
//
//	//chờ nhận mẫu màu từ lòng bàn tay
//	waitForPalmCover(&m);
//
//	//tính toán
//	average(&m);
//
//	//tat cua so
//	destroyWindow("HandDetect");
//
//	//tạo ra thanh chỉnh màu
//	initWindows();
//	inittrackbar();
//
//	int xcu, ycu, xx, yy;
//	xcu = ycu = xx = yy = 0;
//	int flagM = 1;
//	int flagC = 1;
//
//
//	for (;;){
//
//		sh.frNumber++;
//		sh.frNumber2++;
//
//		m.cap >> m.src;
//
//		flip(m.src, m.src, 0); //Lật ảnh
//
//		/////////////////////////////////
//		m.srcLR = returnImage(m.src, framePrev);
//		/////////////////////////////////
//
//		// giam anh xuống 1 nửa
//		pyrDown(m.srcLR, m.srcLR);
//		Mat imgClone;
//		m.src.copyTo(imgClone);
//		//làm mở anh 1 nửa
//		blur(m.srcLR, m.srcLR, Size(3, 3));
//
//		//chuyển đổi màu của ảnh đó sang HLS
//		cvtColor(m.srcLR, m.srcLR, ORIGCOL2COL);
//
//		//tạo ảnh nhị phân hiển thị màu cùng với màu da
//		produceBinaries(&m);
//
//		//chuyển lại ảnh 1 nửa thành màu RGB lại
//		cvtColor(m.srcLR, m.srcLR, COL2ORIGCOL);
//
//		/////////////////////////////////////////////////////
//		makeContours(&m, &sh, &hg1, &hg2);
//
//		//dieu khien con chuot
//		/////////////////////////////////////////////////////
//		xx = hg1.getPointCenter().x;
//		yy = hg1.getPointCenter().y;
//		if (xcu != xx && ycu != yy && hg1.isHand && hg1.mostFrequentFingerNumber == 1){
//			if (flagM == 0){
//				flagM = 1;
//			}
//			else{
//				int dx = xx - xcu;
//				int dy = yy - ycu;
//				if (!(abs(dx) <= 2 && abs(dy) <= 2)){
//					memset(&point, 0, sizeof(point));
//					point.x = hg1.getPointCenter().x;;
//					point.y = hg1.getPointCenter().y;;
//					point.fingerNum = hg1.mostFrequentFingerNumber;;
//					n = write(sockfd, &point, sizeof(point));
//					if (n < 0)
//						error("ERROR writing to socket");
//				}
//			}
//			flagC = 0;
//		}
//		else{
//			flagM = 0;
//		}
//
//		if (hg1.mostFrequentFingerNumber >= 4 && hg1.isHand && flagC == 0){
//			flagC = 1;
//			digitalWrite(LED_NO, 1);
//			delay(500);
//			digitalWrite(LED_NO, 0);
//
//			memset(&point, 0, sizeof(point));
//			point.x = hg1.getPointCenter().x;;
//			point.y = hg1.getPointCenter().y;;
//			point.fingerNum = hg1.mostFrequentFingerNumber;;
//			n = write(sockfd, &point, sizeof(point));
//			if (n < 0)
//				error("ERROR writing to socket");
//		}
//
//		if (hg1.mostFrequentFingerNumber == 3 && hg1.isHand && flagC == 0){
//			flagC = 1;
//			digitalWrite(LED_NO, 1);
//			delay(500);
//			digitalWrite(LED_NO, 0);
//
//			memset(&point, 0, sizeof(point));
//			point.x = hg1.getPointCenter().x;;
//			point.y = hg1.getPointCenter().y;;
//			point.fingerNum = hg1.mostFrequentFingerNumber;;
//			n = write(sockfd, &point, sizeof(point));
//			if (n < 0)
//				error("ERROR writing to socket");
//
//		}
//		xcu = xx;
//		ycu = yy;
//		////////////////////////////////////////////////////
//		float per = returnPercentDiff(framePrev, m.src);
//		per = (per * 10000) / 100;
//		putText(m.src, to_string(per) + " %", Point(20, 20), fontFace, 1.5f, Scalar(41, 0, 223), 2);
//		/////////////////////////////////////////////////////
//
//		showWindows(m);
//		if (cv::waitKey(30) == char('q')) break;
//	}
//	// clear trạng thái của các GPIO
//	cout << "program finished clear GPIO" << endl;
//	digitalWrite(LED1, 0);
//	digitalWrite(LED2, 0);
//	digitalWrite(LED3, 0);
//	digitalWrite(LED4, 0);
//	digitalWrite(LED5, 0);
//	digitalWrite(LED_NO, 0);
//
//	pinMode(LED1, INPUT);
//	pinMode(LED2, INPUT);
//	pinMode(LED3, INPUT);
//	pinMode(LED4, INPUT);
//	pinMode(LED5, INPUT);
//	pinMode(LED_NO, INPUT);
//	close(sockfd);
//
//	cv::destroyAllWindows();
//	m.cap.release();
//}
//#else 
//void controlCursor(int &flagC, int &flagM, int xx, int yy, int xcu, int ycu, HandGesture hg1){
//	if (xcu != xx && ycu != yy && hg1.isHand && hg1.mostFrequentFingerNumber == 1){
//		if (flagM == 0){
//			flagM = 1;
//		}
//		else{
//			int dx = xx - xcu;
//			int dy = (yy - ycu);
//			if (!(abs(dx) <= 2 && abs(dy) <= 2))
//				MouseMove(4 * dx, 4 * dy);
//		}
//		flagC = 0;
//	}
//	else{
//		flagM = 0;
//	}
//
//	if (hg1.mostFrequentFingerNumber >= 4 && hg1.isHand && flagC == 0){
//		flagC = 1;
//
//		MouseLeftBtnDown();
//		cout << "click left mouse " << endl;
//		Sleep(100);
//		MouseLeftBtnUp();
//
//	}
//
//	if (hg1.mostFrequentFingerNumber == 3 && hg1.isHand && flagC == 0){
//		flagC = 1;
//		MouseRightBtnDown();
//		cout << "click right mouse " << endl;
//		Sleep(100);
//		MouseRightBtnUp();
//	}
//}
//
//void progressWindows(){
//
//	square_len = 20;
//	MyImage m(0);
//	m.cap >> m.src; // chuyen anh tu cam qua anh nguon
//	/////////////////////////////////
//	Mat framePrev;
//	framePrev = returnImagePrev(&m);
//	////////////////////////////////
//	namedWindow("Wait", 1);
//	setMouseCallback("Wait", CallBackFunc, &m);
//	
//
//	///////////////////////////////////////////////////
//	waitStartProgress(m);
//	///////////////////////////////////////////////////
//	flagOn = 0;
//	Shape sh;
//	HandGesture hg1;
//	HandGesture hg2;
//
//	m.cap >> m.src;
//	//chờ nhận mẫu màu từ lòng bàn tay
//	waitForPalmCover(&m);
//
//	//tính toán
//	average(&m);
//
//	//tat cua so
//	destroyWindow("WaitPalm");
//	destroyAllWindows();
//	//tạo ra thanh chỉnh màu
//	initWindows();
//	namedWindow("HandDetect", CV_WINDOW_KEEPRATIO);
//	setMouseCallback("HandDetect", CallBackFuncReset, &m);
//	inittrackbar();
//
//	int xcu, ycu, xx, yy;
//	xcu = ycu = xx = yy = 0;
//	int flagM = 1;
//	int flagC = 1;
//
//
//	for (;;){
//
//		sh.frNumber++;
//		sh.frNumber2++;
//
//		m.cap >> m.src;
//
//		flip(m.src, m.src, 1); //Lật ảnh
//		canBangHistogram(m.src);
//		/////////////////////////////////
//		m.srcLR = returnImage(m.src, framePrev);
//		/////////////////////////////////
//
//		// giam anh xuống 1 nửa
//		pyrDown(m.srcLR, m.srcLR);
//		//làm mở anh 1 nửa
//		blur(m.srcLR, m.srcLR, Size(3, 3));
//
//		//chuyển đổi màu của ảnh đó sang HLS
//		cvtColor(m.srcLR, m.srcLR, ORIGCOL2COL);
//
//		//tạo ảnh nhị phân hiển thị màu cùng với màu da
//		produceBinaries(&m);
//
//		//chuyển lại ảnh 1 nửa thành màu RGB lại
//		cvtColor(m.srcLR, m.srcLR, COL2ORIGCOL);
//
//		/////////////////////////////////////////////////////
//		makeContours(&m, &sh, &hg1, &hg2);
//
//		//dieu khien con chuot
//		/////////////////////////////////////////////////////
//		xx = hg1.getPointCenter().x;
//		yy = hg1.getPointCenter().y;
//		controlCursor(flagC, flagM, xx, yy, xcu, ycu, hg1);
//		xcu = xx;
//		ycu = yy;
//		////////////////////////////////////////////////////
//		float per = returnPercentDiff(framePrev, m.src);
//		per = (per * 10000) / 100;
//		if (per < 30.0f){
//			cout << "thay doi background" << endl;
//			m.cap >> framePrev;
//		}
//		putText(m.src, to_string(per) + " %", Point(20, 20), fontFace, 1.5f, Scalar(41, 0, 223), 2);
//		/////////////////////////////////////////////////////
//
//		showWindows(m);
//		if (cv::waitKey(30) == char('q')) {
//			break;
//		}
//		if (flagReset == 1){
//			break;
//		}
//	}
//	cv::destroyAllWindows();
//	m.cap.release();
//	if (flagReset == 1){
//		flagReset = 0;
//		threshold_bar = 0;
//		for (int i = 0; i < NSAMPLES; i++){
//			for (int j = 0; j < 3; j++){
//				avgColor[i][j] = 0;
//				c_lower[i][j] = 0;
//				c_upper[i][j] = 0;
//			}
//		}
//		progressWindows();
//	}
//}
//#endif
//
