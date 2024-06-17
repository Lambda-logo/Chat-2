#pragma once

#include <string>
#include <vector>
#include <unordered_map>

typedef unsigned int uint;

#define one_block_size_bytes 64
#define one_block_size_uints 16
#define block_expend_size_uints 80

#define SHA1HASHLENGTHBYTES 20
#define SHA1HASHLENGTHUINTS 5

const uint H[5] = {
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476,
    0xC3D2E1F0
};

uint cycle_shift_left(uint val, int bit_count);
uint bring_to_human_view(uint val);

uint* sha1(char* message, uint msize_bytes) {
    return nullptr;
}

class Chat {
public:
    Chat() : data_count(0) {}

    void reg(const std::string& _login, const std::vector<char>& _pass) {
        uint* hash = sha1(const_cast<char*>(_pass.data()), static_cast<uint>(_pass.size()));
        hashTable[_login] = std::make_pair(_pass, hash);
        data_count++;
    }

    bool login(const std::string& _login, const std::vector<char>& _pass) {
        if (hashTable.find(_login) != hashTable.end()) {
            uint* hash = sha1(const_cast<char*>(_pass.data()), static_cast<uint>(_pass.size()));
            return memcmp(hashTable[_login].second, hash, 5 * sizeof(uint)) == 0;
        }
        return false;
    }

private:
    std::unordered_map<std::string, std::pair<std::vector<char>, uint*>> hashTable;
    int data_count = 0;

    int hashFunction(const std::string& key) {
        return 0;
    }
};