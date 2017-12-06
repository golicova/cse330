#ifndef PAIR_H
#define PAIR_H

// Pair.h

using namespace std;

template < class T1, class T2 >
class Pair
{
public:
    Pair(): first(), second() {}
    Pair(const T1 & first, const T2 & second): first(first), second(second) { }
    
    bool operator==(const Pair & rhs) const { return first == rhs.first; }
    bool operator<=(const Pair & rhs) const { return first <= rhs.first; }
    bool operator<(const Pair & rhs) const { return first < rhs.first; }
    bool operator>(const Pair & rhs) const { return first > rhs.first; }

    T1 first;
    T2 second;
};

#endif
