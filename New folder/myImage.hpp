#ifndef _MYIMAGE_
#define _MYIMAGE_ 

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

class MyImage{

public:
	int B;
	int C;
	int S;

	MyImage();
	MyImage(int webCamera);
	Mat src; // Load the image
	Mat srcLR; //ảnh này có kích thước =1/2 ảnh nguồn
	Mat bw; // Create binary image from source image
	vector<Mat> bwList; 
	VideoCapture cap;
	int cameraSrc;
	void initWebCamera(int i);
	void adjustCap(VideoCapture &cap);
};

#endif