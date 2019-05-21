#ifndef BALROG_H
#define BALROG_H

#include <string>
#include "Demon.h"
using namespace std;

namespace cs_creature {
    class Balrog: public Demon {
        public:
            Balrog();
            Balrog(int newStrength, int newHitpoints);
            string getSpecies() const;
            int getDamage() const;
    };
}
# endif