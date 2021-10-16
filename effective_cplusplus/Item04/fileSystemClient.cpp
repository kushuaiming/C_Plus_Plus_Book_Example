#include <iostream>
#include <list>

using namespace std;

class Directory {
public:
	Directory();
};

extern FileSystem tfs;

Directory::Directory() {
	size_t disks = tfs.numDisks();
}

Directory& tempDir() {
	static Directory td;
	return td;
}

int main(int argv, char* argc[])
{
	// 为零时文件而作的目录
	// Directory tempDir();
    return 0;
}
