#ifndef _MOBLIN_H_
#define _MOBLIN_H_

#include "Enemy.h"

//Moblins are pig- or bulldog-like monsters that often reside in forests
// but can reside in caves or otherwise. 

//***Constants***
const int MOBLIN_SPECIAL = 4; //Base damage for Moblin special attack

class Moblin: public Enemy {
 public:
  // Name:  Moblin(string name, int health, int damage, string desc)
  // Description: Creates a new Moblin
  // Preconditions: None
  // Postconditions: Can create a Moblin
  Moblin(string, int, int, string);
  // Name: SpecialAttack
  // Description: Defines the Moblin's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
