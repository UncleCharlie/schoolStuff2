#include "header.h"

int chocolateSpots(const Mat& src, int toleranciaCsokiAlso) {
	
	Mat tesztSuti = src.clone();
	Mat tesztSutiOriginal = src.clone();

	//Morfologiai muveletekkel redukaljuk a kepet a foltdetektalashoz
	Mat kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(25, 25));
	erode(tesztSuti, tesztSuti, kernel);

	kernel = cv::getStructuringElement(MORPH_CROSS, Size(14, 15));
	dilate(tesztSuti, tesztSuti, kernel);

	kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(14, 15));
	morphologyEx(tesztSuti, tesztSuti, MORPH_CLOSE, kernel);
	
	erode(tesztSuti, tesztSuti, kernel);

	//kontrasztot allitunk, a szinek szetvalasztasa erdekeben:
	double alpha = 5.0; 
	int beta = 1;       
	Mat tesztSutiTmp = Mat::zeros(tesztSuti.size(), tesztSuti.type());
		
	for (int y = 0; y < tesztSuti.rows; y++) {
		for (int x = 0; x < tesztSuti.cols; x++) {
			for (int c = 0; c < tesztSuti.channels(); c++) {
				tesztSutiTmp.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha*tesztSuti.at<Vec3b>(y, x)[c] + beta);
			}
		}
	}
		
	kernel = cv::getStructuringElement(MORPH_CROSS, Size(14, 15));
	dilate(tesztSuti, tesztSuti, kernel);
		
	kernel = cv::getStructuringElement(MORPH_ELLIPSE, Size(8, 15));
	morphologyEx(tesztSutiTmp, tesztSutiTmp, MORPH_CLOSE, kernel);



	tesztSuti.setTo(Scalar(255, 255, 255));
	//a gyakorlaton megirt Orange Copy-val kinyerjuk kuszobertek feletti foltokat:
	for (int i = 0; i < tesztSutiTmp.rows; ++i) {
		for (int j = 0; j < tesztSutiTmp.cols; ++j) {
				Vec3b c = tesztSutiTmp.at<Vec3b>(i, j);
				Vec3b h = tesztSutiTmp.at<Vec3b>(i, j);
				if (c[2] > 50 && c[0] < 180 && c[1] < 150)
					tesztSuti.at<Vec3b>(i, j) = c;
		}
	}

	//feketefeher kepet keszitunk:
	cvtColor(tesztSuti, tesztSuti, CV_BGR2GRAY);
	threshold(tesztSuti, tesztSuti, 250, 290, THRESH_BINARY);
	
	//detektalt csokidarabok kirajzolasa:
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(tesztSuti, contours, hierarchy, RETR_LIST, CHAIN_APPROX_NONE);
	
	for (int i = 0; i < contours.size(); i++)
	{
		if(contours.size() < toleranciaCsokiAlso)
			drawContours(src, contours, i, Scalar(0, 0, 255), 2, 8, hierarchy, 0, Point());
		else
			drawContours(src, contours, i, Scalar(94, 206, 165), 2, 8, hierarchy, 0, Point());
	}
	
	return  contours.size();
}