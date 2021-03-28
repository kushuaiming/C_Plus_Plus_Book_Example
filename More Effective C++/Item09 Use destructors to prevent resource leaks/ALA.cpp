#include <iostream>
using namespace std;

class ALA {
public:
    virtual void processAdoption() = 0;
    // ...
};
class Puppy : public ALA {
public:
    virtual void processAdoption();
    // ...
};
class Kitten : public ALA {
public:
    virtual void processAdoption();
    // ...
};

// read animal information from s, then return a pointer
// to a newly allocated object of the appropriate type
ALA* readALA(istream& s);

void processAdoptions(istream& dataSource)
{
    while (dataSource) { // while there¡¯s data
        ALA* pa = readALA(dataSource); // get next animal
        // delete pa; // delete object that
        try {
            pa->processAdoption();
        }
        catch () {
            delete pa;
            throw;
        }
        delete pa;
    } // readALA returned
}

int main(int argc, char* argv[]) {
    return 0;
}
