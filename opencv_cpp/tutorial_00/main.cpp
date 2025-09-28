#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img(200, 200, CV_8UC3, cv::Scalar(0,255,0));
    if(img.empty()) {
        std::cerr << "Error: OpenCV not working!" << std::endl;
        return -1;
    }
    std::cout << "OpenCV is working! Version: " << CV_VERSION << std::endl;
    return 0;
}
