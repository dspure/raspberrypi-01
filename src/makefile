#bin/bash

OBJ_DIR = ../obj
SRC_DIR = .
INC_DIR = ../include
BIN_DIR = .

TARGET = main

CPP = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst %.cpp,%.o,$(CPP))
BIN_TARGET = $(BIN_DIR)/$(TARGET)

LINK = -I /usr/local/include/opencv4  \
                -I /usr/local/include/opencv4/opencv2 \
		-I $(INC_DIR) \
                -L /usr/local/lib \
		-L /usr/lib/arm-linux-gnueabihf/ \
                -l opencv_calib3d \
                -l opencv_core \
                -l opencv_dnn \
                -l opencv_features2d \
                -l opencv_flann \
                -l opencv_gapi \
                -l opencv_highgui \
                -l opencv_imgcodecs \
                -l opencv_imgproc \
                -l opencv_ml \
                -l opencv_objdetect \
                -l opencv_photo \
                -l opencv_stitching \
                -l opencv_video \
                -l opencv_videoio \
		-l swscale \
                -l swresample \
                -l avcodec \
                -l avformat \
                -l avutil \
                -l pthread

CFLAGS = -o

$(BIN_TARGET):$(OBJ)
	g++ $(CFLAGS) $@ $^ $(LINK)
	mv $(SRC_DIR)/*.o $(OBJ_DIR)

%.o:%.cpp
	g++ $(CFLAGS) $@ -c $< $(LINK)

.PHONY:clean

clean:
	rm $(OBJ_DIR)/*.o $(BIN_TARGET)


