#include <iostream>
#include "ffmpeg.hpp"
#include "myopencv.hpp"

using namespace std;

int main()
{
	Camera mycamera();
	mycamera.opencam(0);
	while(1)
	{
		mycamera.read();
		mycamera.show();
	}
	return 0;
}
