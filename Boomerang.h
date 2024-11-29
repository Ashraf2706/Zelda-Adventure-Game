#ifndef _BOOMERANG_H_
#define _BOOMERANG_H_

#include "Weapon.h"

// The Boomerang is a type of weapon used by your hero
// It's special attack goes out and back cutting each way.
// Chooses a random number between 1 and m_damage once then returns result*2
// If m_damage is 6, it would do two times between 1 and 6 so maybe 4 * 2

class Boomerang: public Weapon {
 public:
  // Name: Boomerang(int damage)
  // Description: Creates a new Boomerang
  // Preconditions: None
  // Postconditions: Can create a Boomerang
  Boomerang(int);
  // Name: SpecialAttack
  // Description: Defines the Boomerang's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
