#include <iostream>
#include <list>
using namespace std;

int main(int argc, char* argv[]) {
    list<int> li = { 1, 2, 3, 99 };
    li.remove(99);
    for (int i : li)
        cout << i << endl;
    return 0;
}