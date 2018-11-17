#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;
////This test this test this
void calcHisto_local(Mat img, Mat& histo) {
	vector<Mat> kepek;
	kepek.push_back(img); // egy képet használunk

	vector<int> csatornak;
	csatornak.push_back(0); //a képnek a 0. csatornáját használjuk

	vector<int> hiszto_meretek;
	hiszto_meretek.push_back(256); //szürkeárnyalatok száma

	vector<float> hiszto_tartomanyok;
	hiszto_tartomanyok.push_back(0.0f); //hol kezdődik a tartomány
	hiszto_tartomanyok.push_back(255.f); //meddig tart

	//accumlate: marad false (nullázza a hisztogrammot)

	calcHist(kepek, csatornak, noArray(), histo, hiszto_meretek,
		hiszto_tartomanyok, false);
}
void kuszobol(const Mat& src, Mat dest, float ratio) {
	ratio *= 0.1;
	Mat img = src.clone();
	int eloter = ratio * img.cols * img.rows;
	double osszeg = 0.0;
	Mat histo;
	calcHisto_local(img, histo);

	for (int i = 0; i < histo.rows; i++)
	{
		osszeg += histo.at<float>(i);
		if (osszeg > eloter) {
			threshold(img, dest, i, 255, THRESH_BINARY);
			break;
		}

	}
}


int main() {
	Mat img = imread("scanned3.png", IMREAD_GRAYSCALE);
	cv::Mat dest = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);

	int ratio = 1;
	string menu = "tool";
	createTrackbar("ratio", menu, &ratio, 0.1);

	while (1) {
		kuszobol(img, dest, ratio);
		imshow("teszt", dest);
		cv::waitKey();
	}




	cv::waitKey();


	return 0;
}
