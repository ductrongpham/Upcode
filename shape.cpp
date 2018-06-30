#include "shape.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
 
Shape::Shape(){
	frNumber = 0;
	frNumber2 = 0;

	int cIdxShape = 0;
	int cIdxShape2 = 0;
	fontFace = FONT_HERSHEY_PLAIN;
}

void Shape::initVectors(){
	hullInt = vector<vector<int> >(contourShape.size());
	hullPoint = vector<vector<Point> >(contourShape.size());
	defectShape = vector<vector<Vec4i> >(contourShape.size());
}

void Shape::drawFingerTips(Mat src, Shape *sh, int idxSh, vector <Point> fingerTip1){
	cv::Point p;
	cv::Moments mo;
	mo = cv::moments(sh->contourShape[idxSh]);
	cv::Point center;
	center = cv::Point(mo.m10 / mo.m00, mo.m01 / mo.m00);

	for (int i = 0; i < fingerTip1.size(); i++){
		p = fingerTip1[i];
		cv::circle(src, p, 5, Scalar(255, 255, 0), 4);
		cv::circle(src, p, 8, Scalar(100, 0, 255), 5);
	}
	cv::circle(src, center, 8, Scalar(0, 200, 0), 4);
}