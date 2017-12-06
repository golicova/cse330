/**********
* Iulia Golicova
* String.cpp
* 10/14/2017
* This program illustrates my String class functions.
**********/

#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

//Constructor 
String::String()
{
    size = 0;
    buffer = NULL;
}

//Constructor 
String::String(const String& original)
{
    size = original.size;
    buffer = new char[size];
    for(int i=0; i<size; i++)
        buffer[i] = original.buffer[i];
}

//Constructor 
String::String(const char *c_string)
{
    size = strlen(c_string);
    buffer = new char[size];
    for(int i=0; i<size; i++)
        buffer[i] = c_string[i];
}

//Deconstructor 
String::~String()
{
    delete [] buffer;
}

//Length 
int String::length()
{
    return size;
}

//Operator[]
char& String::operator[](int index)
{
    if(index > size) {
        cout << "Error.\n";
        
        return buffer[0];
    }
    return buffer[index];
} 

//Operator=
String String::operator=(const String& source)
{
    if(this == &source) 
        return *this;
    delete [] buffer;
    size = source.size;
    buffer = new char[size];
    for(int i=0; i<size; i++)
        buffer[i] = source.buffer[i];
    return *this;
} 


String& String::operator+=(const String& right)
{
    String temp(*this); // Copy original string
    delete [] buffer;
    size = right.size + temp.size; // New size = old size + right.size
    buffer = new char[size];
    for(int i=0; i < temp.size; i++) // Insert original string
        buffer[i] = temp[i];
    for(int i=0; i < right.size; i++)
        buffer[i+temp.size] = right.buffer[i]; // Append new string

    return *this;
} // operator+=

bool operator==(const String& left, const String& right)
{
    if(left.size != right.size)
        return false;
    for(int i=0; i<left.size; i++)
        if(left.buffer[i] != right.buffer[i])
            return false;
    return true;
} // operator==

bool operator<=(const String& left, const String& right)
{
    if(left.size > right.size)
        return false;
    for(int i=0; i<left.size; i++)
        if(left.buffer[i] > right.buffer[i])
            return false;
    return true;
} // operator<=

bool operator<(const String& left, const String& right)
{
    if(left.size >= right.size)
        return false;
    for(int i=0; i<left.size; i++)
        if(left.buffer[i] >= right.buffer[i])
            return false;
    return true;
} // operator<

ostream& operator<<(ostream& out, const String& source)
{
    for(int i=0; i<source.size; i++)
        out << source.buffer[i];
    return out;
} // operator<<

