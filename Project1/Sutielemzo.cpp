#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

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

void convert(const Mat src, Mat& dest) {
	Mat srcf, lab;
	src.convertTo(srcf, CV_32FC3, 1 / 255.0);
	cvtColor(srcf, dest, COLOR_BGR2Lab);
}


int main() {
	double E = 0;
	Mat etalon = imread("etalon.png", ImreadModes::IMREAD_COLOR);
	Mat img = imread("etalon.png", IMREAD_GRAYSCALE);
	Mat blob = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	//küszöbérték:
	double ratio = 1;
	//Forma észlelése összehasonlitáshoz:
	kuszobol(img, blob, ratio);
	imshow("teszt", blob);
	


	Mat etalonlab;
	convert(etalon, etalonlab);
	
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

