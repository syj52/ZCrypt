#ifndef ZCRYPT_XOR_H
#define ZCRYPT_XOR_H


#include "IEncryption.h"
#include <vector>

class XorEncryptor : public Encryptor {
private:
    uint8_t key; // 密钥
public:
    XorEncryptor(uint8_t k = 0x55) : key(k) {}
    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& data) override;
    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& data) override;
};

#endif
