#include <iostream>
using namespace std;

// ASPECT_RATIO也许从未被编译器看见
// 也许在编译器开始处理源码之前它就被预处理器移走了
#define ASPECT_RATIO 1.653

// 解决方法是以一个常量替换上述的宏
const double AspectRatio = 1.653; 

// const出现在*左边,表示被指物是常量,出现在*右边表示指针是常量
const char* const authorName = "Scott Meyers";

class GamePlayer {
public:
	void showNumTurns() {
		cout << NumTurns << endl;
		// cout << &NumTurns << endl;
	}
private:
	// static const int NumTurns = 5; // 常量声明式,static可以确保此常量只有一个实体
	enum { NumTurns = 5 }; // 令NumTurns成为5的一个记号名称
	int scores[NumTurns]; // 使用该常量
};

// const int GamePlayer::NumTurns;// NumTurns的定义,不可以再设初值
