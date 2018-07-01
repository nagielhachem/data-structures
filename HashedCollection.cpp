#include "HashedCollection.hpp"

int HashedCollection::hash(float f)
{
    return static_cast<int>(f) % 10;
}
void HashedCollection::add(float value)
{
    int i = hash(value);
    E[i].add(value);
}
void HashedCollection::removeFirst(float value)
{
    int i = hash(value);
    E[i].remove(value);
}
bool HashedCollection::find(float value)
{
    int i = hash(value);
    return E[i].find(value);
}
unsigned int HashedCollection::size()
{
    int _size = 0;
    for (int i = 0; i < 10; ++i)
        _size += E[i].size();
    return _size;
}
