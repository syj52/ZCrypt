#include "FileProcessor.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


// 读取文件内容到字符串
std::string FileProcessor::read_File(const std::string& filepath)
{
    std::ifstream file(filepath, std::ios::binary);
    if(!file.is_open())
    {
        throw std::runtime_error("无法打开输入文件");
    }
    //读取文件
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    //stunt
    std::string msg = "文件读取字节数：" + buffer.str().size();
    LOG_INFO(msg);
    return buffer.str();
}
    
// 将字符串数据写入文件
void FileProcessor::write_File(const std::string& filepath, const std::string& data)
{
    std::ofstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("无法创建输出文件: " + filepath);
    }

    file.write(data.c_str(), static_cast<std::streamsize>(data.size()));
    file.close();
    
    std::string msg1 = "[文件] 成功写入: " + filepath;
    LOG_INFO(msg1);
    std::string msg2 = "[文件] 成功写入: " + std::to_string(data.size()) + "字节";
    LOG_INFO(msg2);
}
