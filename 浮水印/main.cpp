#include <opencv2/opencv.hpp>
#include <iostream>
#include "watermark.h"
#include "imageHandler.h"

using namespace cv;
using namespace std;

int main() {
	Mat image1, image1_grey, image2, image2_grey;
	image1 = imread("001.jpg");
	if (image1.empty()) {
		cout << "Image Input Error." << endl;
		return -1;
	}
	image2 = imread("002.jpg");
	if (image2.empty()) {
		cout << "Image Input Error." << endl;
		return -1;
	}
	
	cvtColor(image1, image1_grey, COLOR_BGR2GRAY);
	cvtColor(image2, image2_grey, COLOR_BGR2GRAY);


	Mat watermark = makeWatermark(image1_grey, image2_grey);
	show("watermark", watermark);
	bool saveWatermark = imwrite("watermark.jpg", watermark);

	Mat recovery = recoveryImage(watermark);
	show("recovery", recovery);
	bool saveRecovery = imwrite("recovery.jpg", recovery);

	return 0;
}