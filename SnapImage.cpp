//
// Created by 赵磊 on 2017/2/9.
//

#include "SnapImage.h"
#include <boost/program_options.hpp>
using namespace cv;
namespace po = boost::program_options;
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
            } else if (key == 27) {
                break;
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

int main(int argc, const char *argv[])
{
    po::options_description description("Usage: SnapImage -i <input video> -o <out base name>");
    description.add_options()("input,i", po::value<std::string>(), "input video");
    description.add_options()("output,o", po::value<std::string>(), "output picture's filename base");
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, description), vm);
    po::notify(vm);
    std::string inputfilename;
    std::string basename;
    if (vm.count("input")) {
        inputfilename = vm["input"].as<std::string>();
    } else {
        std::cout << description;
        return 1;
    }
    if (vm.count("output")) {
        basename = vm["output"].as<std::string>();
    } else {
        std::cout << description;
        return 1;
    }


    SnapImage snapImage(inputfilename, basename);
    snapImage.Init();
    snapImage.Run();
    return 0;
}