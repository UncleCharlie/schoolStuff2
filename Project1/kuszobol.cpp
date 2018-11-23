#include "header.h"

using namespace cv;
using namespace std;

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