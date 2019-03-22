
#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	Mat src = imread("C:/git/OpenCV_Tutorial/Lesson 4/Prius_Top.png");
	Mat Prius;
	resize(src, Prius, Size(454, 176)); //изменение размеров полотна mat
	Mat drawing = Mat::zeros(Prius.rows * 3, Prius.cols * 3, CV_8UC3);
	rectangle(drawing, Rect(Point(0, 0), Point(drawing.cols, drawing.rows)), Scalar(255,255,255), -1, 8, 0);
	Prius.copyTo(drawing(Rect(Prius.cols, Prius.rows, Prius.cols, Prius.rows)));
	namedWindow("winda", WINDOW_AUTOSIZE);
	int a = 20;
	while (true)
	{
		createTrackbar("Steering angle", "winda", &a, 80);
		imshow("winda", drawing);
		imshow("second_window", Prius);
		waitKey(1);
		if (a == 80) break;
	}
							
}