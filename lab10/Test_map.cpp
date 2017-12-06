#include <iostream>
#include <cassert>
//#include <map>
#include "Map.h"
#include <string>
//#include "../lab3/String.h"

using namespace std;

int main()
{
    Map < string, int > m;
    
    assert(m.size() == 0);
    assert(m.empty());
    
    m["abby"] = 9;
    assert(m["abby"] == 9);
    
    m["billy"] = 6;
    assert(m["billy"] == 6);
    assert(m["abby"] == 9);

    m["katie"] = -2;
    assert(m["katie"] == -2);
    assert(m["billy"] == 6);
    assert(m["abby"] == 9);

    m["bobby"] = -4;
    assert(m["bobby"] == -4);
    assert(m["katie"] == -2);
    assert(m["billy"] == 6);
    assert(m["abby"] == 9);

    m["binky"] = 100;
    m["abby"] = -100;
    assert(m["binky"] == 100);
    assert(m["bobby"] == -4);
    assert(m["katie"] == -2);
    assert(m["billy"] == 6);
    assert(m["abby"] == -100);

    assert(m["charles"] == 0);

    assert((*m.find("katie")).second == -2);

    assert(m.find("katie") != m.end());

    Map<string, int>::iterator i;
    for (i = m.begin(); i != m.end(); i++)
        cout << (*i).first << " " << (*i).second << endl;

    m.erase("katie");
    assert(m.find("katie") == m.end());

    cout << "Success!" << endl;
}
