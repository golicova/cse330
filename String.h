/**********
* Iulia Golicova 
* String.h
* 10/14/2017
* This program illustrates my Srting class propersties. 
**********/

#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String {
    private:
        int size;
        char * buffer;
    public:
        String();
        String(const String &);
        String(const char *);
        ~String();

        int length();
        char& operator[](int);
        String operator=(const String &);
        String& operator+=(const String &);
        friend bool operator==(const String &, const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator<(const String &, const String &);
        friend ostream & operator<<(ostream &, const String &);
};

#endif
