#include "String.h"
#include<cstring>

using namespace std;

//This is the definition for the default constructor
String::String()
{
    size = 0;
    buffer = 0;
}

//This is the definition for the constuctor that takes in the parameter String&
String::String(const String & op)
{
    size = op.size;
    buffer = new char[size];
    for(int i = 0; i < size; i++)
        buffer[i] = op.buffer[i];
}

//This is the definition for the constructor that initializes a String from a cstring
String::String(const char * s)
{
    int len = strlen(s);
    buffer = new char[len];
    for(int i = 0; i < len; i++)
        buffer[i] = s[i];
    size = len;
}

//This is the definition for the destructor
String::~String()
{
    delete [] buffer;
}

//This is the definition for the member function for length
int String::length() const
{
    for(int i = 0; i < size; i++)
        if(buffer[i] == '\0')
            return i;
return size;
}

//This is the definition to overload [] operator
char& String::operator[](int b)
{
    return buffer[b];
}

//This is the definition to overload the assignment (=) operator
String String::operator=(const String & op)
{
    delete[] buffer;
    size = op.size;
    buffer = new char[size];
    for(int i = 0; i < size; i++)
        buffer[i] = op.buffer[i];
     return *this;
}

//This is the definition to overload the += operator
String String::operator+=(const String & op)
{
    int temp_size = size + op.size;
    char * temp;
    temp = new char[temp_size];
    int i;
    for(i = 0; i < size; i++)
    temp[i] = buffer[i];

    for(int j = 0; j < op.size; j++, i++)
        temp[i] = op.buffer[j];
    delete [] buffer;
    size = temp_size;
    buffer = temp;
    return *this;
}
//This is the definition to overload the == operator
bool operator==(const String & op, const String & po)
{
    if(op.size != po.size)
        return false;
    else {
        for(int i = 0; i < op.size; i++) {
            if(op.buffer[i] != po.buffer[i])
                return false;
        }
    }
    return true;
}

//This is the definition to overload the <= operator
bool operator<=(const String & op, const String & po)
{
    if(op.size > po.size)
        return false;
    for(int i = 0; i < op.size; i++)
        if(op.buffer[i] > po.buffer[i])
            return false;
    return true;
}

//This is the definition to overload the < operator
bool operator<(const String & op, const String & po)
{
    if(op.size > po.size)
        return false;
    for(int i = 0; i < op.size; i++)
        if(op.buffer[i] > po.buffer[i])
            return false;
    return true;
}

//This is the definiton to overload the output (<<) operator
ostream & operator <<(ostream & out, const String & s)
{
    for(int i = 0; i < s.size; i++)
        out << s.buffer[i];
    return out;
}
