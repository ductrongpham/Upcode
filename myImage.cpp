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
void MyImage::setCam(int index){
	cameraSrc = index;
	cap = VideoCapture(index);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#ifdef __linux__
	cap.set(CV_CAP_PROP_FPS, 90);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#endif
}

void MyImage::setCam(string file){
	cap = VideoCapture(file);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#ifdef __linux__
	cap.set(CV_CAP_PROP_FPS, 90);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#endif
}
MyImage::MyImage(int webCamera){
	cameraSrc = webCamera;
	cap = VideoCapture(webCamera);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#ifdef __linux__
	cap.set(CV_CAP_PROP_FPS, 90);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#endif
}

MyImage::MyImage(string linkVideo){
	cap = VideoCapture(linkVideo);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#ifdef __linux__
	cap.set(CV_CAP_PROP_FPS, 90);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
#endif
}
