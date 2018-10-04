//
//  ArbreBinaire.cpp
//  ArbreTD
//
//  Created by Nagi's Macbook Air on 10/14/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "ArbreDeRecherche.hpp"
#include <queue>

void ArbreDeRecherche::copy(const Noeud* teteOriginal, Noeud*& teteCopy)
{
    if (teteOriginal == 0) {
        teteCopy = 0;
        return;
    }
    teteCopy = new Noeud;
    teteCopy->valeur = teteOriginal->valeur;
    teteCopy->couleur = teteOriginal->couleur;

    copy(teteOriginal->fg, teteCopy->fg);
    copy(teteOriginal->fd, teteCopy->fd);
}

void ArbreDeRecherche::destruct(Noeud* tete)
{
    if (tete == 0)
        return;
    Noeud* tmpFg = tete->fg;
    Noeud* tmpFd = tete->fd;
    delete tete;
    destruct(tmpFg);
    destruct(tmpFd);
}

void ArbreDeRecherche::add(const T& valeur, Noeud*& tete)
{
    if (tete == 0) {
        tete = new Noeud;
        tete->valeur = valeur;
        tete->fg = tete->fd = 0;
    }
    else {
        if (valeur > tete->valeur)
            return add(valeur, tete->fd);
        else
            return add(valeur, tete->fg);
    }
}

bool ArbreDeRecherche::search(const T& valeur, Noeud* tete)
{
    if (tete == 0)
        return false;
    if (valeur == tete->valeur)
        return true;
    else if (valeur > tete->valeur)
        return search(valeur, tete->fd);
    else
        return search(valeur, tete->fg);
}

void ArbreDeRecherche::afficheEnOrdre(Noeud* tete)
{
    if (tete == 0)
        return;
    afficheEnOrdre(tete->fg);
    std::cout << tete->valeur << " ";
    afficheEnOrdre(tete->fd);
}
void ArbreDeRecherche::afficheEnPreOrdre(Noeud* tete)
{
    if (tete == 0)
        return;
    std::cout << tete->valeur << " ";
    afficheEnOrdre(tete->fg);
    afficheEnOrdre(tete->fd);
}
void ArbreDeRecherche::afficheEnPostOrdre(Noeud* tete)
{
    if (tete == 0)
        return;
    afficheEnOrdre(tete->fg);
    afficheEnOrdre(tete->fd);
    std::cout << tete->valeur << " ";
}

int ArbreDeRecherche::size(Noeud* tete)
{
    if (tete == 0)
        return 0;
    return 1 + size(tete->fg) + size(tete->fd);
}

int ArbreDeRecherche::profondeur(Noeud* tete)
{
    if (tete == 0)
        return 0;
    int n1 = profondeur(tete->fg);
    int n2 = profondeur(tete->fd);
    return 1 + (n1 > n2 ? n1 : n2);
}

//public:

ArbreDeRecherche::ArbreDeRecherche() { tete = 0; }

ArbreDeRecherche::ArbreDeRecherche(const ArbreDeRecherche& original)
{
    copy(original.tete, tete);
}
ArbreDeRecherche::~ArbreDeRecherche()
{
    destruct(tete);
}
ArbreDeRecherche const& ArbreDeRecherche::operator=(const ArbreDeRecherche& original)
{
    destruct(tete);
    copy(original.tete, tete);
    return *this;
}
void ArbreDeRecherche::add(const T& valeur)
{
    add(valeur, tete);
}
void ArbreDeRecherche::addIterative(const T& valeur)
{
    Noeud** tmp = &tete;
    while (*tmp != 0) {
        if (valeur > (*tmp)->valeur)
            tmp = &((*tmp)->fd);
        else
            tmp = &((*tmp)->fg);
    }
    *tmp = new Noeud;
    (*tmp)->valeur = valeur;
    (*tmp)->fd = 0;
    (*tmp)->fg = 0;
}
bool ArbreDeRecherche::search(const T& valeur)
{
    return search(valeur, tete);
}
bool ArbreDeRecherche::searchIterative(const T& valeur)
{
    Noeud* tmp = tete;
    while (tmp != 0) {
        if (tmp->valeur == valeur)
            return true;
        if (valeur > tmp->valeur)
            tmp = tmp->fd;
        else
            tmp = tmp->fg;
    }
    return false;
}
void ArbreDeRecherche::afficheEnOrdre()
{
    afficheEnOrdre(tete);
}
void ArbreDeRecherche::afficheEnPreOrdre()
{
    afficheEnPreOrdre(tete);
}
void ArbreDeRecherche::afficheEnPostOrdre()
{
    afficheEnPostOrdre(tete);
}

void ArbreDeRecherche::afficheEnLargeur()
{
    std::queue<Noeud*> q;
    Noeud* p;
    q.push(tete);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p->fg != 0)
            q.push(p->fg);
        if (p->fd != 0)
            q.push(p->fd);
        std::cout << p->valeur << " ";
    }
}

int ArbreDeRecherche::profondeur()
{
    return profondeur(tete);
}
