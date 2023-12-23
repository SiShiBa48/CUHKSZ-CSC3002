#ifndef _TEST_H_
#define _TEST_H_
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

std::vector<unsigned char> readLabels(const std::string& file);

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
#endif