#ifndef ZCRYPT_ENCRYPTION_FACTORY_H
#define ZCRYPT_ENCRYPTION_FACTORY_H

#include <memory>
#include <string>
#include "IEncryption.h" // 依赖基类接口

class EncryptionFactory {
public:
    // 工厂方法：根据算法名称创建对应的加密器实例
    static std::unique_ptr<Encryptor> create(const std::string& algorithm);
};

#endif // ENCRYPTION_FACTORY_H