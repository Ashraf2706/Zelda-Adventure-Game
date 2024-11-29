#ifndef _BOMB_H_
#define _BOMB_H_

#include "Weapon.h"

// The Bomb is a type of weapon used by your hero
// It's special attack explodes and does
// between 1/2 m_damage and 2x damage
// For example, if m_damage is 7, it would do between 3 and 14 (round down)

class Bomb: public Weapon {
 public:
  // Name: Bomb(int damage)
  // Description: Creates a new Bomb
  // Preconditions: None
  // Postconditions: Can create a Bomb
  Bomb(int);
  // Name: SpecialAttack
  // Description: Defines the Bomb's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
