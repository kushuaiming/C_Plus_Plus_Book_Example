#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> vec = { 1963, 1996, 2020, 1963 };
    vec.erase(remove(vec.begin(), vec.end(), 1963), vec.end());
    for (int i : vec)
        cout << i << '\t';
    return 0;
}