#include <ffmpeg.hpp>
#include <iostream>

using namespace std;

FengZhuang::FengZhuang(std::string outurl)
{
	//注册所有封装器
	av_register_all();
	
	ic = NULL;

	vs = NULL;

	Outurl = outurl;
}

void FengZhuang::fengzhuanginit(AVCodecContext *vc)
{
	//创建封装其配置类
	int ret = avformat_alloc_output_context2(&ic,0,"flv",Outurl.c_str());
	if(ret != 0)
	{
		char buf[1024] = {0};
		av_strerror(ret, buf, sizeof(buf) - 1);
		std::cout << buf << std::endl;
		return;
	}
	//添加视频流
	vs = avformat_new_stream(ic,NULL);
	if(!vs)
	{
		std::cout << "add stream faild!" << std::endl;
		return;
	}
	vs->codecpar->codec_tag = 0;
	//从编码器复制参数
	avcodec_parameters_from_context(vs->codecpar, vc);
	av_dump_format(ic,0,Outurl.c_str(),1);
}

void FengZhuang::writeheader()
{
	int ret = avformat_write_header(ic,NULL);
	if(ret != 0)
	{
		char buf[1024] = {0};
		av_strerror(ret, buf, sizeof(buf) - 1);
		std::cout << buf << std::endl;
		return;
	}
}


BianMa::BianMa()
{
	//注册所有编码器
	avcodec_register_all();
	vc = NULL;
	codec = NULL;
}

void BianMa::inith264()
{
	codec = avcodec_find_encoder(AV_CODEC_ID_H264);
	if(!codec)
	{
		std::cout << "Can`t find h264 encoder!" << std::endl;
	}
}

void BianMa::seth264(int width, int height, int fps)
{
	vc = avcodec_alloc_context3(codec);
	if(!vc)
	{
		std::cout << "set h264 faild!" << std::endl;
		return;
	}
	//配置参数
	vc->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;//全局参数
	vc->codec_id = codec->id;
	vc->thread_count = 8;

	vc->bit_rate = 50*1024*8; //压缩后每秒视频的bit位大小 50KB
	vc->width = width;
	vc->height = height;
	vc->time_base = {1,fps};
	vc->framerate = {fps,1};

	//画面组大小，多少帧一个关键帧
	vc->gop_size = 50;
	vc->max_b_frames = 0;
	vc->pix_fmt = AV_PIX_FMT_YUV420P;

	//根据配置类配置编码器
	int ret = avcodec_open2(vc,0,0);
	if(ret != 0)
	{
		char buf[1024] = {0};
		av_strerror(ret,buf,sizeof(buf)-1);
		std::cout << buf << std::endl;
		return;
	}
}


NetWork::NetWork()
{
	//注册所有网络协议
	avformat_network_init();
}

void NetWork::opennetio(AVFormatContext *ic, std::string &outurl)
{
	int ret = avio_open(&ic->pb, outurl.c_str(), AVIO_FLAG_WRITE);
	if(ret != 0)
	{
		char buf[1024] = {0};
		av_strerror(ret, buf, sizeof(buf) - 1);
		std::cout << buf << std::endl;
		return;
	}
}


OutPut::OutPut()
{
}

