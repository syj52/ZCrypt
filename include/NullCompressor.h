#ifndef ZCRYPT_NULL_COMPRESSOR_H
#define ZCRYPT_NULL_COMPRESSOR_H

#include "ICompression.h"

class NullCompressor : public Compressor 
{
public:
    std::string compress(const std::string& data) override;
    std::string decompress(const std::string& data) override;
};

#endif