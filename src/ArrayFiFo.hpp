//
//  ArrayFiFo.hpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef ArrayFiFo_hpp
#define ArrayFiFo_hpp

#include "FiFo.hpp"

class ArrayFiFo : public FiFo {
    float* v;
    int from, to, maxSize;
    
public:
    ArrayFiFo(int maxSize);
    ArrayFiFo(ArrayFiFo const&);
    ArrayFiFo const& operator=(ArrayFiFo const&);
    void push(float value);
    void pop();
    float top();
    bool isEmpty();
    ~ArrayFiFo();
};

#endif /* ArrayFiFo_hpp */
