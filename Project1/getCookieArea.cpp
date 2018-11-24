#include "header.h"

double getCookieArea(const Mat src) {
	//a blob kontúrjának megkeresése:
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(src, contours, hierarchy, RETR_LIST, CHAIN_APPROX_NONE);

	//a terület kiszámitása:
	return contourArea(contours[0]);
}

