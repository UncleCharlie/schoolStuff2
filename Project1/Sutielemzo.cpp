#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "header.h"

using namespace cv;
using namespace std;
RNG rng(12345);

int main() {

	//Kepek beolvasasa:
	//+ETALONLAB+ az etalonlabot tartalmazó kép készitése
	//+BLOB+ blobot tartalmazó kép létrehozása
	Mat etalon = imread("etalon.png", ImreadModes::IMREAD_COLOR);
	Mat img = imread("etalon.png", IMREAD_GRAYSCALE);
	Mat etalonlab;
	convert(etalon, etalonlab);

	Mat blob = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	kuszobol(img, blob, 1);

	Mat kernel = cv::getStructuringElement(MORPH_CROSS, Size(6, 6));
	dilate(blob, blob, kernel);


	//+KONTÚR+ Konturkereses:
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(blob, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	Scalar color = Scalar(rng.uniform(0, 0), rng.uniform(0, 255), rng.uniform(0, 0));

	//összes kontúr kirajzolása:
	for (int i = 0; i < 5; i++)
	{
		//kontur kirajzolasa az etalon kepre
		//kepnev,konturok,konturindex,szin,vastagsag, vonaltipus, a contours tömb 4-edik sorában van a süti kontúrja
		drawContours(etalon, contours, i, color, 2, 8, hierarchy, 0, Point());
	}
	// /Konturkereses
	imshow("teszt", etalon);


	cv::waitKey();



}













/*	//+PONTONKÉNTI VIZSGÁLAT+
	double E = 0;
	for (int i = 1; i <= 3; ++i) {
		String path = "suti" + std::to_string(i) + ".png";
		cout << path << "\n";
		Mat img = imread(path);
		Mat lab;
		convert(img, lab);

		for (int j = 0; j < etalon.rows; ++j) {
			for (int k = 0; k < etalon.cols; ++k) {
				Vec3f c = etalonlab.at<Vec3f>(j, k);
				Vec3f f = lab.at<Vec3f>(j, k);


				double L = c[0] - f[0];
				double A = c[1] - f[1];
				double B = c[2] - f[2];


				E += sqrt(L * L + A * A + B * B);

			}
		}
		E = 0;
	}

	
}

*/