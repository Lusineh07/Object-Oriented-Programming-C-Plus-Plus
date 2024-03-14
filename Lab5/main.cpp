#include <iostream> 
#include "RPG.h"
using namespace std;

void displayStats (RPG player1, RPG player2){
    printf("%s health: %d\t %s health: %d\n", player1.getName().c_str(), player1.getHealth(), player2.getName().c_str(), player2.getHealth());
}

void displayEnd (RPG player1, RPG player2){
    if (player1.isAlive() == true){
        printf("%s defeated %s! Good game!\n ", player1.getName().c_str(), player2.getName().c_str());
    } else{
        printf("%s defeated %s! Good game!\n ", player2.getName().c_str(), player1.getName().c_str());
    }
}

void gameLoop (RPG * player1, RPG * player2){
    while ((*player1).isAlive() && (*player2).isAlive()) {
        displayStats(*player1, *player2);

        // Player 1 turn
        printf("It's %s's turn.\n", (*player1).getName().c_str());
        (*player1).useSkill(player2);
        printf("------------------------\n");

        // Is player 2 alive after player 1 turn?
        if (!(*player2).isAlive()) break;

        displayStats(*player1, *player2);

        // Player 2 turn
        printf("It's %s's turn.\n", (*player2).getName().c_str());
        (*player2).useSkill(player1);
        printf("------------------------\n");
    }
}

int main(){
    RPG p1 = RPG("Wiz", 70, 15, 5, "thief");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;

    // printf("%s Currebt Status\n", p1.getName().c_str());
    // printf("Health: %i\t Strenght: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    // printf("%s Current Status\n", p2.getName().c_str());
    // printf("Health: %d\t Strength: %d\t Defense: %d\n", p2.getHealth(), p2.getStrength(), p2.getDefense());

    // Call updateHealth(0) on p1
    // p1.updateHealth(0);

    // Print the new health
    // printf("New Health of %s: %d\n", p1.getName().c_str(), p1.getHealth());

    //isAlive() for p1 and p2
    // printf("%s is %s\n", p1.getName().c_str(), p1.isAlive() ? "alive" : "dead");
    // printf("%s is %s\n", p2.getName().c_str(), p2.isAlive() ? "alive" : "dead");
}

