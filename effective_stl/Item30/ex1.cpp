#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int transmorify(int x) {
    // 从x中产生一些新值
    return x * 2;
}

int main(int argc, char* argv[]) {
    vector<int> results = { -1,-1 };
    vector<int> values = { 2, 3, 4 };
    // 会出错的写法
    // transform(values.begin(), values.end(), results.end(), transmorify);
    
    // 在result的结尾插入返回的values
    transform(values.begin(), values.end(), back_inserter(results), transmorify);

    for (int i : results)
        cout << i << endl;
    return 0;
}
