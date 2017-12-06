#include <iostream>
#include <cassert>
//#include <queue>
#include "Deque.h"

using namespace std;

main()
{
	Deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_front(1);
	d.push_front(2);
	d.push_front(3);

	Deque<int> c;
	c = d;

	Deque<int>::iterator i;
	for (i = c.begin(); i != c.end(); ++i)
		cout << *i << " ";
	cout << endl;
}
