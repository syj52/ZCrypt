#include <iostream>
#include <memory>

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

//假函数区，具体后续分文件实现，由各组件执行，这里是空声明
std::string read_file(std::string& filepath);
void save_file(std::string& output_path, std::string data);

//假类区
class Compressor 
{
public:
    virtual ~Compressor() = default;
    virtual std::string compress(const std::string& data) = 0;
};
class CompressionFactory 
{
public:
    static std::unique_ptr<Compressor> create(const std::string& compression_algorithm);
};

class Encryptor
{
public:
    virtual ~Encryptor() = default;
    virtual std::string encrypt(const std::string& data) = 0;
};
class EncryptionFactory
{
public:
    static std::unique_ptr<Encryptor> create(const std::string& encryption_algorithm);
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
            if (i + 1 < argc) {
                config.file_path = argv[++i]; // 获取下一个参数作为路径
            }
        }
        else if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc) {
                config.output_path = argv[++i];
            }
        }
        else {
            std::cerr << "Unknown option: " << arg << std::endl;
            return 1;
        } 
    }
    //TODO: 参数有效性检查
    
    // 配置内容
    std::cout << "Mode:\n" << "\tCompress:" << config.compress_ << "\n\t" << "Encrypt:" << config.encrypt_ << std::endl;
    std::cout << "Input: " << config.file_path << std::endl;
    std::cout << "Output: " << config.output_path << std::endl;

    //加载文件内容，确认路径正确
    std::string raw_data = read_file(config.file_path);
    //执行算法
    std::string intermediate;
    if(config.compress)
    {
        auto compressor = CompressionFactory::create(config.compress_);
        intermediate = compressor->compress(raw_data);
        // delete compressor;
    }
    else
    {
        intermediate = raw_data;
    }
    
    // 中间表示 intermediate
    if(config.encrypt)
    {
        auto encryptor = EncryptionFactory::create(config.encrypt_);
        std::string final_data = encryptor->encrypt(intermediate);
        save_file(config.output_path, final_data);
    }
    else
    {
        auto encryptor = EncryptionFactory::create(config.encrypt_);
        std::string final_data = encryptor->encrypt(intermediate);
        save_file(config.output_path, final_data);
    }
    
    std::cout << "ending..." << std::endl;
    return 0;
}