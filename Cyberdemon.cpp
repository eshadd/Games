#include <string>
#include "Cyberdemon.h"
using namespace std;
using namespace cs_creature;

namespace cs_creature {
    Cyberdemon::Cyberdemon()
    : Demon() {}







    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
    : Demon(newStrength, newHitpoints) {
    }







    string Cyberdemon::getSpecies() const {
        return "Cyberdemon";
    }
}