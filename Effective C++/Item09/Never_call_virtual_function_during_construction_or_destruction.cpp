#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Transaction {// 所有交一的base class
public:
    Transaction();
    virtual void logTransaction() const = 0;
};

Transaction::Transaction() {
    //logTransaction();
}

class BuyTransaction : public Transaction {
public:
    virtual void logTransaction() const;
};

class SellTransaction : public Transaction {
public:
    virtual void logTransaction() const;
};

int main(int argv, char* argc[]) {
    // Transaction构造函数会首先被调用,其中的longTransaction会调用基类版本
    //BuyTransaction b;
    return 0;
}