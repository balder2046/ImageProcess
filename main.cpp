#include <iostream>
#include "DrawUtils.h"
#include "GradientShow.h"
using namespace cv;
int main() {
    GradientShow show("gradient");
    show.Init();
    show.Run();
    return 0;

}