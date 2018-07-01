//
//  LinkedList.hpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "List.hpp"

class LinkedList : public List {

    struct Noeud {
        float v;
        Noeud* n;
    } * tete;

    int _size;
    Noeud* node(int i);
    void triFusion(Noeud*& n, int size);
    //    void triRapide(Noeud*& start, Noeud* end);

public:
    LinkedList();
    LinkedList(LinkedList const&);
    LinkedList const& operator=(LinkedList const&);
    void add(float value, int position);
    void add(float value);
    void remove(int position);
    void removeFirst(float value);
    float get(int position);
    bool find(float value);
    void triBulle();
    void triFusion();
    //    void triRapide();
    unsigned int size();
    virtual ~LinkedList();
};

#endif /* LinkedList_hpp */
