//
//  Bug.h
//  INHERITANCE_AND_POLYMORPHISM
//
//  Created by Kristjan Thorsteinsson on 01/04/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.
//

#ifndef INHERITANCE_AND_POLYMORPHISM_Bug
#define INHERITANCE_AND_POLYMORPHISM_Bug

#include <iostream>

#include "World.h"
#include "Organism.h"

class Bug : public Organism
{
public:
    
    Bug(World* aWorld, int xcoord, int ycoord);
    // In the given world moves this organism.
    void move();
    
    // Makes this organism breed.
    void breed();
    
    // Returns the type of this organism.
    OrganismType getType() const;
    
    // The character representation of this organism.
    char representation() const;
    
    // The size of this organism.
    int size() const;
    // Returns true if organism is dead, false otherwise.
    bool isDead() const;
    
    bool in_range(int xx, int yy);
    
private:
    
    void generateOffspring(int whereX, int whereY);
    int death_tik;
};

#endif /* defined(__INHERITANCE_AND_POLYMORPHISM__Bug__) */
