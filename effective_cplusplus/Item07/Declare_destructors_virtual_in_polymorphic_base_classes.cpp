#include <iostream>
using namespace std;

class TimeKeeper {
public:
	TimeKeeper();
	// 这里应该将析构函数声明为虚函数
	virtual ~TimeKeeper();
};

class AtomicColock : public TimeKeeper {};
class WaterColock : public TimeKeeper {};
class WristWatch : public TimeKeeper {};

// 如果一个类不会被用作基类,那么就不应该将析构函数声明为虚函数
class Point {
public:
	Point(int xCoord, int yCoord);
	// 如果这里声明为虚函数,那么会增加存储空间
	~Point();
private:
	int x, y;
};

// string有一个non-virtual函数,所以这样继承不好
class SpecialString : public string {};

class AWOV {
public:
	virtual ~AWOV() = 0;// 声明pure virtual析构函数
};

// pure virtual析构函数的定义
AWOV::~AWOV() {}

int main(int argv, char* argc[]) {
	// 返回一个指针,指向一个TimeKeeper派生类的动态分配对象
	TimeKeeper* getTimeKeeper();
	TimeKeeper* ptk = getTimeKeeper();
	delete ptk;

	SpecialString* pss = new SpecialString("Impending Doom");
	string* ps;
	ps = pss;
	delete ps;//未有定义,现实中*ps的SpecialString资源会泄露,因为SpecialString析构函数没有被调用
	return 0;
}