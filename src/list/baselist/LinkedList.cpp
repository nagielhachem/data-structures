//
//  LinkedList.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    tete = 0;
    _size = 0;
}

LinkedList::LinkedList(LinkedList const& l)
{
    _size = l._size;
    if (l.tete == 0)
        tete = 0;
    else {
        tete = new Noeud;
        tete->v = l.tete->v;
        Noeud* from = l.tete->n;
        Noeud* to = tete;
        while (from != 0) {
            to->n = new Noeud;
            to = to->n;
            to->v = from->v;
            from = from->n;
        }
        to->n = 0;
    }
}

LinkedList const& LinkedList::operator=(LinkedList const& l)
{
    while (tete != 0) {
        Noeud* tmp = tete;
        tete = tete->n;
        delete tmp;
    }
    _size = l._size;
    if (l.tete == 0)
        tete = 0;
    else {
        tete = new Noeud;
        tete->v = l.tete->v;
        Noeud* from = l.tete->n;
        Noeud* to = tete;
        while (from != 0) {
            to->n = new Noeud;
            to = to->n;
            to->v = from->v;
            from = from->n;
        }
        to->n = 0;
    }
    return *this;
}

LinkedList::Noeud* LinkedList::node(int i)
{
    Noeud* tmp = tete;
    while (i-- > 0)
        tmp = tmp->n;
    return tmp;
}

void LinkedList::add(float value, int position)
{
    if (position < 0 || position > _size) {
        throw Exception("position error");
    }
    if (position == 0) {
        Noeud* p = new Noeud;
        if (p == 0)
            throw Exception("add Error");
        p->n = tete;
        p->v = value;
        tete = p;
    }
    else {
        Noeud* p = node(position - 1);
        Noeud* q = new Noeud();
        if (p == 0)
            throw Exception("add Error");
        q->n = p->n;
        q->v = value;
        p->n = q;
    }
    ++_size;
}

void LinkedList::add(float value)
{
    LinkedList::add(value, _size);
}

float LinkedList::get(int position)
{
    if (position < 0 || position >= _size)
        throw Exception("position error");
    return node(position)->v;
}

void LinkedList::remove(int position)
{
    if (position < 0 || position >= _size) {
        throw Exception("position error");
    }
    if (position == 0) {
        Noeud* tmp = tete;
        tete = tete->n;
        delete tmp;
    }
    else {
        Noeud* p = node(position - 1);
        Noeud* q = p->n;
        p->n = q->n;
        delete q;
    }
    --_size;
}

void LinkedList::removeFirst(float value)
{
    Noeud* p = tete;
    int k = -1;
    for (int i = 0; i < _size; ++i) {
        if (p->v == value) {
            k = i;
            break;
        }
        p = p->n;
    }
    LinkedList::remove(k);
}

bool LinkedList::find(float value)
{
    Noeud* p = tete;
    while (p != 0) {
        if (p->v == value)
            return true;
        p = p->n;
    }
    return false;
}

void LinkedList::triBulle()
{
    Noeud* t = tete;
    Noeud* p = 0;
    Noeud* q = 0;
    if (t == 0) //aucun element dans la liste.
        return;
    p = t;
    q = p->n;
    if (q == 0) //un element dans la liste => trié.
        return;
    for (int i = 0; i < _size; ++i) {
        while (q != 0) {
            if (p->v > q->v) {
                if (p == tete) {
                    //swapping des Noeuds *p et *q et inversant les pointeurs:
                    p->n = q->n;
                    q->n = p;
                    tete = q;
                    t = tete;
                }
                else {
                    //swapping des Noeuds *p et *q et inversant les pointeurs:
                    p->n = q->n;
                    q->n = p;
                    t->n = q;
                }
                //rearrangement de p et q:
                p = q;
                q = p->n;
            }
            //passer aux Noeuds suivants:
            t = p;
            p = q;
            q = p->n;
        }
        //reprendre pour la i-ème iteration:
        t = tete;
        p = t;
        q = p->n;
    }
}

void LinkedList::triFusion(Noeud*& n, int size)
{
    //condition d'arret:
    if (size <= 1) //déjà Trié
        return;

    //initialisation des variables:
    Noeud* t1 = n; //premiere partie de la liste
    Noeud* t2 = n; //deuxieme partie de la liste
    Noeud* p1 = t1; //iterateur t1
    Noeud* p2 = t2; //iterateur t2
    Noeud* tmp = 0; //zone temporaire.
    Noeud* p = 0; //iterateur de la zone temporaire
    int size1 = size / 2;
    int size2 = size / 2;
    for (int i = 0; i < size1; ++i)
        t2 = t2->n;
    //ainsi on a t1 de taille size/2
    //alors que t2 de taille size/2 si size est paire, de taille size/2 + 1 sinon.
    if (size % 2 == 1)
        ++size2;

    //recursivité:
    triFusion(t1, size1);
    triFusion(t2, size2);

    //fusion:
    p1 = t1;
    p2 = t2;
    //p1 et p2 != 0 car size > 1
    if (p1->v < p2->v) {
        tmp = new Noeud;
        tmp->v = p1->v;
        tmp->n = 0;
        p1 = p1->n;
        --size1;
    }
    else {
        tmp = new Noeud;
        tmp->v = p2->v;
        tmp->n = 0;
        p2 = p2->n;
        --size2;
    }
    p = tmp; //initialisation de l'iterateur.

    //iteration:
    while (size1 != 0 && size2 != 0) {
        if (p1->v < p2->v) {
            p->n = new Noeud;
            p = p->n;
            p->v = p1->v;
            p->n = 0;
            p1 = p1->n;
            --size1;
        }
        else {
            p->n = new Noeud;
            p = p->n;
            p->v = p2->v;
            p->n = 0;
            p2 = p2->n;
            --size2;
        }
    }

    //a la fin soit size1 = 0 soit size2 = 0
    if (size2 != 0) { //=> size1 = 0
        size1 = size2;
        p1 = p2;
    }

    for (int i = 0; i < size1; ++i) {
        p->n = new Noeud;
        p = p->n;
        p->v = p1->v;
        p->n = 0;
        p1 = p1->n;
    } //p pointe vers le dernier noeud de tmp

    p1 = t2;
    for (int i = 0; i < size2; ++i) {
        p1 = p1->n;
    } //p1 pointe vers le premier noeud de l'ancienne liste ou 0.

    //relier la nouvelle sous-liste a l'ancienne:
    p->n = p1;
    n = tmp;

    //delete de l'ancienne:
    size1 = size / 2;
    size2 = size1;
    if (size % 2 == 1)
        ++size2;
    p = t1;
    for (int i = 0; i < size1; ++i) {
        tmp = p->n;
        delete p;
        p = tmp;
    }
    p = t2;
    for (int i = 0; i < size2; ++i) {
        tmp = p->n;
        delete p;
        p = tmp;
    }
}

void LinkedList::triFusion()
{
    triFusion(tete, _size);
    node(_size - 1)->n = 0;
}

//not working!
/*
void LinkedList::triRapide(Noeud*& start, Noeud* end)
{
    //condition d'arret:
    if (start == end || end == 0 || start == 0) {
        return;
    }

    //initialisation des variables:
    float v = start->v; //pivot
    bool grand = false; //true s'il n'y a pas de valeur plus grande que v
    Noeud* prePremierGrand = 0; //pointe vers le Noeud qui precede le premier grand.
    Noeud* av = 0; //pointe vers le Noeud qui precede le prePremierGrand.
    Noeud* p = start; //iterateur: de start a end.
    Noeud* q = p->n;

    //on pointe sur les Noeud qui precede le Noeud qui nous interesse.
    //ainsi on peut permuter les Noeuds sans casser la liste.

    //iteration:
    
    do {
        if (q->v < v) {
            if (!grand) {
                av = p;
            }
            else {
                //prePremierGrand->n != 0 car on travaille sur le premier Noeud ayant une valeur inferieur au pivot
                //et au moins un Noeud ayant une valeur superieur au pivot le suit.

                //swaping du premier grand et q:
                if(q==end) //end change
                    end = prePremierGrand->n;
                Noeud* tmp = q->n;
                p->n = prePremierGrand->n; //equivaut au premier grand
                prePremierGrand->n = q;
                q->n = (p->n)->n;
                (p->n)->n = tmp;
                av = prePremierGrand; //av change
                prePremierGrand = q; //q remplace premierGrand or q->v < v donc q est prePremierGrand.
            }
        }
        else {
            if (!grand) {
                prePremierGrand = p; //pointe vers le Noeud qui precede le premier grand.
                grand = true;
            }
        }
        p = q;
        q = p->n;
    } while (p != end);

    //probleme dans l'implementation!!!
    //swaping du pivot pour le placer entre les 2 tableaux:
    if (grand) { //swap pivot avec prePremierGrand
        if (av != 0) {
            //prePremierGrand != 0 car grand = true.
            //start != 0 exception dans triRapide().
            if (av == start) {
                Noeud* tmp = prePremierGrand->n;
                prePremierGrand->n = start;
                start->n = tmp;
                start = prePremierGrand;
                av = start;
            }
            else {
                Noeud* tmp = prePremierGrand->n;
                prePremierGrand->n = start->n;
                start->n = tmp;
                av->n = start;
                start = prePremierGrand;
            }
        }
        else { //aucun element plus petit que le pivot => pas de swaping.
            av = start;
        }
    }
    else { //swaping start et end:
        Noeud* tmp = end->n;
        end->n = start->n;
        start->n = tmp;
        av->n = start;
        tmp = start;
        start = end;
        end = tmp;
        
    }

    //test:
    for (int i = 0; i < _size; ++i)
        std::cout << get(i) << " ";
    std::cout << std::endl;
    
#warning recursivité not working!

    //recursivité:
    if (av == start)
        triRapide(av->n, end);
    else{
        triRapide(start, av);
        triRapide(av->n->n, end);
    }
}

void LinkedList::triRapide()
{
    if (tete == 0)
        throw Exception("error: empty list");
    triRapide(tete, node(_size - 1));
}
*/

unsigned int LinkedList::size()
{
    return _size;
}

LinkedList::~LinkedList()
{
    while (tete != 0) {
        Noeud* tmp = tete;
        tete = tete->n;
        delete tmp;
    }
}
