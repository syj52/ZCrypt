#ifndef ZCRYPT_FILEPROCESSOR_H
#define ZCRYPT_FILEPROCESSOR_H

#include <string>

class FileProcessor {
public:
    // 读取文件内容到字符串
    static std::string read_File(const std::string& filepath);
    
    // 将字符串数据写入文件
    static void write_File(const std::string& filepath, const std::string& data); 
private:
    // 私有构造函数，防止被实例化
    FileProcessor() = default;
};

#endif