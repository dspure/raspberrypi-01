#pragma once

#include <iostream>

extern "C"
{
//#include <libavutil/channel_layout> //用户音频声道布局操作
//#include <libavutil/opt.h> //设置选项操作
//#include <libavutil/mathematics.h> //用于数学相关操作
#include <libavutil/timestamp.h> //用于时间戳操作
#include <libswscale/swscale.h> //用于缩放、转换颜色格式操作
#include <libavcodec/avcodec.h> //编码解码操作
//#include <libswscale/swresample.h> //音频采样频率操作
#include <libavformat/avformat.h> //用于封装与解封装操作
}

class FengZhuang
{
	public:
		std::string Outurl;
		AVFormatContext *ic; //rtmp flv 封装器配置类
		AVStream *vs;
	public:
		FengZhuang(std::string outurl); //注册所有封装器
		void fengzhuanginit(AVCodecContext *vc); //初始化封装器配置类
		void writeheader(); //写入封装头
};

class BianMa
{
	public:
		AVCodecContext *vc; //编码器配置类
		AVCodec *codec; //编码器类
	public:
		BianMa(); //注册所有解码编码器
		void inith264(); //初始化编码器
		void seth264(int width, int height, int fps); //设置编码器
};

class NetWork
{
	public:
		NetWork(); //注册所有网络
		void opennetio(AVFormatContext *ic, std::string &outurl);
};

class OutPut
{
	AVFrame *yuv; //输出配置类
	public:
		OutPut();
};
