#include "header.h"

double getCookieArea(const Mat src) {
	//a blob kont�rj�nak megkeres�se:
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(src, contours, hierarchy, RETR_LIST, CHAIN_APPROX_NONE);

	//a ter�let kisz�mit�sa:
	return contourArea(contours[0]);
}

