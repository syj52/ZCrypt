#ifndef ZCRYPT_IENCRYPTION_H
#define ZCRYPT_IENCRYPTION_H

#include <vector>
#include <cstdint>

// 加密算法基类 (接口)
class Encryptor {
public:
    virtual ~Encryptor() = default;

    // 纯虚函数：执行加密
    // 输入：明文数据
    // 输出：密文数据
    virtual std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data) = 0;

    // 纯虚函数：执行解密
    // 输入：密文数据
    // 输出：明文数据
    virtual std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data) = 0;
};

#endif