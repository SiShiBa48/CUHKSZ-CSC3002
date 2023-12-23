#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>

using namespace cv;
using namespace cv::ml;

std::string generate(int index) {
    std::stringstream path;
    path << "dataspace/" << std::setw(5) << std::setfill('0') << index << ".bmp";
    return path.str();
}

int main() {
    Ptr<SVM> svm = SVM::load("SVM_DATA.xml");

    int n;
    std::cout << "Number of images: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string path = generate(i);
        Mat image = imread(path, IMREAD_GRAYSCALE);

        if (image.empty()) {
            std::cout << "No images " << path << std::endl;
            continue;
        }

        Mat imagef;
        image.convertTo(imagef, CV_32F, 1.0 / 255.0);
        Mat imagefed = imagef.reshape(1, 1);

        float response = svm->predict(imagefed);

        std::cout << "Image " << path << " is predicted as: " << response << std::endl;
    }
    system("pause");
    return 0;
}
