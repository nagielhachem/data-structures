//
//  ArrayList.cpp
//  CollectionsTd
//
//  Created by Nagi's Macbook Air on 10/8/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "ArrayList.hpp"
#include <iostream>

void ArrayList::copy(ArrayList const& original)
{
    _size = original._size;
    memcpy(a, original.a, _size * sizeof(float));
}

ArrayList::ArrayList(int maxSize)
{
    this->maxSize = maxSize;
    a = new float[maxSize];
    _size = 0;
}

ArrayList::ArrayList(ArrayList const& original)
{
    this->maxSize = original.maxSize;
    a = new float[maxSize];
    copy(original);
}

ArrayList const& ArrayList::operator=(ArrayList const& original)
{
    delete[] a;
    this->maxSize = original.maxSize;
    a = new float[maxSize];
    copy(original);
    return *this;
}

void ArrayList::add(float value, int position)
{
    if (_size == maxSize)
        throw Exception("add error");
    if (position < 0 || position > _size)
        throw Exception("position error");
    for (int i = _size - 1; i >= position; --i) {
        a[i + 1] = a[i];
    }
    a[position] = value;
    ++_size;
}

void ArrayList::add(float value)
{
    ArrayList::add(value, _size);
}

void ArrayList::remove(int position)
{
    if (position < 0 || position >= _size) {
        throw Exception("position error");
    }
    for (int i = position + 1; i < _size; ++i) {
        a[i - 1] = a[i];
    }
    --_size;
}

void ArrayList::removeFirst(float value)
{
    int k = -1;
    for (int i = 0; i < _size; ++i) {
        if (a[i] == value) {
            k = i;
            break;
        }
    }
    ArrayList::remove(k);
    --_size;
}

float ArrayList::get(int position)
{
    if (position < 0 || position >= _size) {
        throw Exception("position error");
    }
    return a[position];
}

bool ArrayList::find(float value)
{
    for (int i = 0; i < _size; ++i) {
        if (a[i] == value)
            return true;
    }
    return false;
}

void ArrayList::triBulle()
{
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                float b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }
}

void ArrayList::triMinMax()
{
    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
        for (int j = _size - i - 1; j > i; --j) {
            if (a[j] < a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

void ArrayList::triInsertion()
{
    for (int i = 1; i < _size; ++i) {
        for (int j = i; j > 0; --j) {
            if (a[j] < a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

void ArrayList::triRapide(int debut, int fin)
{
    //condition d'arret:
    if ((fin - debut) <= 1)
        return;

    //initialisation des variables:
    float v = a[debut];
    bool grand = false; //true s'il n'y a pas de valeur plus grande que v
    int premierGrand = 0; //index de la premiere valeur plus grande que v

    //iteration:
    for (int i = debut + 1; i < fin; ++i) {
        if (a[i] < v) {
            if (grand) {
                //swaping de a[i] avec le premier plus grand:
                float tmp = a[premierGrand];
                a[premierGrand] = a[i];
                a[i] = tmp;
                ++premierGrand;
            }
        }
        else {
            if (!grand) {
                premierGrand = i;
                grand = true;
            }
        }
    }
    //swaping du pivot pour le placer entre les 2 tableaux:
    if (grand) { //placer le pivot avant le premier grand
        v = a[premierGrand - 1];
        a[premierGrand - 1] = a[debut];
        a[debut] = v;
    }
    else { //placer le pivot a la fin
        v = a[fin - 1];
        a[fin - 1] = a[debut];
        a[debut] = v;
        premierGrand = fin; //pour assurer la bonne recursivité
    }

    //recursivité:
    triRapide(debut, premierGrand - 1); //partie gauche sans pivot
    triRapide(premierGrand, fin); //partie droite sans pivot
}

void ArrayList::triRapide()
{
    triRapide(0, _size);
}

unsigned int ArrayList::size()
{
    return _size;
}

ArrayList::~ArrayList()
{
    delete[] a;
}
