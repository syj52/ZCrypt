#include "Xor.h"
#include <iostream>

std::vector<uint8_t> XorEncryptor::encrypt(const std::vector<uint8_t>& data) {
    if (data.empty()) return {};

    std::vector<uint8_t> output;
    output.reserve(data.size()); // 预分配

    for (const auto& byte : data) {
        // 核心逻辑：异或运算
        output.push_back(byte ^ key);
    }

    std::cout << "[XOR] 加密完成: " << data.size() << " 字节\n";
    return output;
}

std::vector<uint8_t> XorEncryptor::decrypt(const std::vector<uint8_t>& data) {
    // 异或加密的特性：加密和解密是同一个过程
    // 再次异或同一个密钥，数据还原
    return encrypt(data);
}