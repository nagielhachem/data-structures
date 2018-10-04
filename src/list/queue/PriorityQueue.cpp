//
//  PriorityQueue.cpp
//  FileDePrioriteTD
//
//  Created by Nagi's Macbook Air on 10/27/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "../../Exception.hpp"
#include "PriorityQueue.hpp"
#include <iostream>

PriorityQueue::PriorityQueue(int n)
{
    _maxSize = n;
    _size = 0;
    tab = new float[n];
}

void PriorityQueue::push(float n)
{
    if (_maxSize == _size)
        throw Exception("add error");
    tab[_size] = n;
    int fils = _size;
    int pere = (fils - 1) / 2;
    while (n > tab[pere]) {
        tab[fils] = tab[pere];
        tab[pere] = n;
        if (pere != 0) {
            fils = pere;
            pere = (fils - 1) / 2;
        }
    }
    ++_size;
}

void PriorityQueue::pop()
{
    if (_size == 0)
        throw Exception("pop error");
    tab[0] = tab[_size - 1];
    --_size;
    int pere = 0;
    int max = tab[1] > tab[2] ? 1 : 2;
    while (tab[pere] < tab[max]) {
        int tmp = tab[pere];
        tab[pere] = tab[max];
        tab[max] = tmp;
        if ((2 * max + 2) < _size) { //pere n'est pas feuille
            pere = max;
            max = tab[2 * pere + 1] > tab[2 * pere + 2] ? (2 * pere + 1) : (2 * pere + 2);
        }
        else if ((2 * max + 1) < _size) {
            pere = max;
            max = 2 * pere + 1;
        }
        else
            break;
    }
}
float PriorityQueue::top()
{
    if (_size == 0)
        throw Exception("empty");
    return tab[0];
}

float PriorityQueue::get(int i)
{
    return tab[i];
}
int PriorityQueue::size()
{
    return _size;
}

void PriorityQueue::affiche()
{
    for (int i = 0; i < _size; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

PriorityQueue::~PriorityQueue()
{
    delete[] tab;
}
