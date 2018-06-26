#include "myImage.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace cv;

MyImage::MyImage(){
}

MyImage::MyImage(int webCamera){
	cameraSrc = webCamera;
	cap = VideoCapture(webCamera);
	cap.set(CV_CAP_PROP_FPS, 10);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#ifdef __linux__
	cap.set(CV_CAP_PROP_FPS, 90);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

#endif
}
void MyImage::adjustCap(VideoCapture &cap){
	cap.set(CV_CAP_PROP_BRIGHTNESS, float(B));
	cap.set(CV_CAP_PROP_CONTRAST, float(C));
	cap.set(CV_CAP_PROP_SATURATION, float(S));
	cap.set(CV_CAP_PROP_GAIN, float(G));
}