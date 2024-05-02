#include <iostream>
#include "Charmander.h"
using namespace std;
int main(){
    // Charmander first = Charmader();
    vector<string> pokemonType;
    pokemonType.push_back("Fire");

    vector<string> skills;
    skills.push_back("Growl"); 
    skills.push_back("Scratch");

    cout << "---------Constructor Created---------\n";
    Charmander charlie = Charmander("Charlie", 100, 4, 4, pokemonType, skills);

    cout << "---------Direct Speak---------\n";
    charlie.speak();

    Pokemon * p1 = &charlie;
    cout << "---------Speak called from Pokemon Pointer---------\n";
    (*p1).speak();

    Pokemon * c1 = &charlie;
    cout << "---------Speak called from Charmander Pointer---------\n";
    (*c1).speak();

    cout << "---------Print Stats---------\n";
    charlie.printStats();
}