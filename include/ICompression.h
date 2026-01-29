#ifndef ZCRYPT_ICOMPRESSION_H
#define ZCRYPT_ICOMPRESSION_H

#include <string>

// 压缩算法基类 (接口)
class Compressor {
public:
    virtual ~Compressor() = default;

    // 纯虚函数：执行压缩
    // 输入：原始数据
    // 输出：压缩后的数据
    virtual std::string compress(const std::string& data) = 0;

    // 纯虚函数：执行解压缩
    // 输入：压缩后的数据
    // 输出：原始数据
    virtual std::string decompress(const std::string& data) = 0;
};


#endif