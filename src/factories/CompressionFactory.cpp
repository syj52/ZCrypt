#include "CompressionFactory.h"
#include "NullCompressor.h" // 引入空算法实现
#include "Rle.h"
// #include "Huffman.h"      // TODO: 后续引入 Huffman 头文件

std::unique_ptr<Compressor> CompressionFactory::create(const std::string& algorithm) {
    if (algorithm == "null") {
        return std::make_unique<NullCompressor>();
    }
    else if (algorithm == "rle")
    {
        return std::make_unique<RleCompressor>();
    }
    // TODO: 后续添加其他算法
    // else if (algorithm == "huffman") {
    //     return std::make_unique<HuffmanCompressor>();
    // }
    
    // 如果不支持该算法，返回空指针
    return nullptr;
}