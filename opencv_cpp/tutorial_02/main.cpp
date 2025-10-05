#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
    cv::Mat img = cv::imread("./pool.jpg", cv::IMREAD_COLOR);

    // PROCESSING IMAGE
    cv::Mat bilateralImg, gaussianImg, medianImg;

    cv::bilateralFilter(img, bilateralImg, 15, 95, 45);
    cv::GaussianBlur(img, gaussianImg, cv::Size(15,15), 0);
    cv::medianBlur(img, medianImg, 15);

    // SAVE IMAGE
    cv::imwrite("./../images/tutorial_02/00.jpg", img);
    cv::imwrite("./../images/tutorial_02/01.jpg", bilateralImg);
    cv::imwrite("./../images/tutorial_02/02.jpg", gaussianImg);
    cv::imwrite("./../images/tutorial_02/03.jpg", medianImg);

    // PLOTTING
    cv::imshow("Input Image", img);
    cv::imshow("Bilateral Filter", bilateralImg);
    cv::imshow("Gaussian Filter", gaussianImg);
    cv::imshow("Median Filter", medianImg);
    cv::waitKey(0);

    return 0;
}