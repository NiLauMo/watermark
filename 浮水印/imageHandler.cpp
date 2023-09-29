#include "imageHandler.h"

void show(string windowName, Mat var) {
	namedWindow(windowName, WINDOW_NORMAL);
	resizeWindow(windowName, 800, 600);
	imshow(windowName, var);
	waitKey(0);
}