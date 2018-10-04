//
//  ArbreBinaire.hpp
//  ArbreTD
//
//  Created by Nagi's Macbook Air on 10/14/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef ArbreBinaire_hpp
#define ArbreBinaire_hpp

#include <stdio.h>
#include <iostream>
#include "../Exception.hpp"

typedef int T;

class ArbreDeRecherche {
protected:
    struct Noeud {
        T valeur;
        Noeud* fg;
        Noeud* fd;
        bool couleur; //true:rouge, false:noir
    } * tete;

    void copy(const Noeud* teteOriginal, Noeud*& teteCopy);
    void destruct(Noeud* tete);
    virtual void add(const T& valeur, Noeud*& tete);
    bool search(const T& valeur, Noeud* tete);
    virtual void afficheEnOrdre(Noeud* tete);
    virtual void afficheEnPreOrdre(Noeud* tete);
    virtual void afficheEnPostOrdre(Noeud* tete);
    int size(Noeud* tete);
    int profondeur(Noeud* tete);

public:
    ArbreDeRecherche();
    ArbreDeRecherche(const ArbreDeRecherche& original);
    ArbreDeRecherche const& operator=(const ArbreDeRecherche& original);
    virtual void add(const T& valeur);
    virtual void addIterative(const T& valeur);
    bool search(const T& valeur);
    bool searchIterative(const T& valeur);
    void afficheEnOrdre();
    void afficheEnPreOrdre();
    void afficheEnPostOrdre();
    virtual void afficheEnLargeur();
    int profondeur();
    virtual ~ArbreDeRecherche();
};

#endif /* ArbreBinaire_hpp */
