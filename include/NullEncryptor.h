#ifndef ZCRYPT_NULL_ENCRYPTOR_H
#define ZCRYPT_NULL_ENCRYPTOR_H

#include "IEncryption.h"

class NullEncryptor : public Encryptor 
{
public:
    std::string encrypt(const std::string& data) override;
    std::string decrypt(const std::string& data) override;
};

#endif