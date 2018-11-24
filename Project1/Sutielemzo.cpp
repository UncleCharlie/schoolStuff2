#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <sstream>
#include "header.h"

using namespace cv;
using namespace std;

int main() {

	//Kepek beolvasasa:
	Mat etalonColor = imread("etalon.jpg", ImreadModes::IMREAD_COLOR);
	Mat etalon = imread("etalon.jpg", IMREAD_GRAYSCALE);
	int numOfRows = etalon.rows;
	int numOfCols = etalon.cols;

	//blobot tartalmazó kép létrehozása:
	Mat blob = cv::Mat::zeros(numOfRows, numOfCols, CV_8UC1);
	//a kep homogen "blob"-bá redukálása, (az alapertelmezett kuszobertek a kuszobol fuggvenyhez= 5):
	turnToBlob(etalon, blob);

	//az etalon süti területének megkeresése:
	double etalonTerulet = getCookieArea(blob);
	cout << "etalon terulet: " << etalonTerulet << "\n";
	//a területre vonatkozó tolerancia értéket +-3000-ben határoztam meg:
	double toleranciaTeruletAlso = etalonTerulet - 3500;
	double toleranciaTeruletFelso = etalonTerulet + 3500;
	//az etalon süti csokidarabjai számának megkeresése:
	int etalonCsokiDarabok = chocolateSpots(etalonColor);
	cout << "etalon csokidarabok szama: " << etalonCsokiDarabok << "\n";
	//a csokoládédarabok számára vonatkozó alsó tolerancia értéket etalon-3-ban határoztam meg, felsőt nem határoztam meg:
	int toleranciaCsokiAlso = etalonCsokiDarabok - 1;

	int counter = 1;
	int tesztsutiCsokiDarabok;
	double tesztSutiTerulet;

	while (1) {
	//képek beolvasása:
		stringstream name;
		name << "tesztsuti" << counter << ".jpg";
		string filename = name.str();
		
		Mat tesztsuti = imread(filename, IMREAD_GRAYSCALE);
		Mat tesztsutiColor = imread(filename, ImreadModes::IMREAD_COLOR);

		if (tesztsuti.empty())
			break;
	//suti vizsgálata:

		turnToBlob(tesztsuti, tesztsuti);

		tesztsutiCsokiDarabok = chocolateSpots(tesztsutiColor, toleranciaCsokiAlso);
		tesztSutiTerulet = getCookieArea(tesztsuti);

		drawArea(tesztsuti, tesztsutiColor, toleranciaTeruletAlso, toleranciaTeruletFelso);

		imshow("teszt", tesztsutiColor);

		if (cookieSizeTest(tesztsuti, toleranciaTeruletAlso, toleranciaTeruletFelso) && (tesztsutiCsokiDarabok > toleranciaCsokiAlso))
			cout << filename << ": A vizsgalt suti terulete " << tesztSutiTerulet << "\nA csokidarabok szama: " << tesztsutiCsokiDarabok << "\nA suti atment a minosegvizsgalaton\n";
		else
			cout << filename << ": A vizsgalt suti terulete " << tesztSutiTerulet << "\nA csokidarabok szama: " << tesztsutiCsokiDarabok << "\nA suti megbukott a minosegvizsgalaton\n";

		counter++;
		cv::waitKey();
	}
	

	cv::waitKey();

}
