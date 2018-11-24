#include "header.h"

bool cookieSizeTest(const Mat src, double toleranciaAlso, double toleranciaFelso) {
	//a vizsgált képek átalakítása:
	Mat tesztblob = cv::Mat::zeros(src.rows, src.cols, CV_8UC1);
	turnToBlob(src, tesztblob);
	double teszTerulet = getCookieArea(tesztblob);

	if (teszTerulet < toleranciaAlso || teszTerulet  > toleranciaFelso)
		return false;
	else
		return true;
}