//
// Created by 赵磊 on 2017/2/9.
//

#include "SnapImage.h"
using namespace cv;
SnapImage::SnapImage(const std::string &inputFile,const std::string &outFileBase) {
    winName = "Capture";
    writeFileNo = 0;
    inputVideoFilePath = inputFile;
    outFileNameBase = outFileBase;
    framecountVideo = 0;
    fpsVideo = 0;
    widthVideo = heightVideo = 0;
}

void SnapImage::Init() {
    captureVideo.open(inputVideoFilePath);
    if (captureVideo.isOpened())
    {
        widthVideo = captureVideo.get(CV_CAP_PROP_FRAME_WIDTH);
        heightVideo = captureVideo.get(CV_CAP_PROP_FRAME_HEIGHT);
        framecountVideo = captureVideo.get(CV_CAP_PROP_FRAME_COUNT);
        fpsVideo = captureVideo.get(CV_CAP_PROP_FPS);

    }
}

void SnapImage::Run() {

    if (captureVideo.isOpened())
    {
        int waitTime = (int)(1000.0f / fpsVideo);
        int frameIndex = 0;
        while (frameIndex < framecountVideo)
        {
            captureVideo.read(matFrame);
            imshow(winName,matFrame);
            frameIndex++;
            int key = waitKey(waitTime);
            if (key == ' ')
            {
                std::string outname = genOutFileName();
                imwrite(outname,matFrame);
            }
        }
    }
}

std::string SnapImage::genOutFileName() {
    writeFileNo++;
    char szBuf[128];
    snprintf(szBuf,128,"%s_%03d.png",outFileNameBase.c_str(),writeFileNo);
    return szBuf;
}


int main(int argc, char *argv[])
{
    SnapImage snapImage("back.mp4","out");
    snapImage.Init();
    snapImage.Run();
    return 0;
}