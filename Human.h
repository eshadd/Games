#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "Creature.h"
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    class Human: public Creature {
        public:
            Human();
            Human(int newStrength, int newHitpoints);
            string getSpecies() const;
    };
}
# endif