#pragma once

#include <iostream>
#include <highgui.hpp>
#include "ffmpeg.hpp"

using namespace std;

class Camera
{
	public:
		cv::VideoCapture cam;
		cv::Mat frame;
		int inWidth;	//图像宽度
		int inHeight;	//图像高度
		int fps;	//图像FPS
	public:
		Camera();
		bool opencam(int cameraid); //打开相机
		int getcamwidth(); //获取图像宽度
		int getcamheight(); //获取图像高度
		int getcamfps(); //获取图像fps
		void show();	//显示帧图像
		cv::Mat read();	//读取帧图像
};
