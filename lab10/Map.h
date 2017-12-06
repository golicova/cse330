#ifndef MAP_H
#define MAP_H

// Map.h

#include "../lab8/Set.h"
#include "Pair.h"

using namespace std;

template < class key, class value >
class Map : public Set < Pair < key, value > >
{
public:
    typedef Set < Pair < key, value > > parent;
    typedef Set_iterator < Pair < key, value > > iterator;

    Map(): parent() {}
    
    iterator find(const key & k);
    value & operator[](const key & k);
    void erase(const key & k);
};

template < class key, class value >
typename Map<key, value>::iterator Map<key, value>::find(const key & k)
{
    return parent::find( Pair<key, value>(k, value()) );
} // find

template < class key, class value >
value & Map<key, value>::operator[](const key & k)
{
    iterator it = parent::insert(Pair<key, value> (k, value()));
    return (*it).second;
} // operator[]

template < class key, class value >
void Map<key, value>::erase(const key & k)
{
    parent::erase(Pair<key,value>(k, value()));
} // erase

#endif
