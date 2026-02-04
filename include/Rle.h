#ifndef ZCRYPT_RLE_H
#define ZCRYPT_RLE_H

#include "ICompression.h"

class RleCompressor : public Compressor {
public:
    std::vector<uint8_t> compress(const std::vector<uint8_t>& data) override;
    std::vector<uint8_t> decompress(const std::vector<uint8_t>& data) override;
};

#endif // RLE_H