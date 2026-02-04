#ifndef ZCRYPT_BINARYUTILS_H
#define ZCRYPT_BINARYUTILS_H

#include <vector>
#include <string>
#include <cstdint>

namespace ZCRYPT {
    // 将字符串转换为字节流 (用于模拟二进制数据处理)
    std::vector<uint8_t> stringToBytes(const std::string& str);
    std::string bytesToString(const std::vector<uint8_t>& bytes);
};
#endif