#include "FileProcessor.h"
#include "Logger.h"
#include <fstream>
#include <stdexcept>
#include <cstdint>


// 读取文件内容到字符串
std::vector<uint8_t> FileProcessor::read_File(const std::string& filepath)
{
    std::ifstream file(filepath, std::ios::binary);
    if(!file.is_open())
    {
        throw std::runtime_error("无法打开输入文件");
    }
    // 获取文件大小
    file.seekg(0, std::ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    // 预分配内存并读取
    std::vector<uint8_t> buffer(file_size);
    file.read(reinterpret_cast<char*>(buffer.data()), static_cast<std::streamsize>(file_size));
    file.close();

    //stunt
    std::string msg = "[文件] 读取字节数: " + std::to_string(file_size);
    LOG_INFO(msg);
    return buffer;
}
    
// 将字符串数据写入文件
void FileProcessor::write_File(const std::string& filepath, const std::vector<uint8_t>& data)
{
    std::ofstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("无法创建输出文件: " + filepath);
    }

    file.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
    file.close();
    
    std::string msg1 = "[文件] 成功写入: " + filepath;
    LOG_INFO(msg1);
    std::string msg2 = "[文件] 成功写入: " + std::to_string(data.size()) + "字节";
    LOG_INFO(msg2);
}
