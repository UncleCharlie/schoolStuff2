#include "header.h"

void turnToBlob(const Mat& src, Mat dest, double kuszobArany) {

	//kuszobol(src, dest, kuszobArany);
	threshold(src, dest,250, 255, THRESH_BINARY);
	Mat kernel = cv::getStructuringElement(MORPH_RECT, Size(5, 5));
	morphologyEx(dest, dest, MORPH_CLOSE, kernel);
	erode(dest, dest, kernel);

}