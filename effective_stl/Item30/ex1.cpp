#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int transmorify(int x) {
    // ��x�в���һЩ��ֵ
    return x * 2;
}

int main(int argc, char* argv[]) {
    vector<int> results = { -1,-1 };
    vector<int> values = { 2, 3, 4 };
    // ������д��
    // transform(values.begin(), values.end(), results.end(), transmorify);
    
    // ��result�Ľ�β���뷵�ص�values
    transform(values.begin(), values.end(), back_inserter(results), transmorify);

    for (int i : results)
        cout << i << endl;
    return 0;
}
