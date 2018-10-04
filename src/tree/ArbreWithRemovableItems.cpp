//
//  ArbreWithRemovableItems.cpp
//  ArbreTD
//
//  Created by Nagi's Macbook Air on 10/14/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#include "ArbreWithRemovableItems.hpp"

void ArbreWithRemovableItems::remove(const T& valeur, Noeud*& tete)
{
    if (tete == 0)
        throw Exception("remove error");
    if (valeur == tete->valeur) {
        if (tete->fg == 0) {
            Noeud* tmp = tete->fd;
            delete tete;
            tete = tmp;
        }
        else {
            Noeud* tmpFg = tete->fg;
            Noeud* tmp = tete->fg;
            while (tmp->fd != 0) {
                tmp = tmp->fd;
            }
            tmp->fd = tete->fd;
            delete tete;
            tete = tmpFg;
        }
    }
    else if (valeur > tete->valeur)
        remove(valeur, tete->fd);
    else
        remove(valeur, tete->fg);
}

void ArbreWithRemovableItems::remove(const T& valeur)
{
    remove(valeur, tete);
}