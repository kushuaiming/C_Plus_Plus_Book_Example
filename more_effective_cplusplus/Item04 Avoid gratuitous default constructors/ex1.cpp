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
    //EquipmentPiece bestPieces[10];// ����,û�а취����EquipmentPiece�Ĺ��캯��
    //EquipmentPiece *bestPieces = new EquipmentPiece[10];// ����,��������ͬ������

    // �������1,�ṩ��Ҫ�Ĳ���
    int ID1 = 1, ID2 = 2, ID3 = 3;
    EquipmentPiece bestPieces[] = {
        EquipmentPiece(ID1),
        EquipmentPiece(ID2),
        EquipmentPiece(ID3)
    };

    // �������2,��һ��ָ����������Ƕ�������
    typedef EquipmentPiece* PEP;
    PEP bestPieces[10];
    //PEP* bestPieces = new PEP[10];
    int IDNumber = 0;
    for (int i = 0; i < 10; i++) {
        bestPieces[i] = new EquipmentPiece(IDNumber);
    }

    // Ϊʮ��Ԫ�ص���������ڴ�
    void* rawMemory = operator new[](10 * sizeof(EquipmentPiece));
    EquipmentPiece* bestPieces = static_cast<EquipmentPiece*>(rawMemory);
    for (int i = 0; i < 10; i++)
        new (bestPieces + i) EquipmentPiece(IDNumber);
    // ���ٶ��󲢻��տռ�
    for (int i = 9; i >= 0; i--)
        bestPieces[i].~EquipmentPiece();
    operator delete[](rawMemory);

    return 0;
}