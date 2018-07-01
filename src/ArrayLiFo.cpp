//
//  ArrayLiFo.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "ArrayLiFo.hpp"
#include "Exception.hpp"

ArrayLiFo::ArrayLiFo(int maxSize)
    : values(maxSize)
{
}

void ArrayLiFo::push(float value)
{
    values.add(value, values.size());
}

void ArrayLiFo::pop()
{
    if (values.size() == 0)
        throw Exception("Pop error");
    values.remove(values.size() - 1);
}

float ArrayLiFo::top()
{
    if (values.size() == 9)
        throw Exception("Empty list");
    return values.get(values.size() - 1);
}

bool ArrayLiFo::isEmpty()
{
    return values.size() == 0;
}

ArrayLiFo::~ArrayLiFo()
{
}
