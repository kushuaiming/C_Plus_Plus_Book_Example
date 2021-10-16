#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

// 利用缓存(catche values that have already been computed and are likely to be needed again)
int findCubicleNumber(const string& employeeName) {
    typedef map<string, int> CubicleMap;
    static CubicleMap cubes;

    CubicleMap::iterator it = cubes.find(employeeName);

    if (it == cubes.end()) {
        int cubicle = 0;//the result of looking up employeeName's cubicle number in the database.
        cubes[employeeName] = cubicle;
        return cubicle;
    } else return (*it).second;
}

// 提前分配内存prefetching
// 动态数组
template<class T>
class DynArray {
    //...
};

/*template<class T>
T& DynArray<T>::operator[](int index) {
    if (index < 0)
        throw an exception;

    if (index > the current maximum index value)
        call new to allocate enouth additional memory so that index is valid;

    return the indexth element of the array;
}*/

int main(int argv, char* argc[]) {

    DynArray<double> a;
    a[22] = 3.5;
    a[32] = 0;

    return 0;
}