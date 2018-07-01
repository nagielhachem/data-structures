#pragma once
#include "Collection.hpp"

class List : public Collection {
public:
    virtual void add(float value, int position) = 0;
    //  throws Exception("add error") if adding fails
    //  throws Exception("position error") for invalid position errors

    virtual void remove(int position) = 0;
    //  throws Exception("position error") for invalid position errors

    virtual float get(int position) = 0;
    //  throws Exception("position error") for invalid position errors

    virtual unsigned int size() = 0;

    virtual ~List() {}
};
