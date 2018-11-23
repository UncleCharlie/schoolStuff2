#include "header.h"

void convert(const Mat src, Mat& dest) {
	Mat srcf, lab;
	src.convertTo(srcf, CV_32FC3, 1 / 255.0);
	cvtColor(srcf, dest, COLOR_BGR2Lab);
}