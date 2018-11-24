#include "header.h"

void turnToBlob(const Mat& src, Mat dest, double kuszobArany) {
	int numOfRows = src.rows;
	int numOfCols = src.cols;

	kuszobol(src, dest, kuszobArany);
	Mat kernel = cv::getStructuringElement(MORPH_RECT, Size(5, 5));
	erode(dest, dest, kernel);
}