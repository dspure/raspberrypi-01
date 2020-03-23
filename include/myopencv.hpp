#pragma once

#include <iostream>
#include <highgui.hpp>
//#include "ffmpeg.hpp"

using namespace std;

class Camera
{
	public:
		cv::VideoCapture cam;
		cv::Mat frame;
		int inWidth;
		int inHeight;
		int fps;
	public:
		Camera();
		bool opencam(int cameraid); //打开相机
		int getcamwidth(); //获取图像宽度
		int getcamheight(); //获取图像高度
		int getcamfps(); //获取图像fps
		void show();	//显示帧图像
		void read();	//读取帧图像
};
