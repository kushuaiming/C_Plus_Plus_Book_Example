#include <iostream>
using namespace std;

class HomeForSale {
private:
	// 将拷贝构造函数和拷贝赋值运算符放在private里可以阻止拷贝行为
	HomeForSale(const HomeForSale&);
	HomeForSale& operator=(const HomeForSale&);
};

class Uncopyable {
protected:
	// 允许derived对象构造和析构
	Uncopyable() {}
	~Uncopyable() {}
private:
	// 但是阻止copy
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale : private Uncopyable {
	//...
};

int main(int argv, char* argc[])
{
	HomeForSale h1;
	HomeForSale h2;
	// 下面这个从实际情况来讲不应该通过编译
	HomeForSale h3(h1);
	h1 = h2;
}