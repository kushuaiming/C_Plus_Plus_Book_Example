#include <iostream>
#include <set>
using namespace std;

struct StringPtrLess :
    public binary_function<const string*, const string*, bool> {
    bool operator()(const string* ps1, const string* ps2) const {
        return *ps1 < *ps2;
    }
};

int main(int argc, char* argv[]) {
    set<string*, StringPtrLess> ssp; // ssp = "set of string ptrs"
    ssp.insert(new string("Anteater"));
    ssp.insert(new string("Wombat"));
    ssp.insert(new string("Lemur"));
    ssp.insert(new string("Penguin"));
    for (set<string*, StringPtrLess>::const_iterator i = ssp.begin(); i != ssp.end(); ++i)
        cout << **i << endl;
    // copy(ssp.begin(), ssp.end(), ostream_iterator<string*>(cout, "\n"));
    return 0;
}
