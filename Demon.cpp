#include <iostream>
#include <string>
#include "Demon.h"
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    Demon::Demon()
    : Creature() {}







    Demon::Demon(int newStrength, int newHitpoints)
    : Creature(newStrength, newHitpoints) {
    }







    string Demon::getSpecies() const {
        return "Demon";
    }







    int Demon::getDamage() const {
        int damage = Creature::getDamage();

        if (rand() % attack_occur_denom == 0) {
            damage = damage + attack_adder;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }

        return damage;
    }
}