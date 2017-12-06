#ifndef QUEUE_H
#define QUEUE_H

#include <list>
//#include "../lab5/List.h"

using namespace std;

//template <class T, template <class T> class Container = List>
template <class T, template <class T, class = allocator<T> > class Container = list>
class Queue
{
public:
    // constructors previously defined in Container
    bool empty() const { return container.empty(); }
    unsigned int size() const { return container.size(); };
    void push(const T & x) { container.push_front(x); };
    void pop() { container.pop_back(); };
    T & front() { return container.front(); };
    T & back() { return container.back(); };

private:
    Container<T> container;
};

#endif
