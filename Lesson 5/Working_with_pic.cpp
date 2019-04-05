#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

#define PI 3.14159265


int main() {
	int a = 40;
	Mat src = imread("C:/Users/admin/Pictures/Colorspaces.jpg");
	Mat src_out;
	cvtColor(src, src_out, COLOR_BGR2GRAY);
	resize(src, src_out, Size(454, 176));
	namedWindow("winda", WINDOW_AUTOSIZE);
	int t1=100;
	int t2=150;
	createTrackbar("min", "winda", &t1, 300);
	createTrackbar("max", "winda", &t2, 300);

	vector<vector<Point>> countours;
	vector<Vec4i> hierarchy;

	

	Mat drawing = Mat::zeros(src_out.size(), CV_8UC3);
	Mat src_canny;
	Canny(src_out, src_canny, t1, t2, 3);

	findContours(src_canny, countours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for(int i = 0; i < countours.size(); i++)
	{
		Scalar color = Scalar(255, 0, 0);
		drawContours(src_canny, countours, i, color, 2, 8, hierarchy, 0, Point());
	}


	//for(int i = 0;i< src_out.cols;i++)
	//{
	//	for(int j = 0; j < src_out.rows;j++)
	//	{
	//		//cout << src.at<Vec3b>(i, j)<<endl;
	//		if(
	//			(src_out.at<Vec3b>(j,i)[0]>130) &&
	//			(src_out.at<Vec3b>(j, i)[1]>130) &&
	//			(src_out.at<Vec3b>(j, i)[2]>130))
	//		{
	//			src_out.at<Vec3b>(j, i)[0] = 0;
	//			src_out.at<Vec3b>(j, i)[1] = 0;
	//			src_out.at<Vec3b>(j, i)[2] = 0;
	//		}



	//	}
	//}

	imshow("winda", src_canny);
	waitKey(0);

	/*while(true)
	{
		Canny(src_out, src_out1, t1, t2, 3);
		imshow("winda", src_out1);
		waitKey(1);

	}*/

	
	
	//prius_assist();
}

