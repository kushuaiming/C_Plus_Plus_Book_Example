#include <iostream>
using namespace std;

class EquipmentPiece {
public:
    EquipmentPiece(int IDNumber);
    //...
private:
    int idNumber;
};

EquipmentPiece::EquipmentPiece(int IDNumber) : idNumber(IDNumber) {}

int main(int argv, char* argc[]) {
    //EquipmentPiece bestPieces[10];// 错误,没有办法调用EquipmentPiece的构造函数
    //EquipmentPiece *bestPieces = new EquipmentPiece[10];// 错误,和上面相同的问题

    // 解决方法1,提供必要的参数
    int ID1 = 1, ID2 = 2, ID3 = 3;
    EquipmentPiece bestPieces[] = {
        EquipmentPiece(ID1),
        EquipmentPiece(ID2),
        EquipmentPiece(ID3)
    };

    // 解决方法2,用一个指针数组而不是对象数组
    typedef EquipmentPiece* PEP;
    PEP bestPieces[10];
    //PEP* bestPieces = new PEP[10];
    int IDNumber = 0;
    for (int i = 0; i < 10; i++) {
        bestPieces[i] = new EquipmentPiece(IDNumber);
    }

    // 为十个元素的数组分配内存
    void* rawMemory = operator new[](10 * sizeof(EquipmentPiece));
    EquipmentPiece* bestPieces = static_cast<EquipmentPiece*>(rawMemory);
    for (int i = 0; i < 10; i++)
        new (bestPieces + i) EquipmentPiece(IDNumber);
    // 销毁对象并回收空间
    for (int i = 9; i >= 0; i--)
        bestPieces[i].~EquipmentPiece();
    operator delete[](rawMemory);

    return 0;
}