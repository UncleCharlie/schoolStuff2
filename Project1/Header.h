#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;

void kuszobol(const Mat& src, Mat dest, float ratio);
void calcHisto_local(Mat img, Mat& histo);
void convert(const Mat src, Mat& dest);