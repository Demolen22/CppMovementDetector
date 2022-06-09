#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core.hpp>
#include <string>


using namespace std;
using namespace cv;


int main() {

	//VideoCapture cap("http://live.uci.agh.edu.pl/video/stream1.cgi?start=1543408695");
	VideoCapture cap(0);
	Mat img1, img2, img2bw, d;
	int counter = 1;
	while (true) {
		cap.read(img1);
		cap.read(img2);
		cvtColor(img1, img1, COLOR_RGB2GRAY, 1);
		cvtColor(img2, img2bw, COLOR_RGB2GRAY, 1);
		absdiff(img1, img2bw, d);
		GaussianBlur(d, d, Size(3, 3), 3, 0);
		Canny(d, d, 45, 80);
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
		dilate(d, d, kernel);
		vector<vector<Point>> contours;
		vector<Vec4i> priority;
		findContours(d, contours, priority, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
		drawContours(img2, contours, -1, Scalar(0, 255, 0), 2);
		imshow("Image", img2);
		int k = waitKey(1);
		string filename = "screen" + to_string(counter)+ ".png";
		if (k == 's'){
			imwrite(filename, img2);
			counter++;
		}
	}
	return 0;
}

