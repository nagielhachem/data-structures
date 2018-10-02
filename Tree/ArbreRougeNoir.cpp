//
//  ArbreRougeNoir.cpp
//  ArbreTD
//
//  Created by Nagi's Macbook Air on 10/14/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "ArbreRougeNoir.hpp"

ArbreRougeNoir::ArbreRougeNoir()
{
    i = 0;
}

void ArbreRougeNoir::afficheEnOrdre(Noeud* tete)
{
    if (tete == 0)
        return;
    afficheEnOrdre(tete->fg);
    std::cout << tete->valeur;
    if (tete->couleur)
        std::cout << "r ";
    else
        std::cout << "n ";
    afficheEnOrdre(tete->fd);
}

void ArbreRougeNoir::rearrangeArbre(Noeud*& grandPa, Noeud*& fils)
{
    //    Noeud* p = 0;
    //    if (fils->valeur > grandPa->valeur)
    //        p = grandPa->fd;
    //    else
    //        p = grandPa->fg;
    //    if (p->couleur == false) {
    //        //cas 2: ne rien faire.
    //    }
}

void ArbreRougeNoir::add(const T& valeur, Noeud*& tete)
{
    if (tete == 0) {
        tete = new Noeud;
        tete->valeur = valeur;
        tete->couleur = true; //on ajoutte rouge.
        tete->fg = tete->fd = 0;
    }
    else {
        if (valeur > tete->valeur) {
            add(valeur, tete->fd);
        }
        else {
            add(valeur, tete->fg);
        }
    }
}

void ArbreRougeNoir::add(const T& valeur)
{
    add(valeur, tete);
    i = 0;
}