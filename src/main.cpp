#include <iostream>
#include <memory>
#include <vector>
#include "Logger.h"
#include "FileProcessor.h"
#include "CompressionFactory.h"
#include "EncryptionFactory.h"

using byte = uint8_t;

/*
    参数配置：
    ZC -c 压缩模式 -e 加密模式 -f 文件 -o 输出文件
    加密必须进行防止意外，因此未设置时设定使用默认加密方式，压缩可选，默认不压缩；
*/
struct Config {
    bool compress = false;
    bool encrypt = false;
    std::string compress_;
    std::string encrypt_ = "default";
    std::string file_path;
    std::string output_path;
};

int main(int argc, const char** argv) 
{
    // 1. 解析参数
    Config config;
    for(int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg == "-c" || arg == "--compress") {
            config.compress = true;
            config.compress_ = argv[++i];
        }
        else if (arg == "-e" || arg == "--encrypt") {
            config.encrypt = true;
            config.encrypt_ = argv[++i];
        }
        else if (arg == "-f" || arg == "--file") {
            config.file_path = argv[++i];
        }
        else if (arg == "-o" || arg == "--output") {
            config.output_path = argv[++i];
        }
        else {
            std::cerr << "Unknown option: " << arg << std::endl;
            return 1;
        } 
    }

    // 参数有效性检查
    if (config.file_path.empty()) {
        std::cerr << "Error: Input file path is required!" << std::endl;
        return 1;
    }
    if (config.output_path.empty()) {
        std::cerr << "Error: Output file path is required!" << std::endl;
        return 1;
    }

    // 显示配置信息
    std::cout << "Mode:\n" << "\tCompress:" << (config.compress ? config.compress_ : "none") 
              << "\n\tEncrypt:" << config.encrypt_ << std::endl;
    std::cout << "Input: " << config.file_path << std::endl;
    std::cout << "Output: " << config.output_path << std::endl;

    // 2. 读取原始数据
    std::vector<byte> raw_data = FileProcessor::read_File(config.file_path);

    // 3. 处理数据
    std::vector<byte> intermediate;
    if(config.compress)
    {
        auto compressor = CompressionFactory::create(config.compress_);
        if (!compressor) {
            std::cerr << "Error: Unknown compression algorithm: " << config.compress_ << std::endl;
            return 1;
        }
        intermediate = compressor->compress(raw_data);
    }
    else
    {
        intermediate = raw_data;
    }
    
    // 4. 加密处理
    std::vector<byte> final_data;
    if(config.encrypt)
    {
        auto encryptor = EncryptionFactory::create(config.encrypt_);
        if (!encryptor) {
            std::cerr << "Error: Unknown encryption algorithm: " << config.encrypt_ << std::endl;
            return 1;
        }
        final_data = encryptor->encrypt(intermediate);
    }
    else
    {
        final_data = intermediate;
    }
    
    // 5. 写入输出文件
    FileProcessor::write_File(config.output_path, final_data);
    
    std::cout << "ending..." << std::endl;
    return 0;
}