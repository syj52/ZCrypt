#include "EncryptionFactory.h"
#include "NullEncryptor.h" // 引入空算法实现
#include "Xor.h"
#include "Logger.h"
// #include "AES.h"         // TODO: 后续引入 AES 头文件

std::unique_ptr<Encryptor> EncryptionFactory::create(const std::string& algorithm) {
    if (algorithm == "null") {
        return std::make_unique<NullEncryptor>();
    }
    else if (algorithm == "xor")
    {
        return std::make_unique<XorEncryptor>();
    }
    // TODO: 后续添加其他算法
    // else if (algorithm == "aes") {
    //     return std::make_unique<AES>();
    // }
    
    // 如果不支持该算法，返回空指针
    return nullptr;
}