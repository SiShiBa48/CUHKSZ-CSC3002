#ifndef _TEST_H_
#define _TEST_H_
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<unsigned char>> readImages(const std::string& file);

std::vector<std::vector<unsigned char>> readImages(const std::string& file){
    std::ifstream f(file, std::ios::binary);

    char head[16];
    f.read(head, 16);

    int image = (static_cast<unsigned char>(head[4]) << 24) |
                      (static_cast<unsigned char>(head[5]) << 16) |
                      (static_cast<unsigned char>(head[6]) << 8) |
                      static_cast<unsigned char>(head[7]);

    int rows = (static_cast<unsigned char>(head[8]) << 24) |
                    (static_cast<unsigned char>(head[9]) << 16) |
                    (static_cast<unsigned char>(head[10]) << 8) |
                    static_cast<unsigned char>(head[11]);

    int col = (static_cast<unsigned char>(head[12]) << 24) |
                       (static_cast<unsigned char>(head[13]) << 16) |
                       (static_cast<unsigned char>(head[14]) << 8) |
                       static_cast<unsigned char>(head[15]);

    std::vector<std::vector<unsigned char>> images (image, std::vector<unsigned char>(rows * col));

    for (int i = 0; i < image; i++) {
        f.read(reinterpret_cast<char*>(images[i].data()), rows * col);
    }

    f.close();
    return images;
}

#endif