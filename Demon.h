#ifndef DEMON_H
#define DEMON_H

#include <string>
#include "Creature.h"
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    class Demon: public Creature {
        private:
            int attack_adder = 50;
            float attack_probability = 0.25;
            int attack_occur_denom = 1 / attack_probability;
        public:
            Demon();
            Demon(int newStrength, int newHitpoints);
            string getSpecies() const;
            int getDamage() const;
    };
}
# endif