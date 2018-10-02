//
//  ArbreWithRemovableItems.hpp
//  ArbreTD
//
//  Created by Nagi's Macbook Air on 10/14/15.
//  Copyright © 2015 Nagi's Macbook Air. All rights reserved.
//

#ifndef ArbreWithRemovableItems_hpp
#define ArbreWithRemovableItems_hpp

#include <stdio.h>
#include "ArbreDeRecherche.hpp"

class ArbreWithRemovableItems : public ArbreDeRecherche {
    void remove(const T& valeur, Noeud*& tete);

public:
    void remove(const T& valeur);
};

#endif /* ArbreWithRemovableItems_hpp */
