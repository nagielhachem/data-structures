//
//  ArrayList.hpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include "../../Exception.hpp"
#include "List.hpp"

class ArrayList : public List {
    float* a;
    int maxSize, _size;
    void copy(ArrayList const& original);
    void triRapide(int debut, int fin);
public:
    ArrayList(int maxSize);
    ArrayList(ArrayList const& original);
    ArrayList const& operator=(ArrayList const& original);
    void add(float value, int position);
    void add(float value);
    void remove(int position);
    void removeFirst(float value);
    float get(int position);
    bool find(float value);
    void triBulle();
    void triMinMax();
    void triInsertion();
    void triRapide();
    unsigned int size();
    ~ArrayList();
};

#endif /* ArrayList_hpp */
