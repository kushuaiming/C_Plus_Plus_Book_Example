#include <iostream>
using namespace std;

class BST {
private:
    int i;
public:
    //...
};

class BalancedBST : public BST {
    //...

};

void printBSTArray(ostream& s, const BST array[], int numElements) {
    for (int i = 0; i < numElements; i++) {
        s << array[i];// ���������������<<��ΪBST�Ķ�����Ƶ�
    }
}

void deleteArray(ostream& logStream, BST array[]) {
    logStream << "Deleting array at address " << static_cast<void*>(array) << '\n';
    delete[] array;
}

int main(int argv, char* argc[]){
    BST BSTArray[10];
    printBSTArray(cout, BSTArray, 10); // û����

    BalancedBST bBSTArray[10];
    printBSTArray(cout, bBSTArray, 10);// ?

    BalancedBST* balTreeArray = new BalancedBST[50];
    deleteArray(cout, balTreeArray);
    return 0;
}