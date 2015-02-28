#include <iostream>
#include <ctime>    // for time
#include "World.h"
using namespace std;

int main()
{
    World myWorld(time(0));

    myWorld.display();

    char ch;

    while (cin.get(ch) && ch != 'q') {   // q for quit
        myWorld.simulateOneStep();
        myWorld.display();
    }

    return 0;
}
