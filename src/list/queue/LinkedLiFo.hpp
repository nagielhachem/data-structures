//
//  LinkedLiFo.hpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef LinkedLiFo_hpp
#define LinkedLiFo_hpp

#include "../../Exception.hpp"
#include "../baselist/LinkedList.hpp"
#include "LiFo.hpp"

class LinkedLiFo : public LiFo {
    LinkedList values;

public:
    LinkedLiFo();
    void push(float value);
    void pop();
    float top();
    bool isEmpty();
    ~LinkedLiFo();
};


#endif /* LinkedLiFo_hpp */
