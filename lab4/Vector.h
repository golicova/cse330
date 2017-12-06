#ifndef VECTOR_H
#define VECTOR_H

// Vector.h

using namespace std;

template <class T>
class Vector
{
public:

    typedef T * iterator;                  // typerdef --> old new 
                                           // iterator is a pointer to type T (T for type)

    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);           // copy constructor
    ~Vector();

    unsigned int capacity() const;         // return capacity of vector (in elements)
    unsigned int size() const;             // return the number of elements in the vector
    bool empty() const;

    iterator begin();                      // return an iterator pointing to the first element
    iterator end();                        // return an iterator pointing to one past the last element
    T & front();                           // return a reference to the first element
    T & back();                            // return a reference to the last element
    void push_back(const T & value);       // add a new element
    void pop_back();                       // remove the last element

    void reserve(unsigned int capacity);   // adjust capacity
    void resize(unsigned int size);        // adjust size

    T & operator[](unsigned int index);    // return reference to numbered element
    Vector<T> operator=(const Vector<T> & source);

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;                            // an array, buffer is a pointer to type T 
};

// Two sample methods follow

template <class T>
Vector<T>::Vector()
{
     my_size = 0;
	 my_capacity = 0;
	 buffer = 0;
}

template <class T>
Vector<T>::Vector(unsigned int size)
{
    my_size = size; 
    my_capacity = size; 
    buffer = new T[size];
    
    for(int i = 0; i < size; i++) {
        buffer[i] = T();                    
    }
}

template <class T>
Vector<T>::Vector(unsigned int size, const T & initial) 
{
    my_size = size; 
    my_capacity = size; 
    buffer = new T[my_capacity];
    
    for(int i = 0; i < my_size; i++) {
        buffer[i] = initial;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_size = v.my_size; 
    my_capacity = v.my_capacity; 
    buffer = new T[my_capacity];
    
    for(int i = 0; i < my_size; i++) {
        buffer[i] = v.buffer[i];
    }
}

template <class T>
Vector<T>::~Vector()
{
    delete buffer; 
    my_size = 0; 
    my_capacity = 0; 
}

template <class T>
unsigned int Vector<T>::capacity() const
{
    return my_capacity;
}

template <class T>
unsigned int Vector<T>::size() const
{
    return my_size;
}

template <class T>
bool Vector <T>::empty() const
{
    return my_size == 0; 
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return buffer + my_size;
}

template <class T> 
T & Vector<T>::front()
{
    return * buffer; 
}

template <class T> 
T & Vector<T>::back()
{
    return * (buffer + my_size - 1); 
}

template <class T> 
void Vector<T>::push_back(const T & value) 
{
    if(my_size == my_capacity) {
        reserve(my_capacity + 5);
    }    
    buffer[my_size++] = value; 
}

template <class T> 
void Vector<T>::pop_back() 
{
    buffer[--my_size] = T();
}

template <class T> 
void Vector<T>::reserve(unsigned int capacity)
{
    if(capacity <= my_capacity)
        return; 
   
    my_capacity = capacity;
    T * temp = new T[my_capacity];
    
    for(int i = 0; i < my_size; i++) {
        temp[i] = buffer[i];
    }
    
    delete [] buffer; 
    buffer = temp; 
}

template <class T>
void Vector<T>::resize(unsigned int size)
{
    if (size > my_capacity)
        my_capacity = size; 
        
    my_size = size; 
    reserve(my_capacity);
}

template <class T>
T & Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}

template <class T>
Vector<T> Vector<T>::operator=(const Vector<T> & source)
{
    delete [] buffer; 
    my_size = source.my_size;
    my_capacity = source.my_capacity; 
    buffer = new T[my_capacity];
    
    for(int i = 0; i < my_size; i++) {
        buffer[i] = source.buffer[i];
    }
    return *this;
}

#endif
