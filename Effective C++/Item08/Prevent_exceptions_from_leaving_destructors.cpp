#include <iostream>
#include <vector>
using namespace std;

class Widget {
public:
	//...
	~Widget() {
		// ...假设这里可能发生异常
	}
};

void doSomething() {
	vector<Widget> v;
}
// v在这里被销毁


// 用于数据库链接的类
class DBConnection {
public:
	// 这个函数返回DBconnection对象,为求简化暂时省略参数
	static DBConnection create();
	// 关闭联机,失败则抛出异常
	void close();
};

// 为了确保客户不忘记调用close(),一个合理的想法是创建一个用来管理DBConnection资源的类
//class DBConn {
//public:
//	// ...
//	~DBConn() {
//		db.close();
//	}
//private:
//	DBConnection db;
//};

//DBConn::~DBConn() {
//	try { db.close(); }
//	catch () {
//		// 制作运转记录,记下对close的调用失败
//		abort();
//	}
//}

class DBConn {
public:
	// ...
	void close() {// 供顾客使用的新函数
		db.close();
		closed = true;
	}

	~DBConn() {
		if (!closed) {
			try { db.close(); }
			catch () {
				// 制作运转记录,记下对close的调用失败
			}
		}
	}
private:
	DBConnection db;
	bool closed;
};

int main(int argv, char* argc[]) {
	
	return 0;
}