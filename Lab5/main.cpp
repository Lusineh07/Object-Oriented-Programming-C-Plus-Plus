#include <iostream> 
#include "RPG.h"
using namespace std;

int main(){
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    printf("%s Currebt Status\n", p1.getName().c_str());
    printf("Health: %i\t Strenght: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    printf("%s Current Status\n", p2.getName().c_str());
    printf("Health: %d\t Strength: %d\t Defense: %d\n", p2.getHealth(), p2.getStrength(), p2.getDefense());

    // Call updateHealth(0) on p1
    p1.updateHealth(0);

    // Print the new health
    printf("New Health of %s: %d\n", p1.getName().c_str(), p1.getHealth());

    //isAlive() for p1 and p2
    printf("%s is %s\n", p1.getName().c_str(), p1.isAlive() ? "alive" : "dead");
    printf("%s is %s\n", p2.getName().c_str(), p2.isAlive() ? "alive" : "dead");

    return 0;
}

