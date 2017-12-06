#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double-ended queue

#include <vector>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque {
public:
	typedef DequeIterator<T> iterator;
	
	Deque(): vecOne(), vecTwo() { }
	Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
	Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }
        ~Deque() { } // destructors for vecOne and vecTwo are automatically called
                     // never call a destructor explicitly
        Deque & operator=(const Deque<T> & d);

	T & operator[](unsigned int);
	T & front();
	T & back();
	bool empty();
	iterator begin();
	iterator end();
    void erase(const iterator &);
	void erase(const iterator &, const iterator &);
	void insert(const iterator &, const T &);
	int size();
	void push_front(const T & value);
	void push_back(const T & value);
	void pop_front();
	void pop_back();
protected:
	vector<T> vecOne;
	vector<T> vecTwo;
};

template <class T>
Deque<T> & Deque<T>::operator=(const Deque<T> & d)
{
    vecOne = d.vecOne;
    vecTwo = d.vecTwo;
    
    return *this;
} // operator=

template <class T>
T & Deque<T>::operator[](unsigned int index)
{
    unsigned int n = vecOne.size();
    if(index < n)
        return vecOne[(n-1) - index];
    else
        return vecTwo[index - n];
} // operator []

template <class T>
T & Deque<T>::front()
{
    if(!empty()){
        if(vecOne.empty()) {
		    return vecOne.back();
	}
	else 
	    return vecTwo.front();
    }
} // front 

template <class T> 
T & Deque<T>::back()
{
    if(!empty()){
        if(vecTwo.empty()) {
		    return vecTwo.back();
	}
    return vecOne.front();
    }
} // back

template <class T>
bool Deque<T>::empty()
{
	return (vecOne.empty() && vecTwo.empty());
} // empty 

template <class T>
DequeIterator<T> Deque<T>::begin()
{
    return iterator(this, 0);
} // begin

template <class T>
DequeIterator<T> Deque<T>::end()
{
    return iterator(this, size());
} // end

template <class T>
void Deque<T>::erase(const iterator & itr)
{
    if(!empty()) {
        int index = itr.index; 
        int n = vecOne.size();
        if(index < n) 
            vecOne.erase(vecOne.begin() + ((n-1) - index));
        else 
            vecTwo.erase(vecTwo.begin() + (index - n));
    }
} // erase 

template <class T>
void Deque<T>::erase(const iterator & itr_a, const iterator & itr_b)
{
    int index_a = itr_a.index;
    int index_b = itr_b.index;
    int n = vecOne.size();
    for(int i = 0; i < index_b - index_a; i++) {
        erase(itr_a);
    }
} // erase range 

template <class T>
void Deque<T>::insert(const iterator & itr, const T & value)
{
    if(itr.index < vecOne.size())
        vecOne.insert(vecOne.end() + (vecOne.size() - 1 - itr.index), value);
    else 
        vecTwo.insert(vecTwo.begin() + (vecOne.size() - itr.index), value);
} // erase

template <class T>
int Deque<T>::size()
{
    return vecOne.size() + vecTwo.size();
} // size

template <class T>
void Deque<T>::push_front(const T & value)
{
    vecOne.push_back(value);
} // push_front

template <class T>
void Deque<T>::push_back(const T & value)
{
    vecTwo.push_back(value);
} // push_back

template <class T>
void Deque<T>::pop_front()
{
    if(vecOne.empty())
        vecTwo.erase(vecTwo.begin());
    else
        vecOne.pop_back();
} // pop_front

template <class T>
void Deque<T>::pop_back()
{
    if(vecTwo.empty()) {
        cout << "running pop_back if\n";
        vecOne.erase(vecOne.begin());
    } else {
        cout << "running pop_back else\n";
        vecTwo.pop_back();
    }
} // pop_back

template <class T>
class DequeIterator {
	friend class Deque<T>;
	typedef DequeIterator<T> iterator;
public:
	DequeIterator(): theDeque(0), index(0) { }
	DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
	DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

	T & operator*();
	iterator & operator++();
	iterator operator++(int);
	iterator & operator--();
	iterator operator--(int);
	bool operator==(const iterator & r);
	bool operator!=(const iterator & r);
	bool operator<(const iterator & r);
	T & operator[](unsigned int i);
	iterator operator=(const iterator & r);
	iterator operator+(int i) {return iterator(theDeque, index + i);}
	iterator operator-(int i) {return iterator(theDeque, index - i);};
protected:
	Deque<T> * theDeque;
	int index;
};

template <class T>
T & DequeIterator<T>::operator*()
{
    return (*theDeque)[index];
} // operator*

template <class T>
DequeIterator<T> & DequeIterator<T>::operator++()
{
    if( index < ( theDeque->size() ) )
        index++;

    return *this;
} // operator++ (pre-increment)

template <class T>
DequeIterator<T> DequeIterator<T>::operator++(int)
{
    iterator temp(*this);
    if( index < ( theDeque->size() ) )
        index++;

    return temp;
} // operator++ (post-increment)

template <class T>
DequeIterator<T> & DequeIterator<T>::operator--()
{
    if(index > 0)
        index--;
        
    return *this;
} // operator-- (pre-decrement)

template <class T>
DequeIterator<T> DequeIterator<T>::operator--(int)
{
    iterator temp(*this);
    if(index > 0)
        index--;
        
    return temp;
} // operator-- (post-decrement)

template <class T>
bool DequeIterator<T>::operator==(const iterator & r)
{
    return (index == r.index) && (theDeque == r.theDeque);
} // operator==

template <class T>
bool DequeIterator<T>::operator!=(const iterator & r)
{
    return !( (index == r.index) && (theDeque == r.theDeque) );
} // operator!=

template <class T>
bool DequeIterator<T>::operator<(const iterator & r)
{
    return theDeque == r.theDeque && index < r.index;
} // operator <

template <class T>
T & DequeIterator<T>::operator[](unsigned int i)
{
	return (*theDeque) [index + 1];
}

template <class T>
DequeIterator<T> DequeIterator<T>::operator=(const iterator & r)
{
    theDeque = r.theDeque;
    index = r.index;
    
    return *this;
} // operator=

#endif
