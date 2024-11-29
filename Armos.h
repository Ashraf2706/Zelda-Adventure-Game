#ifndef _ARMOS_H_
#define _ARMOS_H_

#include "Enemy.h"

// Armos are stone or mechanical statues that come to life and attack.
// The like to smash their opponents.

//***Constants***
const int ARMOS_SPECIAL = 2; //Base addition for Armos special attack

class Armos: public Enemy {
 public:
  // Name: Armos(string name, int health, int damage, string desc)
  // Description: Creates a new Armos
  // Preconditions: None
  // Postconditions: Creates a new Armos
  Armos(string, int, int, string);
  // Name: SpecialAttack
  // Description: Defines the Armos's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
