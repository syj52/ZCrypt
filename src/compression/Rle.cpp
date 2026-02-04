#include "Rle.h"
#include "BinaryUtils.h"
#include <iostream>

std::string RleCompressor::compress(const std::string& data) {
    if (data.empty()) return "";

    std::vector<uint8_t> input = ZCRYPT::stringToBytes(data);
    std::vector<uint8_t> output;

    uint8_t count = 1;
    uint8_t current = input[0];

    for (size_t i = 1; i < input.size(); i++) {
        if (input[i] == current && count < 255) {
            count++;
        } else {
            output.push_back(count);
            output.push_back(current);
            current = input[i];
            count = 1;
        }
    }
    // 别忘了最后一组
    output.push_back(count);
    output.push_back(current);

    std::cout << "[RLE] 压缩: " << data.size() << " -> " << output.size() << " 字节\n";
    return ZCRYPT::bytesToString(output);
}

std::string RleCompressor::decompress(const std::string& data) {
    std::vector<uint8_t> input = ZCRYPT::stringToBytes(data);
    std::vector<uint8_t> output;

    for (size_t i = 0; i < input.size(); i += 2) {
        if (i + 1 >= input.size()) break; // 防止越界
        uint8_t count = input[i];
        uint8_t value = input[i + 1];
        for (int j = 0; j < count; j++) {
            output.push_back(value);
        }
    }

    std::cout << "[RLE] 解压: " << data.size() << " -> " << output.size() << " 字节\n";
    return ZCRYPT::bytesToString(output);
}