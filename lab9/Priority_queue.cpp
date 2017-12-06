#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Priority_queue
{
public:
    Priority_queue(): c() { }
    Priority_queue(const Priority_queue & p): c(p.c) { }
    Priority_queue & operator=(const Priority_queue & p) { c = p.c; return *this; }
    // vector destructor is automatically called when an obj of type
    // Priority_queue is destroyed.

    bool empty() { return c.empty(); }
    unsigned int size() { return c.size(); }
    void push(const T & x);
    void pop();
    T & top() { return c.front(); }

private:
    vector<T> c;
    void pop_heap(Iterator start, Iterator stop);
    void push_heap(Iterator start, Iterator stop);
    void adjust_heap(Iterator start, unsigned heap_size, unsigned position);
};



template <class T>
void Priority_queue<T>::push(const T & x)
{
    c.push_back(x);
    unsigned n = c.size() - 1;
    unsigned parent = (n - 1) / 2; 
    while(n > 0 and c[parent] < c[n]) {
        swap(c[n], c[parent]);
        n = parent; 
        parent = (n - 1) / 2; 
    }
} //push

template <class T>
void Priority_queue<T>::pop()
{
    // 1. call pop_heap() on c
    // 2. c.pop_back();

    typename vector<T>::iterator start = c.begin();
    typename vector<T>::iterator stop = c.end();
    pop_heap(start, stop);
    c.pop_back();
} // pop

template <class T>
void Priority_queue<T>::push_heap(Iterator start, Iterator stop)
{
    unsigned int position = (stop - start) - 1;
    unsigned int parent = (position - 1) / 2;

    // percolate up
    while(position > 0 && start[position] < start[parent]) {
        swap(start[position], start[parent]);
        position = parent;
        parent = (position - 1) / 2;
    }
} // push_heap

template <class T>
void Priority_queue<T>::pop_heap(Iterator start, Iterator stop)
{
    unsigned int last_position = (stop - start) - 1;
    swap(start[0], start[last_position]);
    adjust_heap(start, last_position, 0);
} // pop_heap

template <class T>
void Priority_queue<T>::adjust_heap(Iterator start, unsigned heap_size, unsigned position)
{
    while(position < heap_size) {
        // To fix, replace position with the larger of the two children
        unsigned int child_pos = position * 2 + 1;
        if(child_pos < heap_size) {
            if((child_pos + 1 < heap_size) && start[child_pos + 1] > start[child_pos])
                child_pos++;
            // childpos is larger of two children
            if(start[position] > start[child_pos])
                // structure is now a heap
                return;
            else
                swap(start[position], start[child_pos]);
            
            position = child_pos;
        }
    }
} // adjust_heap

#endif
