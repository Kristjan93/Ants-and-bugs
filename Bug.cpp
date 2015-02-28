//
//  Bug.cpp
//  INHERITANCE_AND_POLYMORPHISM
//
//  Created by Kristjan Thorsteinsson on 01/04/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.
//

#include "Bug.h"
#include "Organism.h"
using namespace std;

Bug::Bug(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord)
{
    death_tik = 0;
}

void Bug::move()
{
    breedTicks++;
    death_tik++;
    
    if(world->getAt(x, y + 1) != NULL)
    {
        if(world->getAt(x, y + 1)->getType() == ANT)
        {
            death_tik = 0;
            delete world->getAt(x, y + 1);
            movesTo(x, y + 1);
            return;
        }
    }
    
    if(world->getAt(x, y - 1) != NULL)
    {
        if(world->getAt(x, y - 1)->getType() == ANT)
        {
            death_tik = 0;
            delete world->getAt(x, y - 1);
            movesTo(x, y - 1);
            return;
        }
    }
    
    if(world->getAt(x - 1, y) != NULL)
    {
        if(world->getAt(x - 1, y)->getType() == ANT)
        {
            death_tik = 0;
            delete world->getAt(x - 1, y);
            movesTo(x - 1, y);
            return;
        }
    }
    if(world->getAt(x + 1, y) != NULL)
    {
        if(world->getAt(x + 1, y)->getType() == ANT)
        {
            death_tik = 0;
            delete world->getAt(x + 1, y);
            movesTo(x + 1, y);
            return;
        }
    }
    
    Move mover = world->randomMove();
    switch (mover){
        case UP:
            if(world->getAt(x, y + 1) == NULL && in_range(x, y + 1))
            {
                movesTo(x, y + 1);
            }
            break;
        case DOWN:
            if(world->getAt(x, y - 1) == NULL && in_range(x, y - 1))
            {
                movesTo(x, y - 1);
            }
            break;
        case LEFT:
            if(world->getAt(x - 1, y) == NULL && in_range(x - 1, y))
            {
                movesTo(x - 1, y);
            }
            break;
        case RIGHT:
            if(world->getAt(x + 1, y) == NULL && in_range(x + 1, y))
            {
                movesTo(x + 1, y);
            }
            break;
        default:
            break;
    }
}

void Bug::generateOffspring(int whereX, int whereY)
{
    new Bug(this->world, whereX, whereY);
    breedTicks = 0;
}

void Bug::breed()
{
    if(breedTicks >= BREED_BUGS)
    {
        breedAtAdjacentCell();
    }
    
}

bool Bug::isDead() const
{
    if(death_tik >= STARVE_BUGS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

OrganismType Bug::getType() const
{
    return BUG;
}


char Bug::representation()const
{
    return 'X';
}

int Bug::size() const
{
    return 30;
}

bool Bug::in_range(int xx, int yy)
{
    return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE);
}
