#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v;
    v.reserve(10);
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
    }
    cout << v.size();
    v[3] = v[5] = v[9] = 99;
    remove(v.begin(), v.end(), 99);
    cout << v.size();
    return 0;
}