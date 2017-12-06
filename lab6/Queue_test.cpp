#include <iostream>
#include <cassert>
#include "Queue.h"
//#include "../lab3/String.h"
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    Queue<string, list> q;
    q.push("abc");
    q.push("de");
    assert(q.back() == "abc");

    q.pop();
    assert(q.size() == 1);
    assert(q.front() == "de");

    cout << "SUCCESS\n";

    return 0;
}
