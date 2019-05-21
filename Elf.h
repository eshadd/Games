#ifndef ELF_H
#define ELF_H

#include <string>
#include "Creature.h"
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    class Elf: public Creature {
        private:
            int damage_occur_denom = 2, damage_multiplier = 2;
        public:
            Elf();
            Elf(int newStrength, int newHitpoints);
            string getSpecies() const;
            int getDamage() const;
    };
}
# endif