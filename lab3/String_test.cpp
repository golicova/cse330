#include <iostream>
#include <cassert>
#include "String.h"

using namespace std;

int main()
{
    String s1; // s1 == ""
    assert(s1.length() == 0);

    String s2("hi"); // s2 == "hi"
    assert(s2.length() == 2);

    String s3(s2); // s3 == "hi"
    assert(s3.length() == 2);
    assert(s3[0] == 'h');
    assert(s3[1] == 'i');

    s1 = s2; // s1 == "hi"
    assert(s1 == s2);

    s3 = "bye"; // s3 == "bye"
    assert(s3.length() == 3);
    assert(s3[0] == 'b');
    assert(s3[1] == 'y');
    assert(s3[2] == 'e');

    s1 += "re"; // s1 == "hire"
    assert(s1 == "hire");

    s1 += "d"; // s1 == "hired"
    assert(not (s1 == "hire"));

    cout << "SUCCESS" << endl;
}
