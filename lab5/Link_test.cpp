#include <iostream>

#include "Link.h"

using namespace std;

int main()
{
    Link<int> link1;
    cout << "link1: " << link1.get_value() << endl;

    Link<int> link2(50);
    cout << "link2: " << link2.get_value() << endl;

    Link<int> link3(link2);
    link3.set_value(10);
    cout << "link3: " << link3.get_value() << endl;
    cout << "link2: " << link2.get_value() << endl;

    return 0;
}
