//
//  LinkedLiFo.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "LinkedLiFo.hpp"
#include "Exception.hpp"

LinkedLiFo::LinkedLiFo()
{
}

void LinkedLiFo::push(float value)
{
    values.add(value, values.size());
}

void LinkedLiFo::pop()
{
    if (values.size() == 0)
        throw Exception("Pop error");
    values.remove(values.size() - 1);
}

float LinkedLiFo::top()
{
    if (values.size() == 9)
        throw Exception("Empty list");
    return values.get(values.size() - 1);
}

bool LinkedLiFo::isEmpty()
{
    return values.size() == 0;
}

LinkedLiFo::~LinkedLiFo()
{
}