#include <iostream>
using namespace std;

class Abstract_base {
public:
    virtual ~Abstract_base() = 0;
    virtual void interface() const = 0;
    virtual const char*
        mumble() const { return _mumble; }
protected:
    char* _mumble;
};

int main(int argc, char* argv[]) {
    return 0;
}