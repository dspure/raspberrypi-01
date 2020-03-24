#include <iostream>
#include "ffmpeg.hpp"
#include "myopencv.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Camera cam = Camera();
	FFmpeg mypeg = FFmpeg();
	cam.opencam(0);//打开相机
	mypeg.set_swscontext(cam.getcamwidth(), cam.getcamheight(), cam.getcamwidth(), cam.getcamheight(), AV_PIX_FMT_BGR24, AV_PIX_FMT_YUV420P);//设置格式转换上下文
	mypeg.set_output(AV_PIX_FMT_YUV420P, cam.getcamwidth(), cam.getcamheight(), 0, 32);
}
