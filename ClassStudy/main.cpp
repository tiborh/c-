#include <iostream>
#include "MemoryBlock.h"

using namespace std;

int main(int argc, char** argv)
{
    size_t ts = 10;
    MemoryBlock *tb = new MemoryBlock(ts);
    cout << "Before init (tb): " << *tb << '\n';
    tb->init();
    cout << "After init (tb): " << *tb << '\n';
    MemoryBlock *tba = new MemoryBlock(*tb);

    cout << "After copy constructor used (tba): " << *tba << '\n';
    tb->init();
    cout << "Reinitialsed first (tb): " << *tb << '\n';
    cout << "Unchanged copy (tba): " << *tba << '\n';

    MemoryBlock *tbb = new MemoryBlock(ts);
    *tbb = *tba;
    cout << "After assignment operator used (tbb=tba) tbb == " << *tbb << '\n';
    tba->init();
    tba->init();
    cout << "After reinitialisation of tba, tbb remains " << *tbb << '\n';
    cout << "Reinitialsed tba== " << *tba << '\n';

    cout << "Destroying tb, tba and tbb: \n";
    for (MemoryBlock *ttemp : {tb, tba, tbb})
        delete ttemp;

    MemoryBlock tbc(ts);
    tbc.init();
    cout << "tbc prepared for move: " << tbc << '\n';
    MemoryBlock tbd = move(tbc);
    cout << "After move constructing tbd from tbc,\n";
    cout << "tbd: " << tbd << '\n';
    cout << "tbc: " << tbc << '\n';

    return 0;
}
