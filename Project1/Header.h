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
void turnToBlob(const Mat& src, Mat dest, double kuszobArany = 5);
double getCookieArea(const Mat src);
bool cookieSizeTest(const Mat src, double toleranciaAlso, double toleranciaFelso);
int chocolateSpots(const Mat& src, int toleranciaCsokiAlso = 0);
void drawArea(const Mat blob, const Mat& src, double toleranciaTeruletAlso, double toleranciaTeruletFelso);