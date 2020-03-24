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

#include <string.h>

class FFmpeg
{
	public:
		//输出Url
		char *outUrl;
		//像素格式转换上下文
		SwsContext *vsc;
		//输出数据结构
		AVFrame *yuv;
		//编码器上下文
		AVCodecContext *vc;
		//rtmp flv 封装器
		AVFormatContext *ic;
	public:
		FFmpeg();
		void set_swscontext(int inWidth, int inHeight, int outWidth, int outHeight, enum AVPixelFormat srcFormat, enum AVPixelFormat dstFormat); //像素输入输出格式转换配置
		void set_output(enum AVPixelFormat dstFormat, int outWidth, int outHeight, int pts, int buffsize); //输出器配置
};



