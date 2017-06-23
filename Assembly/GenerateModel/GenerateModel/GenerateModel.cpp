// GenerateModel.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <cv.h>  
#include <highgui.h> 
#include <math.h>  
#include <iostream>
#include <set>
#include <fstream>
#include "opencv2/opencv.hpp" 

using namespace std;
using namespace cv;

struct MyPoint
{
	double x;
	double y;
	int z;
	double weight;
};
struct Pair
{
	int index;
	int num;
};

MyPoint CrossPoint(const CvPoint* line1, const CvPoint* line2);
MyPoint VanishingPoint(vector<CvPoint*> &lines);
// bool divide_lines(MyPoint pt1, MyPoint pt2, CvPoint *line);
bool ifinline(MyPoint pt, CvPoint *line);
bool dividephoto(string path);
extern "C" __declspec(dllexport) bool __stdcall handleImage(int x1, int y1, int x2, int y2, const char* userId, const char* picId);

void on_mouse(int event, int x, int y, int flags, void* ustc);
vector<CvPoint> conorpoints1;


bool pointsort(Pair pair1, Pair pair2) { return pair1.num > pair2.num; }

vector<CvPoint> conorpoints;
vector<MyPoint> vanishing;
IplImage * src;
IplImage * sourcepic;

//int main(int argc, char** argv)
//{
//bad result:2,10,14,12
//illegal pic:9
//	  string user_id = "01";
//	  string pic_id = "01";
//
//	if (handleImage(225, 206, 671, 462, user_id, pic_id))
//		cout << "ok" << endl;

/*string path = "img\\" + user_id + "\\" + pic_id + "\\";
string pfilename = path + "home.jpg";

const char *filename = pfilename.c_str();
IplImage* src0 = cvLoadImage(filename);

if (!src0)
{
printf("Load image error!\n");
return -1;
}

src = cvCreateImage(
cvSize(1000, 1000 * src0->height / src0->width),
src0->depth,
src0->nChannels
);
cvResize(src0, src);

cvNamedWindow("PointSelect", 1);
cvShowImage("PointSelect", src);
cvSetMouseCallback("PointSelect", on_mouse, 0);

cvWaitKey(0);*/
//}


void on_mouse(int event, int x, int y, int flags, void* ustc)
{
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		CvPoint pt = cvPoint(x, y);
		cout << pt.x << "," << pt.y << endl;
		conorpoints1.push_back(pt);
		if (conorpoints1.size() > 1) {
			handleImage(conorpoints1[0].x, conorpoints1[0].y, conorpoints1[1].x, conorpoints1[1].y, "01", "01");
		}
	}
}

bool __stdcall handleImage(int x1, int y1, int x2, int y2, const char* userId, const char* picId)
{
	string user_id = string(userId);
	string pic_id = string(picId);
	CvPoint pt1 = cvPoint(x1, y1);
	CvPoint pt2 = cvPoint(x2, y2);
	conorpoints.push_back(pt1);
	conorpoints.push_back(pt2);

	string path = "\\Image\\hsides\\" + user_id + "\\" + pic_id + "\\";
	string pfilename = path + "house.jpg";

	const char *filename = pfilename.c_str();
	IplImage* src0 = cvLoadImage(filename);
	IplImage* dst;
	IplImage* color_dst;
	IplImage* temp_dst;
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* orlines = 0;
	int i;

	if (!src0)
	{
		printf("Load image error!\n");
		return -1;
	}

	src = cvCreateImage(
		cvSize(1000, 1000 * src0->height / src0->width),
		src0->depth,
		src0->nChannels
	);
	sourcepic = cvCreateImage(
		cvSize(1000, 1000 * src0->height / src0->width),
		src0->depth,
		src0->nChannels
	);
	cvResize(src0, src);
	cvResize(src0, sourcepic);


	dst = cvCreateImage(cvGetSize(src), 8, 1);
	color_dst = cvCreateImage(cvGetSize(src), 8, 3);

	cvCanny(src, dst, 50, 200, 3);
	cvCvtColor(dst, color_dst, CV_GRAY2BGR);


	orlines = cvHoughLines2(dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI / 180, 50, 50, 5);

	vector<CvPoint*> lines;
	vector<vector<CvPoint*>> lines_three;
	for (int i = 0; i < orlines->total; i++)
	{
		CvPoint* line = (CvPoint*)cvGetSeqElem(orlines, i);
		lines.push_back(line);
	}

	for (int n = 0; n < 3; n++) {
		MyPoint vanishing_point = VanishingPoint(lines);
		vector<CvPoint*> lines_in;
		vanishing.push_back(vanishing_point);
		vector<CvPoint*> templines = lines;
		lines.clear();
		for (i = 0; i < templines.size(); i++)
		{
			CvPoint* line = templines[i];
			if (ifinline(vanishing_point, line))lines_in.push_back(line);
			else lines.push_back(line);
		}
		cout << lines.size() << endl;
		lines_three.push_back(lines_in);
	}

	return dividephoto(path);


}

bool dividephoto(string path)
{
	string htop = path + "htop.jpg";
	string hbottom = path + "hbottom.jpg";
	string hleft = path + "hleft.jpg";
	string hright = path + "hright.jpg";
	string hback = path + "hback.jpg";

	MyPoint pt1, pt2, pt3;
	vector<CvPoint> conors;
	int mark = 0;
	for (int i = 0; i < 3; i++)
	{
		if (vanishing[i].z == 0) {
			mark++;
			pt1 = vanishing[i];
		}
	}

	cout << "mark:" << mark << endl;

	CvPoint line1[2];
	CvPoint line2[2];
	CvPoint line3[2];
	CvPoint line4[2];

	conors.push_back(conorpoints[0]);

	if (mark == 1) {
		for (int j = 0; j < 3; j++)
		{
			if (vanishing[j].z == -1) {
				if (abs(vanishing[j].y) < 0.5)
					pt2 = vanishing[j];
				else pt3 = vanishing[j];
			}
		}

		line1[0] = conorpoints[0];
		line1[1].x = line1[0].x - pt2.x * 500;
		line1[1].y = line1[0].y - pt2.y * 500;

		line2[0] = conorpoints[1];
		line2[1].x = line2[0].x - pt3.x * 500;
		line2[1].y = line2[0].y - pt3.y * 500;

		line3[0] = conorpoints[1];
		line3[1].x = line3[0].x - pt2.x * 500;
		line3[1].y = line3[0].y - pt2.y * 500;

		line4[0] = conorpoints[0];
		line4[1].x = line4[0].x - pt3.x * 500;
		line4[1].y = line4[0].y - pt3.y * 500;
	}

	else if (mark == 2) {
		bool dir = true;
		pt1 = vanishing[0];
		pt2 = vanishing[1];
		pt3 = vanishing[2];
		if (pt1.z == -1) {
			pt2 = pt1;
			pt1 = vanishing[1];
		}
		else if (pt3.z == -1) {
			pt2 = pt3;
			pt3 = vanishing[1];
		}

		if (abs(pt2.y) < 0.5)
			dir = false;

		line1[0] = conorpoints[0];
		line2[0] = conorpoints[1];
		line3[0] = conorpoints[1];
		line4[0] = conorpoints[0];

		if (!dir) {

			if (abs(pt3.y - src->height / 2) < abs(pt1.y - src->height / 2)) {
				MyPoint temp = pt3;
				pt3 = pt1;
				pt1 = pt3;
			}

			line1[1].x = line1[0].x - pt2.x * 500;
			line1[1].y = line1[0].y - pt2.y * 500;


			line2[1].x = pt3.x;
			line2[1].y = pt3.y;


			line3[1].x = line3[0].x - pt2.x * 500;
			line3[1].y = line3[0].y - pt2.y * 500;


			line4[1].x = pt3.x;
			line4[1].y = pt3.y;
		}
		else {

			if (abs(pt3.x - 500) < abs(pt1.x - 500)) {
				MyPoint temp = pt3;
				pt3 = pt1;
				pt1 = pt3;
			}

			line1[1].x = pt3.x;
			line1[1].y = pt3.y;


			line2[1].x = line2[0].x - pt2.x * 500;
			line2[1].y = line2[0].y - pt2.y * 500;


			line3[1].x = pt3.x;
			line3[1].y = pt3.y;


			line4[1].x = line4[0].x - pt2.x * 500;
			line4[1].y = line4[0].y - pt2.y * 500;
		}
	}

	else if (mark == 3) {

		pt1 = vanishing[0];
		pt2 = vanishing[1];
		pt3 = vanishing[2];

		if (abs(pt3.x - 500) > abs(pt1.x - 500)) {
			if (abs(pt3.x - 500) < abs(pt2.x - 500)) {
				pt3 = pt2;
				pt2 = vanishing[2];
			}
		}
		else {
			if (abs(pt1.x - 500) < abs(pt2.x - 500)) {
				pt3 = pt2;
				pt2 = vanishing[2];
			}
			else {
				pt3 = pt1;
				pt1 = vanishing[2];
			}
		}

		if (abs(pt1.y - src->height / 2) > abs(pt2.y - src->height / 2)) {
			MyPoint temp = pt1;
			pt1 = pt2;
			pt2 = temp;
		}

		line1[0] = conorpoints[0];
		line2[0] = conorpoints[1];
		line3[0] = conorpoints[1];
		line4[0] = conorpoints[0];

		line1[1].x = pt3.x;
		line1[1].y = pt3.y;

		line2[1].x = pt2.x;
		line2[1].y = pt2.y;

		line3[1].x = pt3.x;
		line3[1].y = pt3.y;

		line4[1].x = pt2.x;
		line4[1].y = pt2.y;

	}

	else return false;



	MyPoint tppt1 = CrossPoint(line1, line2);
	CvPoint tpt1;
	tpt1.x = tppt1.x;
	tpt1.y = tppt1.y;
	MyPoint tppt2 = CrossPoint(line3, line4);
	CvPoint tpt2;
	tpt2.x = tppt2.x;
	tpt2.y = tppt2.y;
	conors.push_back(tpt1);
	conors.push_back(conorpoints[1]);
	conors.push_back(tpt2);

	CvPoint line5[2];
	line5[0].x = pt1.x;
	line5[0].y = pt1.y;
	line5[1] = conors[0];
	CvPoint line6[2];
	line6[0].x = pt1.x;
	line6[0].y = pt1.y;
	line6[1] = conors[1];
	CvPoint line7[2];
	line7[0].x = pt1.x;
	line7[0].y = pt1.y;
	line7[1] = conors[2];
	CvPoint line8[2];
	line8[0].x = pt1.x;
	line8[0].y = pt1.y;
	line8[1] = conors[3];

	CvPoint line9[2];
	line9[0].x = 0;
	line9[0].y = 0;
	line9[1].x = 0;
	line9[1].y = 500;
	CvPoint line10[2];
	line10[0].x = 0;
	line10[0].y = 0;
	line10[1].x = 1000;
	line10[1].y = 0;
	CvPoint line11[2];
	line11[0].x = 1000;
	line11[0].y = 0;
	line11[1].x = 1000;
	line11[1].y = 500;
	CvPoint line12[2];
	line12[0].x = 0;
	line12[0].y = src->height;
	line12[1].x = 1000;
	line12[1].y = src->height;

	MyPoint tppt3 = CrossPoint(line5, line9);
	if (tppt3.y < 0)tppt3 = CrossPoint(line5, line10);
	CvPoint tpt3;
	tpt3.x = tppt3.x;
	tpt3.y = tppt3.y;
	MyPoint tppt4 = CrossPoint(line6, line11);
	if (tppt4.y<0)tppt4 = CrossPoint(line6, line10);
	CvPoint tpt4;
	tpt4.x = tppt4.x;
	tpt4.y = tppt4.y;
	MyPoint tppt5 = CrossPoint(line7, line11);
	if (tppt5.y>src->height)tppt5 = CrossPoint(line7, line12);
	CvPoint tpt5;
	tpt5.x = tppt5.x;
	tpt5.y = tppt5.y;
	MyPoint tppt6 = CrossPoint(line8, line9);
	if (tppt6.y > src->height)tppt6 = CrossPoint(line8, line12);
	CvPoint tpt6;
	tpt6.x = tppt6.x;
	tpt6.y = tppt6.y;

	conors.push_back(tpt3);
	conors.push_back(tpt4);
	conors.push_back(tpt5);
	conors.push_back(tpt6);

	for (int k = 0; k < conors.size(); k++) {
		cvCircle(src, conors[k], 5, CV_RGB(255, 0, 0));
	}
	cvShowImage("PointSelect", src);

	int width = sqrt((conors[1].x - conors[0].x)*(conors[1].x - conors[0].x) + (conors[1].y - conors[0].y)*(conors[1].y - conors[0].y));
	int height = sqrt((conors[1].x - conors[2].x)*(conors[1].x - conors[2].x) + (conors[1].y - conors[2].y)*(conors[1].y - conors[2].y));

	CvPoint2D32f points1_1[4];
	CvPoint2D32f points2_1[4];
	CvPoint2D32f points3_1[4];
	CvPoint2D32f points4_1[4];
	CvPoint2D32f points5_1[4];
	CvPoint2D32f points1_2[4];
	CvPoint2D32f points2_2[4];
	CvPoint2D32f points3_2[4];
	CvPoint2D32f points4_2[4];
	CvPoint2D32f points5_2[4];

	//back
	CvPoint2D32f cpt1_1;
	cpt1_1.x = conors[0].x;
	cpt1_1.y = conors[0].y;
	CvPoint2D32f cpt2_1;
	cpt2_1.x = conors[1].x;
	cpt2_1.y = conors[1].y;
	CvPoint2D32f cpt3_1;
	cpt3_1.x = conors[2].x;
	cpt3_1.y = conors[2].y;
	CvPoint2D32f cpt4_1;
	cpt4_1.x = conors[3].x;
	cpt4_1.y = conors[3].y;

	points1_1[0] = cpt1_1;
	points1_1[1] = cpt2_1;
	points1_1[2] = cpt3_1;
	points1_1[3] = cpt4_1;

	CvPoint2D32f cpt1; cpt1.x = 0; cpt1.y = 0;
	CvPoint2D32f cpt2; cpt2.x = width; cpt2.y = 0;
	CvPoint2D32f cpt3; cpt3.x = width; cpt3.y = height;
	CvPoint2D32f cpt4; cpt4.x = 0; cpt4.y = height;

	points1_2[0] = cpt1;
	points1_2[1] = cpt2;
	points1_2[2] = cpt3;
	points1_2[3] = cpt4;

	CvMat* h1 = cvCreateMat(3, 3, CV_32FC1);
	cvGetPerspectiveTransform(points1_1, points1_2, h1);
	IplImage* dst1 = cvCreateImage(
		cvSize(src->width, src->height),
		src->depth,
		src->nChannels
	);
	cvWarpPerspective(sourcepic, dst1, h1);

	CvSize size1 = cvSize(width, height);
	cvSetImageROI(dst1, cvRect(0, 0, size1.width, size1.height));
	IplImage* pDest1 = cvCreateImage(size1, dst1->depth, dst1->nChannels);
	cvCopy(dst1, pDest1);
	cvResetImageROI(pDest1);
	cvSaveImage(hback.c_str(), pDest1);

	//distance
	int d1 = sqrt((conors[4].x - conors[0].x)*(conors[4].x - conors[0].x) + (conors[4].y - conors[0].y)*(conors[4].y - conors[0].y));
	int d2 = sqrt((conors[3].x - conors[7].x)*(conors[3].x - conors[7].x) + (conors[3].y - conors[7].y)*(conors[3].y - conors[7].y));
	int d3 = sqrt((conors[1].x - conors[5].x)*(conors[1].x - conors[5].x) + (conors[1].y - conors[5].y)*(conors[1].y - conors[5].y));
	int d4 = sqrt((conors[2].x - conors[6].x)*(conors[2].x - conors[6].x) + (conors[2].y - conors[6].y)*(conors[2].y - conors[6].y));
	int d12 = d1;
	if (d2 > d1)d12 = d2;
	int d13 = d1;
	if (d3 > d1)d13 = d3;
	int d24 = d2;
	if (d4 > d2)d24 = d4;
	int d34 = d3;
	if (d4 > d3)d34 = d4;

	//left
	CvPoint2D32f cpt5_1; cpt5_1.x = conors[4].x; cpt5_1.y = conors[4].y;
	CvPoint2D32f cpt6_1; cpt6_1.x = conors[0].x; cpt6_1.y = conors[0].y;
	CvPoint2D32f cpt7_1; cpt7_1.x = conors[3].x; cpt7_1.y = conors[3].y;
	CvPoint2D32f cpt8_1; cpt8_1.x = conors[7].x; cpt8_1.y = conors[7].y;

	points2_1[0] = cpt5_1;
	points2_1[1] = cpt6_1;
	points2_1[2] = cpt7_1;
	points2_1[3] = cpt8_1;


	CvPoint2D32f cpt5; cpt5.x = d12 - d1; cpt5.y = 0;
	CvPoint2D32f cpt6; cpt6.x = d12; cpt6.y = 0;
	CvPoint2D32f cpt7; cpt7.x = d12; cpt7.y = height;
	CvPoint2D32f cpt8; cpt8.x = d12 - d2; cpt8.y = height;

	points2_2[0] = cpt5;
	points2_2[1] = cpt6;
	points2_2[2] = cpt7;
	points2_2[3] = cpt8;

	CvMat* h2 = cvCreateMat(3, 3, CV_32FC1);
	cvGetPerspectiveTransform(points2_1, points2_2, h2);
	IplImage* dst2 = cvCreateImage(
		cvSize(src->width, src->height),
		src->depth,
		src->nChannels
	);
	cvWarpPerspective(sourcepic, dst2, h2);

	if (d12 > src->width)d12 = src->width;
	CvSize size2 = cvSize(d12, height);
	cvSetImageROI(dst2, cvRect(0, 0, size2.width, size2.height));
	IplImage* pDest2 = cvCreateImage(size2, dst2->depth, dst2->nChannels);
	cvCopy(dst2, pDest2);
	cvResetImageROI(pDest2);
	cvSaveImage(hleft.c_str(), pDest2);

	//top
	CvPoint2D32f cpt9_1;
	cpt9_1.x = conors[4].x;
	cpt9_1.y = conors[4].y;
	CvPoint2D32f cpt10_1;
	cpt10_1.x = conors[5].x;
	cpt10_1.y = conors[5].y;
	CvPoint2D32f cpt11_1;
	cpt11_1.x = conors[1].x;
	cpt11_1.y = conors[1].y;
	CvPoint2D32f cpt12_1;
	cpt12_1.x = conors[0].x;
	cpt12_1.y = conors[0].y;

	points3_1[0] = cpt9_1;
	points3_1[1] = cpt10_1;
	points3_1[2] = cpt11_1;
	points3_1[3] = cpt12_1;

	CvPoint2D32f cpt9; cpt9.x = 0; cpt9.y = d13 - d1;
	CvPoint2D32f cpt10; cpt10.x = width; cpt10.y = d13 - d3;
	CvPoint2D32f cpt11; cpt11.x = width; cpt11.y = d13;
	CvPoint2D32f cpt12; cpt12.x = 0; cpt12.y = d13;

	points3_2[0] = cpt9;
	points3_2[1] = cpt10;
	points3_2[2] = cpt11;
	points3_2[3] = cpt12;

	CvMat* h3 = cvCreateMat(3, 3, CV_32FC1);
	cvGetPerspectiveTransform(points3_1, points3_2, h3);
	IplImage* dst3 = cvCreateImage(
		cvSize(src->width, src->height),
		src->depth,
		src->nChannels
	);
	cvWarpPerspective(sourcepic, dst3, h3);

	if (d13 > src->height)d13 = src->height;
	CvSize size3 = cvSize(width, d13);
	cvSetImageROI(dst3, cvRect(0, 0, size3.width, size3.height));
	IplImage* pDest3 = cvCreateImage(size3, dst3->depth, dst3->nChannels);
	cvCopy(dst3, pDest3);
	cvResetImageROI(pDest3);
	cvSaveImage(htop.c_str(), pDest3);

	//right
	CvPoint2D32f cpt13_1;
	cpt13_1.x = conors[1].x;
	cpt13_1.y = conors[1].y;
	CvPoint2D32f cpt14_1;
	cpt14_1.x = conors[5].x;
	cpt14_1.y = conors[5].y;
	CvPoint2D32f cpt15_1;
	cpt15_1.x = conors[6].x;
	cpt15_1.y = conors[6].y;
	CvPoint2D32f cpt16_1;
	cpt16_1.x = conors[2].x;
	cpt16_1.y = conors[2].y;

	points4_1[0] = cpt13_1;
	points4_1[1] = cpt14_1;
	points4_1[2] = cpt15_1;
	points4_1[3] = cpt16_1;

	CvPoint2D32f cpt13; cpt13.x = 0; cpt13.y = 0;
	CvPoint2D32f cpt14; cpt14.x = d3; cpt14.y = 0;
	CvPoint2D32f cpt15; cpt15.x = d4; cpt15.y = height;
	CvPoint2D32f cpt16; cpt16.x = 0; cpt16.y = height;

	points4_2[0] = cpt13;
	points4_2[1] = cpt14;
	points4_2[2] = cpt15;
	points4_2[3] = cpt16;

	CvMat* h4 = cvCreateMat(3, 3, CV_32FC1);
	cvGetPerspectiveTransform(points4_1, points4_2, h4);
	IplImage* dst4 = cvCreateImage(
		cvSize(src->width, src->height),
		src->depth,
		src->nChannels
	);
	cvWarpPerspective(sourcepic, dst4, h4);

	if (d34 > src->width)d34 = src->width;
	CvSize size4 = cvSize(d34, height);
	cvSetImageROI(dst4, cvRect(0, 0, size4.width, size4.height));
	IplImage* pDest4 = cvCreateImage(size4, dst4->depth, dst4->nChannels);
	cvCopy(dst4, pDest4);
	cvResetImageROI(pDest4);
	cvSaveImage(hright.c_str(), pDest4);

	//bottom
	CvPoint2D32f cpt17_1;
	cpt17_1.x = conors[3].x;
	cpt17_1.y = conors[3].y;
	CvPoint2D32f cpt18_1;
	cpt18_1.x = conors[2].x;
	cpt18_1.y = conors[2].y;
	CvPoint2D32f cpt19_1;
	cpt19_1.x = conors[6].x;
	cpt19_1.y = conors[6].y;
	CvPoint2D32f cpt20_1;
	cpt20_1.x = conors[7].x;
	cpt20_1.y = conors[7].y;

	points5_1[0] = cpt17_1;
	points5_1[1] = cpt18_1;
	points5_1[2] = cpt19_1;
	points5_1[3] = cpt20_1;

	CvPoint2D32f cpt17; cpt17.x = 0; cpt17.y = 0;
	CvPoint2D32f cpt18; cpt18.x = width; cpt18.y = 0;
	CvPoint2D32f cpt19; cpt19.x = width; cpt19.y = d4;
	CvPoint2D32f cpt20; cpt20.x = 0; cpt20.y = d2;

	points5_2[0] = cpt17;
	points5_2[1] = cpt18;
	points5_2[2] = cpt19;
	points5_2[3] = cpt20;

	CvMat* h5 = cvCreateMat(3, 3, CV_32FC1);
	cvGetPerspectiveTransform(points5_1, points5_2, h5);
	IplImage* dst5 = cvCreateImage(
		cvSize(src->width, src->height),
		src->depth,
		src->nChannels
	);
	cvWarpPerspective(sourcepic, dst5, h5);

	if (d24 > src->height)d24 = src->height;
	CvSize size5 = cvSize(width, d24);
	cvSetImageROI(dst5, cvRect(0, 0, size5.width, size5.height));
	IplImage* pDest5 = cvCreateImage(size5, dst5->depth, dst5->nChannels);
	cvCopy(dst5, pDest5);
	cvResetImageROI(pDest5);
	cvSaveImage(hbottom.c_str(), pDest5);

	return true;

}

MyPoint VanishingPoint(vector<CvPoint*> &lines)
{
	vector<MyPoint> points;
	vector<Pair> count;
	for (int i = 0; i < lines.size(); i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			CvPoint* line1 = lines[i];
			CvPoint* line2 = lines[j];
			MyPoint pt = CrossPoint(line1, line2);
			bool mark = true;
			if (pt.z == 0) {
				for (int k = 0; k < points.size(); k++) {
					if (points[k].z == 0 && pt.x != -1 && pt.y != -1
						&& points[k].x < pt.x + 20 && points[k].x > pt.x - 20
						&& points[k].y < pt.y + 15 && points[k].y > pt.y - 15) {
						count[k].num++;
						mark = false;
						break;
					}
				}
			}
			else if (pt.z == -1) {
				for (int k = 0; k < points.size(); k++) {
					if (points[k].z == -1 && ((points[k].x == pt.x  && points[k].y == pt.y)
						|| (points[k].x == -pt.x && points[k].y == -pt.y))) {
						count[k].num += 1;
						mark = false;
						break;
					}
				}
			}
			if (mark) {
				points.push_back(pt);
				Pair pair;
				pair.index = points.size() - 1;
				pair.num = 1;
				count.push_back(pair);
			}
		}
	}

	printf("points:%d\n", points.size());
	sort(count.begin(), count.end(), pointsort);

	return points[count[0].index];

}

bool ifinline(MyPoint pt, CvPoint *line)
{
	bool result = true;
	double x = line[0].x - line[1].x;
	double y = line[0].y - line[1].y;
	if (pt.z == 0) {
		double x1 = pt.x - line[1].x;
		double y1 = pt.y - line[1].y;
		double x2 = pt.x - line[0].x;
		double y2 = pt.y - line[0].y;
		double a1 = (x1*x + y*y1) / (sqrt(x*x + y*y)*sqrt(x1*x1 + y1*y1));
		double a2 = (x2*x + y*y2) / (sqrt(x*x + y*y)*sqrt(x2*x2 + y2*y2));
		double da = a1 - a2;
		if (da>0.001 || da<-0.001)
			result = false;
	}
	else if (pt.z == -1)
	{
		double d = pt.x*y - pt.y*x;
		if (d<-10 || d> 10)
			result = false;
	}
	return result;
}

MyPoint CrossPoint(const CvPoint* line1, const CvPoint* line2)
{
	MyPoint pt;
	pt.x = -1;
	pt.y = -1;
	pt.z = 0;
	// line1's cpmponent  
	double X1 = line1[1].x - line1[0].x;//b1  
	double Y1 = line1[1].y - line1[0].y;//a1  
										// line2's cpmponent  
	double X2 = line2[1].x - line2[0].x;//b2  
	double Y2 = line2[1].y - line2[0].y;//a2  
										// distance of 1,2  
	double X21 = line2[0].x - line1[0].x;
	double Y21 = line2[0].y - line1[0].y;
	// determinant  
	double D = Y1*X2 - Y2*X1;// a1b2-a2b1  
							 //
	pt.weight = sqrt(X1*X1 + Y1*Y1)*sqrt(X2*X2 + Y2*Y2) / 1000;
	if (D <10 && D>-10) {
		double d = sqrt(X1*X1 + Y1*Y1);
		pt.x = X1 / d;
		pt.y = Y1 / d;
		pt.z = -1;
		return pt;
	}
	// cross point  
	pt.x = (X1*X2*Y21 + Y1*X2*line1[0].x - Y2*X1*line2[0].x) / D;
	// on screen y is down increased !   
	pt.y = -(Y1*Y2*X21 + X1*Y2*line1[0].y - X2*Y1*line2[0].y) / D;
	// segments intersect.  
	if ((abs(pt.x - line1[0].x - X1 / 2) <= abs(X1 / 2)) &&
		(abs(pt.y - line1[0].y - Y1 / 2) <= abs(Y1 / 2)) &&
		(abs(pt.x - line2[0].x - X2 / 2) <= abs(X2 / 2)) &&
		(abs(pt.y - line2[0].y - Y2 / 2) <= abs(Y2 / 2)))
	{
		return pt;
	}
	return pt;
}


