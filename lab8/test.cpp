#include <iostream>
#include <cassert>

#include "Set.h"

using namespace std;

main()
{
   Set<int> s;

    s.insert(10);
    s.insert(7);
    s.insert(6);
    s.insert(9);
    s.insert(8);
    s.insert(11);

    Set<int>::iterator i = s.find(7);
    s.erase(i);

    for (i = s.begin(); i != s.end(); i++)
	 cout << *i << endl;

    cout << "All tests passed." << endl;
}
