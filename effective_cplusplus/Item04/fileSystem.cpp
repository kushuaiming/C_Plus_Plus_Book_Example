#include <iostream>
using namespace std;

class FileSystem {
public:
    size_t numDisks() const;
};

size_t FileSystem::numDisks() const {
    return 0;
}

FileSystem& tfs() {
    static FileSystem fs;
    return fs;
}

char a = 'A';