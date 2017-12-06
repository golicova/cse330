#include <iostream>
#include <cassert>

#include "Priority_queue.h"

using namespace std;

int main()
{
   Priority_queue<int> p, q, pq;

   int x;
   while (cin >> x)
	p.push(x);

   pq = q = p;

   while (!pq.empty()) {
	cout << pq.top() << " ";
	pq.pop();
   }
   cout << endl;
}
