//
//  LinkedFiFo.hpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef LinkedFiFo_hpp
#define LinkedFiFo_hpp

#include "../FiFo.hpp"
#include "../../Exception.hpp"

class LinkedFiFo : public FiFo {
    struct Noeud {
        float v;
        Noeud* n;
    } * tete, *queue;

public:
    LinkedFiFo();
    LinkedFiFo(LinkedFiFo const&);
    LinkedFiFo const& operator=(LinkedFiFo const&);
    void push(float value);
    void pop();
    float top();
    bool isEmpty();
    ~LinkedFiFo();
};

#endif /* LinkedFiFo_hpp */
