#include <iostream>
#include <string>
#include "Elf.h"
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    Elf::Elf()
    : Creature() {}







    Elf::Elf(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints) {
    }







    string Elf::getSpecies() const {
        return "Elf";
    }







    int Elf::getDamage() const {
        int damage = Creature::getDamage();
        if ((rand() % damage_occur_denom) == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= damage_multiplier;
        }
        return damage;
    }
}