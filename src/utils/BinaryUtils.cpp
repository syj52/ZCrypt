#include "BinaryUtils.h"

std::vector<uint8_t> ZCRYPT::stringToBytes(const std::string& str) {
    std::vector<uint8_t> bytes(str.begin(), str.end());
    return bytes;
}

std::string ZCRYPT::bytesToString(const std::vector<uint8_t>& bytes) {
    return std::string(bytes.begin(), bytes.end());
}