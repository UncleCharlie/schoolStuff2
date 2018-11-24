/*#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include "header.h"

using namespace cv;
using namespace std;
////This test this test this

int main() {
	Mat img = imread("etalon.jpg", IMREAD_GRAYSCALE);
	cv::Mat dest = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);

	int ratio = 1;
	string menu = "tool";
	createTrackbar("ratio", "teszt", &ratio, 0.1);
	

	while(1) {
		
		kuszobol(img, dest, ratio);
		imshow("teszt", dest);
		cv::waitKey();
	}


	cv::waitKey();

	return 0;
}
*/



//konvex burok
//vector<Point> hull;

//convexHull(contours[4], hull, false, true);
//polylines(etalon, hull, true,color,4);

////volgypontok
//vector<int> hull2;
//convexHull(contours[4], hull2, false, false);

//vector<Vec4i> defects;
//convexityDefects(contours[4], hull2,defects);





//drawMarker(etalon, defects[2],color, MARKER_CROSS);

//összes kontúr kirajzolása:
//GaussianBlur(blob, blob, Size(15, 15), 2, 2);
//GaussianBlur(blob, blob, Size(15, 15), 2, 2);
//Mat kernel = cv::getStructuringElement(MORPH_RECT, Size(5, 5));
//morphologyEx(blob, blob, MORPH_CLOSE, kernel);
//	dilate(blob, blob, kernel);





//	drawContours(img, contours, 1, Scalar(94, 206, 165), 2, 8, hierarchy, 0, Point());
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	//kontur kirajzolasa az etalon kepre
	//	//kepnev,konturok,konturindex,szin,vastagsag, vonaltipus, a contours tömb 4-edik sorában van a süti kontúrja

	//	drawContours(etalon, contours, 0, Scalar(94, 206, 165), 2, 8, hierarchy, 0, Point());
	//	//drawContours(img, contours, i, Scalar(94, 206, 165), 2, 8, hierarchy, 0, Point());
	//	printf("%d\n", i);
	//}
	// /Konturkereses

	//imshow("teszt", etalon);
