#include "ffmpeg.hpp"
#include <iostream>

using namespace std;

FFmpeg::FFmpeg()
{
	outUrl = NULL;
	vsc = NULL;
	yuv = NULL;
	vc = NULL;
	ic = NULL;
	//注册所有编码解码器
	avcodec_register_all();
	//注册所有封装器
	av_register_all();
	//注册所有网络协议
	avformat_network_init();
}

void FFmpeg::set_swscontext(int inWidth, int inHeight, int outWidth, int outHeight, enum AVPixelFormat srcFormat,enum AVPixelFormat dstFormat)
{
	//初始化格式转换上下文
	vsc = sws_getCachedContext(vsc,
			inWidth, inHeight, srcFormat,	//源宽，高，像素格式
			outWidth, outHeight, dstFormat,	//目标源宽高，像素格式
			SWS_BICUBIC,	//尺寸变化使用算法
			0, 0, 0
			);
	if(!vsc)
	{
		std::cout << "swscontext failed!" << std::endl;
		return;
	}
}


void FFmpeg::set_output(enum AVPixelFormat dstFormat, int outWidth, int outHeight, int pts, int buffsize)
{
	//初始化输出数据结构
	yuv = av_frame_alloc();
	yuv->format = dstFormat;
	yuv->width = outWidth;
	yuv->height = outHeight;
	yuv->pts = pts;
	//分配yuv空间
	int ret = av_frame_get_buffer(yuv, buffsize);
	if(ret != 0)
	{
		char buf[1024] = {0};
		av_strerror(ret, buf, sizeof(buf) - 1);
		std::cout << buf << std::endl;
	}
}


