#include "watermark.h"

string uchar2bin(unsigned char value) {
	string bin;
	for (int i = 7; i >= 0; i--) {
		bin += ((value >> i) & 1) ? '1' : '0';
	}
	return bin;
}

unsigned char bin2uchar(string bin) {
	unsigned char uch = 0;
	for (int i = 0; i < 8; i++) {
		if (bin[i] == '1') {
			uch |= (1 << (7 - i));
		}
	}
	return uch;
}

Mat makeWatermark(Mat image1, Mat image2) {
	Mat ans(image1.rows, image1.cols, CV_8UC1);
	for (int i = 0; i < image1.rows; i++) {
		for (int j = 0; j < image1.cols; j++) {
			unsigned char pixel1, pixel2;
			pixel1 = image1.at<uchar>(i, j);
			pixel2 = image2.at<uchar>(i, j);
			
			string bin1, bin2;
			bin1 = uchar2bin(pixel1);
			bin2 = uchar2bin(pixel2);
			bin1[7] = bin2[0];
			ans.at<uchar>(i, j) = bin2uchar(bin1);
		}
	}

	return ans;
}

Mat recoveryImage(Mat image) {
	Mat ans(image.rows, image.cols, CV_8UC1);
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			string bin="", bin_i;
			bin_i = uchar2bin(image.at<uchar>(i, j));
			for (int x = 0; x < 8; x++) {
				bin += bin_i[7];
			}
			ans.at<uchar>(i, j) = bin2uchar(bin);
		}
	}
	return ans;
}