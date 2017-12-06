#ifndef STRING_H
#define STRING_H

// String.h

#include <iostream>

using namespace std;

class String {
        int size;
        char * buffer;
public:
        String();
        String(const String &);
        String(const char *);
        ~String();
        String operator=(const String &);
        String operator+=(const String &);
        int length() const;
        char& operator[](int);

        // other methods

        friend bool operator==(const String &, const String &);
        friend bool operator<=(const String &, const String &);
        friend bool operator<(const String &, const String &);
        friend ostream & operator<<(ostream &, const String &);
};

#endif

