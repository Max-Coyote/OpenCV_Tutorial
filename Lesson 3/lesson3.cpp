#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp> 

using namespace cv;

int main()
{
	Mat image = Mat::zeros(400, 400, CV_8UC3);
	line(image, Point(0, 0), Point(100, 100), Scalar(255, 0, 0), 
													1, LINE_AA, 0);
	circle(image, Point(100, 100), 30, Scalar(0, 0, 255),
											-1, LINE_AA, 0);
	ellipse(image, Point(250, 250), Size(30, 50), 0, 0, 
		360, Scalar(0, 255, 0), -1, LINE_AA, 0);
	
	std::vector<Point> pts;
	pts.push_back(Point(10, 60));
	pts.push_back(Point(10, 10));
	
	pts.push_back(Point(60, 60));
	pts.push_back(Point(60, 10));		
	fillConvexPoly(image, pts, Scalar(130, 130, 130));

	arrowedLine(image, Point(300, 300), Point(200,200), Scalar(255, 0, 0), 1, LINE_AA, 0, 0.2);
	//rec
	//putc
	/*void rectangle(InputOutputArray img, Point pt1, Point pt2, const Scalar& color, 
int thickness=1, int lineType=LINE_8, int shift=0 ) 
*/

	rectangle(image, Point(10, 10), Point(50, 100), Scalar(255, 0, 0), 1, LINE_AA, 0);
	
	/*InputOutputArray img, Rect rec,
		const Scalar& color, int thickness = 1,	
		int lineType = LINE_8, int shift = 0);*/



	imshow("Tutorial", image);
	waitKey(0);
}