#ifndef STACK_H
#define STACK_H

// Stack.h  -- a stack implemented as an adapter (of vector or list or ...)

#include "../lab5/List.h"

using namespace std;

//Use the following line for STL containers.
//template <class T, template <class T, class = allocator<T> > class Container = list>
template <class T, template <class T> class Container = List>
class Stack
{
public:
   //We don't need a constructor or destructor because the Container has/should have one
   //Stack(): container() { }
   //~Stack() { ~container(); }
   bool empty() const;
   unsigned int size() const;
   void push(const T & x);
   void pop();
   T & top();

private:
   Container<T> container;
};

#endif
