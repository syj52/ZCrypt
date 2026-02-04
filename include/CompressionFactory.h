#ifndef ZCRYPT_COMPRESSION_FACTORY_H
#define ZCRYPT_COMPRESSION_FACTORY_H

#include <memory>
#include <string>
#include "ICompression.h" // 依赖基类接口

class CompressionFactory {
public:
    // 工厂方法：根据算法名称创建对应的压缩器实例
    static std::unique_ptr<Compressor> create(const std::string& algorithm);
};

#endif // COMPRESSION_FACTORY_H