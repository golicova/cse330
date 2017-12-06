#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

// forward declaration of classes defined in this header
template <class T> class Link;
template <class T> class List_iterator;

template <class T>
class List
{
public:
    typedef List_iterator<T> iterator;

    // constructors
    List();
    List(const List & source); // copy constructor
    ~List();

    // overloaded operators
    //ostream & operator<<(ostream & out);
    
    // other methods
    bool empty() const;
    unsigned int size() const;
    T & front() const;
    T & back() const;
    iterator begin() const;
    iterator end() const;
    void push_back(const T & x);
    void pop_back();
    void push_front(const T & x);
    void pop_front();
    void insert(iterator pos, const T & x); // insert x before pos
    void erase(iterator & pos);	// pos must be valid after erase() returns
    List<T> & operator=(const List<T> & source);

protected:
    int my_size;
    Link<T> * first_link;
    Link<T> * last_link;
}; // List class

template <class T>
List<T>::List()
{
    first_link = last_link = 0;
    my_size = 0;
} // default constructor

template <class T>
List<T>::List(const List & source)
{
	while(!empty())
		pop_back();

    first_link = last_link = 0;
    my_size = 0;
    for(Link<T> * current = source.first_link; current != 0; 
					current = current->next_link)
        push_back(current->value);

} // copy constructor

template <class T>
List<T>::~List()
{
	while(!empty())
		pop_back();
} // deconstructor

template <class T>
bool List<T>::empty() const
{
    if(my_size == 0)
        return true; 
    return false; 
} // empty

template <class T>
unsigned int List<T>::size() const
{
    return my_size;
} // size

template <class T>
T & List<T>::front() const
{
    return *begin();
} // front

template <class T>
T & List<T>::back() const
{
    return *end();
} // back

template <class T>
typename List<T>::iterator List<T>::begin() const
{
	return iterator(first_link);
}

template <class T>
typename List<T>::iterator List<T>::end() const
{
    if(last_link == 0) // end case: empty List
        return last_link;

	return iterator(last_link->next_link);
}

template <class T>
void List<T>::push_back(const T & x)
{
    Link<T> * new_link = new Link<T>(x);
    if(new_link == 0) {
		cout << "out of memory\n";
		exit(1);
	}
    
    if(first_link == 0) 
		first_link = last_link = new_link; 
	else {
		new_link->prev_link = last_link;
		last_link->next_link = new_link;
		last_link = new_link;
	}

	my_size++;
} // push_back

template <class T>
void List<T>::pop_back()
{
	if(first_link == 0) 
		return;
	
	Link<T> * temp_link = last_link;
	
	if(my_size == 1) 
		last_link = first_link = 0;
	else {
        last_link = temp_link->prev_link;
        last_link->next_link = 0;
	}
	
	delete temp_link;
	my_size--;
} // pop_back

template <class T>
void List<T>::push_front(const T & x)
{
    Link<T> * new_link = new Link<T>(x);
    if(new_link == 0) {
		cout << "out of memory\n";
		exit(1);
	}
    
    if(first_link == 0) 
		first_link = last_link = new_link; 
	else {
		new_link->next_link = first_link;
		first_link->prev_link = new_link;
		first_link = new_link;
	}

	my_size++;
} // push_front

template <class T>
void List<T>::pop_front()
{
	if(first_link == 0) 
		return;

	Link<T> * temp_link = first_link;
	
	if(my_size == 1) 
		last_link = first_link = 0;
	else {
        first_link = temp_link->next_link;
        first_link->prev_link = 0;
	}
	
	delete temp_link;
	my_size--;
} // pop_front

template <class T>
void List<T>::insert(iterator pos, const T & x)
{
    Link<T>* new_link = new Link<T> (x); 
    if(new_link == 0) {
        cout << "Error.";
        exit(1);
    }
    
    my_size++; 
    Link<T> * next = pos.current_link;
    if(next == 0) {
        first_link = last_link = new_link;
        return;
    }
    Link<T> * prev = pos.current_link->prev_link;
    new_link -> next_link = next; 
    new_link -> prev_link = prev;
    if(prev == 0) {
        prev->next_link = new_link;
    }
} 

template <class T>
void List<T>::erase(iterator & pos)
{
    if(my_size == 0)   
        return;

	Link<T> * next = pos.current_link->next_link;
	Link<T> * prev = pos.current_link->prev_link;
	
	if(next == 0) 
		last_link = prev;
	else
		next->prev_link = prev;
	
	if(prev == 0) 
		first_link = next;
	else
		prev->next_link = next;
	
	delete pos.current_link;
	my_size--;

    if(next != 0) 
        pos.current_link = next;
    else if(prev != 0)
        pos.current_link = prev;
    else
        pos.current_link = 0;
}

template <class T>
List<T> & List<T>::operator=(const List<T> & source)
{
	while(!empty()) 
		pop_back();

    first_link = last_link = 0;

    for(iterator current = source.begin(); current != source.end(); current++)
        push_back(current.current_link->value);

    return *this;
} // operator=


template <class T> 
class Link 
{
private:
   Link(const T & x): value(x), next_link(0), prev_link(0) {}
                
   T value;     
   Link<T> * next_link;
   Link<T> * prev_link;

   friend class List<T>;
   friend class List_iterator<T>;
};

/*
template <class T>
Link<T>::Link()
{
    value = T();
    next_link = prev_link = 0;
} // default constructor

template <class T>
Link<T>::Link(const T & x)
{
    value = x;
    next_link = prev_link = 0;
} // constructor

template <class T>
Link<T>::Link(const Link & source)
{
    value = source.value;
    next_link = source.next_link;
    prev_link = source.prev_link;
} // copy constructor
*/

template <class T>
class List_iterator
{
public:
	typedef List_iterator<T> iterator;
	
	// constructors
	List_iterator(): current_link(0) { } // default constructor
	List_iterator(Link<T> * source_link): current_link(source_link) { }
	List_iterator(List_iterator<T> * source): current_link(source.current_link) { }
	
	// overloaded operators
	T & operator*(); // dereferencing operator
	iterator & operator=(const iterator & rhs);
	bool operator==(const iterator & rhs) const;
	bool operator!=(const iterator & rhs) const;
	iterator & operator++();  // pre-increment, ex. ++it
	iterator operator++(int); // post-increment, ex. it++
	iterator & operator--();  // pre-decrement
	iterator operator--(int); // post-decrement

protected:
	Link<T> * current_link;
	
	friend class List<T>;
}; // List_iterator class

template <class T>
T & List_iterator<T>::operator*()
{
	return current_link->value;
} // operator*

template <class T>
List_iterator<T> & List_iterator<T>::operator=(const iterator & source)
{
	current_link = source.current_link;
	return *this;
} // operator=

template <class T>
bool List_iterator<T>::operator==(const iterator & source) const
{
	return current_link == source.current_link;
}

template <class T>
bool List_iterator<T>::operator!=(const iterator & source) const
{
	return current_link != source.current_link;
}

template <class T>
List_iterator<T> & List_iterator<T>::operator++()
{
	current_link = current_link->next_link;
	return *this;
} // operator++ (pre-increment

template <class T>
List_iterator<T> List_iterator<T>::operator++(int)
{
	Link<T> * temp_link = current_link;
	current_link = current_link->next_link;
	return temp_link;
} // operator++ (post-increment)

template <class T>
List_iterator<T> & List_iterator<T>::operator--()
{
	current_link = current_link->prev_link;
	return *this;
} // operator-- (pre-decrement)

template <class T>
List_iterator<T> List_iterator<T>::operator--(int)
{
	Link<T> * temp_link = current_link;
	current_link = current_link->prev_link;
	return temp_link;
} // operator-- (post-decrement)

#endif
