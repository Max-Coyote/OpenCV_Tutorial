#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	cv::Mat src = cv::imread("Priusoracolored.png");
	cv::imshow("first_window", src);
	cv::waitKey(0);
}