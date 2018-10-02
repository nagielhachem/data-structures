//
//  ArbreRougeNoir.hpp
//  ArbreTD
//
//  Created by Nagi's Macbook Air on 10/14/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef ArbreRougeNoir_hpp
#define ArbreRougeNoir_hpp

#include <stdio.h>
#include "ArbreDeRecherche.hpp"

class ArbreRougeNoir : public ArbreDeRecherche {
    int i;
    void afficheEnOrdre(Noeud* tete);
    void rearrangeArbre(Noeud*& grandPa, Noeud*& fils);
    void add(const T& valeur, Noeud*& tete);

public:
    ArbreRougeNoir();
    void add(const T& valeur);
    //    virtual ~ArbreRougeNoir();
};

#endif /* ArbreRougeNoir_hpp */
