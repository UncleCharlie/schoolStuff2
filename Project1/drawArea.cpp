#include "header.h"

using namespace cv;
using namespace std;

void drawArea(const Mat blob, const Mat& src, double toleranciaTeruletAlso, double toleranciaTeruletFelso) {
	
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(blob, contours, hierarchy, RETR_LIST, CHAIN_APPROX_NONE);
	double area = getCookieArea(blob);
		
	for (int i = 0; i < contours.size(); i++)
	{
		if (area < toleranciaTeruletAlso || area > toleranciaTeruletFelso)
			drawContours(src, contours, i, Scalar(0, 0, 255), 2, 8, hierarchy, 0, Point());
		else
			drawContours(src, contours, i, Scalar(94, 206, 165), 2, 8, hierarchy, 0, Point());
	}
}