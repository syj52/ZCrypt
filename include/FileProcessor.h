#ifndef ZCRYPT_FILEPROCESSOR_H
#define ZCRYPT_FILEPROCESSOR_H

#include <string>
#include <vector>
#include <cstdint>

class FileProcessor {
public:
    // 读取文件内容到字节数组
    static std::vector<uint8_t> read_File(const std::string& filepath);
    
    // 将字节数组数据写入文件
    static void write_File(const std::string& filepath, const std::vector<uint8_t>& data); 
private:
    // 私有构造函数，防止被实例化
    FileProcessor() = default;
};

#endif