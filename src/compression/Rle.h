#ifndef ZCRYPT_RLE_H
#define ZCRYPT_RLE_H

#include "ICompression.h"

class RleCompressor : public Compressor {
public:
    std::string compress(const std::string& data) override;
    std::string decompress(const std::string& data) override;
};

#endif // RLE_H