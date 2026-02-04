#include "NullCompressor.h"
#include "NullEncryptor.h"

// NullCompressor 实现
std::vector<uint8_t> NullCompressor::compress(const std::vector<uint8_t>& data) {
    // 什么都不做，直接返回
    return data;
}

std::vector<uint8_t> NullCompressor::decompress(const std::vector<uint8_t>& data) {
    return data;
}

std::vector<uint8_t> NullEncryptor::encrypt(const std::vector<uint8_t>& data) {
    return data;
}

std::vector<uint8_t> NullEncryptor::decrypt(const std::vector<uint8_t>& data) {
    return data;
}