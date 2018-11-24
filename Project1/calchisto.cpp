#include "header.h"

void calcHisto_local(Mat img, Mat& histo) {
	vector<Mat> kepek;
	kepek.push_back(img); // egy képet használunk

	vector<int> csatornak;
	csatornak.push_back(0); //a képnek a 0. csatornáját használjuk

	vector<int> hiszto_meretek;
	hiszto_meretek.push_back(256); //szürkeárnyalatok száma

	vector<float> hiszto_tartomanyok;
	hiszto_tartomanyok.push_back(0.f); //hol kezdõdik a tartomány
	hiszto_tartomanyok.push_back(225.f); //meddig tart

										 //accumlate: marad false (nullázza a hisztogrammot)

	calcHist(kepek, csatornak, noArray(), histo, hiszto_meretek,
		hiszto_tartomanyok, false);
}