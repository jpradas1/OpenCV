#include <iostream>
#include <opencv2/highgui.hpp>

int main()
{
    // LOAD LENNA IMAGE
    cv::Mat img = cv::imread("./Lenna.png", cv::IMREAD_GRAYSCALE);

    // SHOW LENNA IMAGE
    cv::imshow("Window", img);
    cv::waitKey(0);

    return 0;
}