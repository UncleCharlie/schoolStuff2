#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "header.h"

using namespace cv;
using namespace std;
RNG rng(12345);

int main() {

	double E = 0;
	Mat etalon = imread("etalon.png", ImreadModes::IMREAD_COLOR);
	Mat img = imread("etalon.png", IMREAD_GRAYSCALE);
	Mat blob = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	//küszöbérték:
	double ratio = 1;
	//Forma észlelése összehasonlitáshoz:
	kuszobol(img, blob, ratio);

	Mat etalonlab;
	convert(etalon, etalonlab);
	//Konturkereses:
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
	for (int i = 0; i < contours.size(); i++)
	{
		//vonal szinenek megadasa
		Scalar color = Scalar(rng.uniform(4, 255), rng.uniform(4, 255), rng.uniform(4, 55));
		//kontur kirajzolasa az etalon kepre
		//kepnev,konturok,konturindex,szin,vastagsag, vonaltipus
		drawContours(etalon, contours, i, color, 2, 8, hierarchy, 0, Point());
	}
	// /Konturkereses
	imshow("teszt", etalon);


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
		printf("suti%d: %d \n", i, E);
		E = 0;
	}

	cv::waitKey();
}