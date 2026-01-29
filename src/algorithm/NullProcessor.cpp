#include "NullCompressor.h"
#include "NullEncryptor.h"

// NullCompressor 实现
std::string NullCompressor::compress(const std::string& data) {
    // 什么都不做，直接返回
    return data;
}

std::string NullCompressor::decompress(const std::string& data) {
    return data;
}

std::string NullEncryptor::encrypt(const std::string& data) {
    return data;
}

std::string NullEncryptor::decrypt(const std::string& data) {
    return data;
}
