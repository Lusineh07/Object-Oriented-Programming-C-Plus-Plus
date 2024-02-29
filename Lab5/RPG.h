#ifndef RPG_H
#define RPG_H

#include <string>

const int SKILL_SIZE = 2;

class RPG {
    public: 
    //constructors
    RPG();
    RPG(std::string name, int health, int streanght, int defense, std::string type);

    void setSkills();
    void printAction(std::string action, RPG target);
    void updateHealth(int value);
    //void attack(RPG target);
    //void useSkill(RPG target);
    bool isAlive() const;
    std::string getName() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;

    private:

    std::string name;
    int health;
    int strength;
    int defense;

    std::string type; // warrior, mage, thief, archer
    std::string skills[SKILL_SIZE];

};
#endif
