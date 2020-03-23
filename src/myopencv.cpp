#include "myopencv.hpp"

Camera::Camera()
{
}

bool Camera::opencam(int cameraid)
{
	this->cam.open(cameraid);
	if(!cam.isOpened())
	{
		cout <<  "cam open err" << endl;
		return false;
	}
	return true;
}

int Camera::getcamwidth()
{
        inWidth = cam.get(cv::CAP_PROP_FRAME_WIDTH);
        return inWidth;
}

int Camera::getcamheight()
{
        inHeight = cam.get(cv::CAP_PROP_FRAME_HEIGHT);
        return inHeight;
}

int Camera::getcamfps()
{
        fps = cam.get(cv::CAP_PROP_FPS);
        return fps;
}

void Camera::show()
{
	cv::imshow("video",frame);
	cv::waitKey(20);
}

void Camera::read()
{
	cam >> frame;
}


