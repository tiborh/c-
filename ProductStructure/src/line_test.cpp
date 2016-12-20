#include "line.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

void validator(line tl)
{
    cout << "\nTest line:\n" << tl << '\n';
    cout << "Validation: " << (tl.is_valid() ? "passed" : "\t\tfailed") << '\n';
}

void line_test()
{
    //only lengths are examined:
    line test_line0("abc12345","百千万","0","零");
    validator(test_line0);
    assert(test_line0.is_valid());

    //all correct, version designation is not needed
    line test_line1("abc12345\tr1a\t一");
    validator(test_line1);
    assert(test_line1.is_valid());

    //no r-state
    line test_line2("abc12345\t\t二\t");
    validator(test_line2);
    assert(!test_line2.is_valid());

    //product number is too short
    line test_line3("abc1234\tr1b\t三\t");
    validator(test_line3);
    assert(!test_line3.is_valid());

    //no function designation
    line test_line4("abc12345\tr1b\t\t四");
    validator(test_line4);
    assert(!test_line4.is_valid());

    //r-state is too short
    line test_line5("abc12345\tr1\t五\t");
    validator(test_line5);
    assert(!test_line5.is_valid());
    assert(test_line5.get_tier() == 0);

    line tl6(". . . CAA 901 3129/3	R1A	GUI	");
    validator(tl6);
    assert(tl6.get_tier() == 3);
}

