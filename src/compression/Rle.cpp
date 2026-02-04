#include "Rle.h"
#include <iostream>

std::vector<uint8_t> RleCompressor::compress(const std::vector<uint8_t>& data) {
    if (data.empty()) return {};

    std::vector<uint8_t> output;

    uint8_t count = 1;
    uint8_t current = data[0];

    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] == current && count < 255) {
            count++;
        } else {
            output.push_back(count);
            output.push_back(current);
            current = data[i];
            count = 1;
        }
    }
    // 别忘了最后一组
    output.push_back(count);
    output.push_back(current);

    std::cout << "[RLE] 压缩: " << data.size() << " -> " << output.size() << " 字节\n";
    return output;
}

std::vector<uint8_t> RleCompressor::decompress(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> output;

    for (size_t i = 0; i < data.size(); i += 2) {
        if (i + 1 >= data.size()) break; // 防止越界
        uint8_t count = data[i];
        uint8_t value = data[i + 1];
        for (int j = 0; j < count; j++) {
            output.push_back(value);
        }
    }

    std::cout << "[RLE] 解压: " << data.size() << " -> " << output.size() << " 字节\n";
    return output;
}