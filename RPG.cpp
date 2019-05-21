#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "Human.h"
#include "Cyberdemon.h"
#include "Elf.h"
#include "Balrog.h"
using namespace std;
using namespace cs_creature;

bool continueFight(Creature &fighter, Creature &enemy, int fightStage);
bool getWillingness();
Creature *createCreature(string role);
void displayCombatant(char r, Creature *combatant);
void battleArena(Creature&, Creature&);
void throwBlow(Creature&, Creature&);
void displayResult(Creature&, Creature&);

int MAX_STRENGTH = 25, MAX_HITPOINTS = 100;
float ENEMY_BOLDNESS = 0.5;

int main()
{
    Creature *fighter, *enemy;
    int fightStage = 0;

	srand(static_cast<unsigned>(time(0)));

    fighter = createCreature("be");
    enemy = createCreature("fight");
    cout <<  endl;

    if (continueFight(*enemy, *fighter, fightStage))
	    battleArena(*fighter, *enemy);
}






bool continueFight(Creature &attacker, Creature &attacked, int fightStage) {
    bool fight = true;
    int boldness;

    if (attacker.getStrength() / attacked.getHitpoints() > 1 || attacked.getStrength() / attacker.getHitpoints() < 5) {
        if (fightStage == 0) {
            cout << "Your enemy is strong compared to you. ";
            fight = getWillingness();
        }
        else
            cout << "The fight is at a critical stage. ";
            if (fightStage == 1)
                fight = getWillingness();
            if (fightStage == 2) {
                if (attacked.getStrength() / MAX_STRENGTH < ENEMY_BOLDNESS) {
                    cout << "Your enemy runs away!" << endl << endl;
                    fight = false;
                }
            }
    }
    return fight;
}







bool getWillingness() {
    string response;
    cout << "Do you wish to fight on (y/n)? ";
    getline(cin, response);
    if (response[0] != 'y') {
        cout << "You run and live to fight another day!" << endl << endl;
        return false;
    }
    else
        return true;
}





Creature *createCreature(string role) {
    bool invalidSpecies = true;
    string species;
    Creature *combatant = nullptr;

    while(invalidSpecies) {
        cout << "Which species would you like to " + role + ": Human, Elf, Cyberdemon or Balrog? ";
        getline(cin, species);

        switch (tolower(species[0])) {
            case 'h': combatant = new Human((rand() % MAX_STRENGTH) + 1, (rand() % MAX_HITPOINTS) + 1);
                invalidSpecies = false;
                break;
            case 'e': combatant = new Elf((rand() % MAX_STRENGTH) + 1, (rand() % MAX_HITPOINTS) + 1);
                invalidSpecies = false;
                break;
            case 'c': combatant = new Cyberdemon((rand() % MAX_STRENGTH) + 1, (rand() % MAX_HITPOINTS) + 1);
                invalidSpecies = false;
                break;
            case 'b': combatant = new Balrog((rand() % MAX_STRENGTH) + 1, (rand() % MAX_HITPOINTS) + 1);
                invalidSpecies = false;
                break;
            default: cout << "There are no " << species << "s in this land." << endl;
        }
    }
    displayCombatant(role[0], combatant);
    return combatant;
}






void displayCombatant(char r, Creature *combatant) {
    switch (r)
    {
        case 'b': cout << "You fight as a ";
            break;
        case 'f': cout << "Your enemy is a ";
            break;
    }
    cout << combatant->getSpecies() << " with a hit strength of " << combatant->getStrength()
        << " and " << combatant->getHitpoints() << " hit points." << endl;
}






void battleArena(Creature& fighter, Creature& enemy) {
    while (fighter.getHitpoints() > 0 && enemy.getHitpoints() > 0) {
        throwBlow(fighter, enemy);
            if(continueFight(enemy, fighter, 1))
                throwBlow(enemy, fighter);
            else
                fighter.setHitpoints(-999);
        if(!continueFight(fighter, enemy, 2))
            enemy.setHitpoints(-999);
    cout <<  endl;
    }
    displayResult(fighter, enemy);
}







void throwBlow(Creature &attacker, Creature& attackee) {
        attackee.setHitpoints(attackee.getHitpoints() - attacker.getDamage());
        cout << attackee.getSpecies() << " has " << attackee.getHitpoints() << " remaining hitpoints." << endl;
}







void displayResult(Creature &fighter, Creature& enemy) {
    if (fighter.getHitpoints() > 0) {
        cout << fighter.getSpecies();
    }
    else if (enemy.getHitpoints() > 0) {
        cout << enemy.getSpecies();
    }
    else
        cout << "Neither";
    cout << " was victorious!" << endl;
    cout << endl;
}
