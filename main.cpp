#include <iostream>
#include "DrawUtils.h"
#include "GradientShow.h"
#include "boost/program_options.hpp"

namespace po = boost::program_options;
using namespace cv;

int main(int argc, const char *argv[]) {
    po::options_description desp("Usage: ImageProcess <inputimage>");
    desp.add_options()("inputimage,i", po::value<std::string>());
    po::positional_options_description pos;
    pos.add("inputimage", 1);
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desp).positional(pos).run(), vm);
    po::notify(vm);
    std::string inputfilename;
    if (vm.count("inputimage")) {
        inputfilename = vm["inputimage"].as<std::string>();
    } else {
        std::cout << desp;
        return 1;
    }
    GradientShow show("gradient", inputfilename);
    show.Init();
    show.Run();
    return 0;

}