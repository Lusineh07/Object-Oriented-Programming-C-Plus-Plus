#include "RPG.h"
#include <iostream> 
#include <cctype>
#include <cmath>
using namespace std;

// Overloaded constructor
RPG::RPG(string name, int health, int strength, int defense, string type) {
    this->name = name;
    this->health = abs(health);
    this->strength = abs(strength);
    this->defense = abs(defense);
    this->type = type;
    setSkills();
}

// Default constructor
RPG::RPG() {
    name = "NPC";
    health = 100;
    strength = 15;
    defense = 5;
    type = "warrior";
    setSkills();
}
string RPG::getName() const{
    return name;
}

int RPG::getHealth() const {
    return health;
}

int RPG::getStrength() const {
    return strength;
}

int RPG::getDefense() const {
    return defense;
}

// Member function to set skills
void RPG::setSkills() {
    if(type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";
    }else if(type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if(type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else{
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

void RPG::updateHealth(int new_health) {
    health = new_health;
}

void RPG::attack(RPG * opponent){
    int opp_health = (*opponent).getHealth();
    int opp_def = (*opponent).getDefense();

    int new_health;
    if (strength - opp_def > 0 ){
        new_health = opp_health - (strength - opp_def);
    } else{
        new_health = opp_health - 0;
    }

    (*opponent).updateHealth(new_health);
}

void RPG::useSkill(RPG * opponent){

    for(int i = 0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    int chosen_skill_index;
    int wrong_input_count = 0;

    printf("Choose a skill to use. Enter 0 or 1: ");

    while(true){
        cin >> chosen_skill_index;
        if (cin.fail() || (chosen_skill_index != 0 && chosen_skill_index != 1)) {
            wrong_input_count++;

            if (wrong_input_count == 3){
                cout << "You have entered wrong input 3 TIMES! -_- Exiting...\n";
                exit(0);
            }
            cout << "Invalid input. Please choose 0 or 1: ";
            cin.clear();
            cin.ignore();

        } else {
            wrong_input_count = 0;
            break;
        }
    }

    // printf("Error1\n");
    // switch (chosen_skill_index){
    // case 0:
    // case 1:
    //     printf("Correct!");
    //     break;
    // default:
    //     printf("Wrong input!");
    //     break;
    // }
    // printf("Error2\n");

    string chosen_skill = skills [chosen_skill_index];
    //printf("Error3\n");

    printAction (chosen_skill, (*opponent));
    //printf("Error4\n");

    attack(opponent);
    //printf("Error5\n");

}

bool RPG::isAlive() const {
    return health > 0;
}

void RPG::printAction(string skill, RPG opponent){
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}
