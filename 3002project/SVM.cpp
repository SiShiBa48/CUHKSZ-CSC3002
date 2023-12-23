#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include "readerimage.h"
#include "readerlable.h"
#include "train.cpp"

using namespace cv;
using namespace cv::ml;

std::vector<unsigned char> readLabels(const std::string& file) {
    std::ifstream f(file, std::ios::binary);

    char head[8];
    f.read(head, 8);

    int lables = (static_cast<unsigned char>(head[4]) << 24) |
                      (static_cast<unsigned char>(head[5]) << 16) |
                      (static_cast<unsigned char>(head[6]) << 8) |
                      static_cast<unsigned char>(head[7]);

    std::vector<unsigned char> labels(lables);

    for (int i = 0; i < lables; i++) {
        f.read(reinterpret_cast<char*>(&labels[i]), 1);
    }

    f.close();
    return labels;
}

int main() {
    std::cout << "Loading training and test data..." << std::endl;

    std::vector<std::vector<unsigned char>> trainim = readImages("train-images.idx3-ubyte");
    std::vector<unsigned char> trainla = readLabels("train-labels.idx1-ubyte");

    Mat trainingImagesMat(trainim.size(), trainim[0].size(), CV_32F);
    Mat trainingLabelsMat(trainla.size(), 1, CV_32S);

    for (size_t i = 0; i < trainim.size(); ++i) {
        for (size_t j = 0; j < trainim[i].size(); ++j) {
            trainingImagesMat.at<float>(i, j) = static_cast<float>(trainim[i][j]) / 255.0f;
        }
        trainingLabelsMat.at<int>(i, 0) = static_cast<int>(trainla[i]);
    }

    std::vector<std::vector<unsigned char>> testImages = readImages("t10k-images.idx3-ubyte");
    std::vector<unsigned char> testLabels = readLabels("t10k-labels.idx1-ubyte");

    Mat testImagesMat(testImages.size(), testImages[0].size(), CV_32F);
    Mat testLabelsMat(testLabels.size(), 1, CV_32S);

    for (size_t i = 0; i < testImages.size(); ++i) {
        for (size_t j = 0; j < testImages[i].size(); ++j) {
            testImagesMat.at<float>(i, j) = static_cast<float>(testImages[i][j]) / 255.0f;
        }
        testLabelsMat.at<int>(i, 0) = static_cast<int>(testLabels[i]);
    }

    std::cout << "Start training, this process may take several minutes..." << std::endl;
    train(trainingImagesMat, trainingLabelsMat, testImagesMat, testLabelsMat);
    std::cout << "Trainning completed." << std::endl;

    return 0;
}
