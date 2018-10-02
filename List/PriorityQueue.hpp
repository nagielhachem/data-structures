//
//  PriorityQueue.hpp
//  FileDePrioriteTD
//
//  Created by Nagi's Macbook Air on 10/27/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

class PriorityQueue {
    float* tab;
    int _maxSize, _size;

public:
    PriorityQueue(int n);
    virtual ~PriorityQueue();
    void push(float n);
    void pop();
    float top();
    float get(int i);
    int size();
    void affiche();
};

#endif /* PriorityQueue_hpp */
