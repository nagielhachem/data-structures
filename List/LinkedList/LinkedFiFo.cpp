//
//  LinkedFiFo.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "LinkedFiFo.hpp"

LinkedFiFo::LinkedFiFo()
{
    tete = 0;
}

LinkedFiFo::LinkedFiFo(LinkedFiFo const& o)
{
    tete = 0;
    Noeud* tmp = o.tete;
    while (tmp != 0) {
        push(tmp->v);
        tmp = tmp->n;
    }
}

LinkedFiFo const& LinkedFiFo::operator=(LinkedFiFo const& o)
{
    while (tete != 0) {
        Noeud* tmp = tete;
        tete = tete->n;
        delete tmp;
    }
    Noeud* tmp = o.tete;
    while (tmp != 0) {
        push(tmp->v);
        tmp = tmp->n;
    }
    return *this;
}

void LinkedFiFo::push(float value)
{
    if (tete == 0) {
        tete = queue = new Noeud;
        if (tete == 0)
            throw Exception("add error");
        tete->v = value;
    }
    else {
        queue->n = new Noeud;
        if (queue->n == 0)
            throw Exception("add error");
        queue = queue->n;
        queue->v = value;
        queue->n = 0;
    }
}

void LinkedFiFo::pop()
{
    if (tete == 0)
        throw Exception("pop error");
    Noeud* tmp = tete;
    tete = tete->n;
    delete tmp;
}

float LinkedFiFo::top()
{
    if (tete == 0)
        throw Exception("empty list");
    return tete->v;
}

bool LinkedFiFo::isEmpty()
{
    return tete == 0;
}

LinkedFiFo::~LinkedFiFo()
{
    while (tete != 0) {
        Noeud* tmp = tete;
        tete = tete->n;
        delete tmp;
    }
}
