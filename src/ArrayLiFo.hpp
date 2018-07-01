//
//  ArrayLiFo.hpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef ArrayLiFo_hpp
#define ArrayLiFo_hpp

#include "ArrayList.hpp"
#include "LiFo.hpp"

class ArrayLiFo : public LiFo {
    ArrayList values;
    
public:
    ArrayLiFo(int maxSize);
    void push(float value);
    void pop();
    float top();
    bool isEmpty();
    ~ArrayLiFo();
};

#endif /* ArrayLiFo_hpp */
