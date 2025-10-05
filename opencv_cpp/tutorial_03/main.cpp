#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
    cv::Mat img = cv::imread("./binary.png", cv::IMREAD_COLOR);
    cv::threshold(img, img, 125, 255, cv::THRESH_BINARY);

    // int size = 3;
    int size = 2;
    cv::Mat erodedImg, dilatedImg;
    cv::Mat elementKernel = cv::getStructuringElement(
        cv::MORPH_RECT, cv::Size(size,size), cv::Point(-1,-1)
    );

    cv::erode(img, erodedImg, elementKernel, cv::Point(-1,-1), 1);
    // cv::dilate(img, dilatedImg, elementKernel, cv::Point(-1,-1), 1);
    cv::dilate(erodedImg, dilatedImg, elementKernel, cv::Point(-1,-1), 1);

    // cv::imwrite("./../images/tutorial_03/00.png", img);
    // cv::imwrite("./../images/tutorial_03/01.png", erodedImg);
    // cv::imwrite("./../images/tutorial_03/02.png", dilatedImg);
    cv::imwrite("./../images/tutorial_03/03.png", erodedImg);
    cv::imwrite("./../images/tutorial_03/04.png", dilatedImg);

    cv::imshow("Input Image", img);
    cv::imshow("Erode Filter", erodedImg);
    cv::imshow("Dilate Filter", dilatedImg);
    cv::waitKey(0);

    return 0;
}