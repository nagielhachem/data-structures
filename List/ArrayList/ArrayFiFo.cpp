//
//  ArrayFiFo.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "ArrayFiFo.hpp"

ArrayFiFo::ArrayFiFo(int maxSize)
{
    v = new float[maxSize + 1];
    this->maxSize = maxSize + 1;
    from = to = 0;
}

ArrayFiFo::ArrayFiFo(ArrayFiFo const& o)
{
    v = new float[o.maxSize];
    maxSize = o.maxSize;
    from = o.from;
    to = o.to;
    for (int i = 0; i != to; i = (i + 1) % maxSize) {
        v[i] = o.v[i];
    }
}
ArrayFiFo const& ArrayFiFo::operator=(ArrayFiFo const& o)
{
    delete[] v;
    v = new float[o.maxSize];
    maxSize = o.maxSize;
    from = o.from;
    to = o.to;
    for (int i = 0; i != to; i = (i + 1) % maxSize) {
        v[i] = o.v[i];
    }
    return *this;
}

void ArrayFiFo::push(float value)
{
    if ((to + 1) % maxSize == from)
        throw Exception("add error");
    v[to] = value;
    to = (to + 1) % maxSize;
}

void ArrayFiFo::pop()
{
    if (from == to)
        throw Exception("pop error");
    from = (from + 1) % maxSize;
}

float ArrayFiFo::top()
{
    if (from == to)
        throw Exception("empty list");
    return v[from];
}

bool ArrayFiFo::isEmpty()
{
    return from == to;
}

ArrayFiFo::~ArrayFiFo()
{
    delete[] v;
}
