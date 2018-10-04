//
//  Exception.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(std::string message)
    : _m(message)
{
}

std::string Exception::message() const { return _m; }

Exception::~Exception() {}