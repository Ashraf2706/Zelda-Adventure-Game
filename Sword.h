#ifndef _SWORD_H_
#define _SWORD_H_

#include "Weapon.h"

// The Sword is a type of weapon used by Link
// It's special attack slashes and does between 1 and m_damage (twice)
// For example, if m_damage is 4 then it would could do 2 and 4 for a total of 6

class Sword: public Weapon {
 public:
  // Name: Sword(int damage)
  // Description: Creates a new Sword
  // Preconditions: None
  // Postconditions: Can create a Sword
  Sword(int);
  // Name: SpecialAttack
  // Description: Defines the Sword's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
