#include "header.h"

void calcHisto_local(Mat img, Mat& histo) {
	vector<Mat> kepek;
	kepek.push_back(img); // egy k�pet haszn�lunk

	vector<int> csatornak;
	csatornak.push_back(0); //a k�pnek a 0. csatorn�j�t haszn�ljuk

	vector<int> hiszto_meretek;
	hiszto_meretek.push_back(256); //sz�rke�rnyalatok sz�ma

	vector<float> hiszto_tartomanyok;
	hiszto_tartomanyok.push_back(0.f); //hol kezd�dik a tartom�ny
	hiszto_tartomanyok.push_back(225.f); //meddig tart

										 //accumlate: marad false (null�zza a hisztogrammot)

	calcHist(kepek, csatornak, noArray(), histo, hiszto_meretek,
		hiszto_tartomanyok, false);
}