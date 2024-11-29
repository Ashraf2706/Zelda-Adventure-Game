#ifndef _PEAHAT_H_
#define _PEAHAT_H_

#include "Enemy.h"

/* Peahats are flying plant or flower-like enemies.
   They propel themselves into the air with the use of their petals or
   leaves that are located either at their base or top,
   and achieve flight by rapidly spinning them, similar to helicopter blades.
*/

//***Constants***
const int PEAHAT_SPECIAL = 3; //Base for Peahat special attack

class Peahat: public Enemy {
 public:
  // Name: Peahat(string name, int health, int damage, string desc)
  // Description: Creates a new Peahat
  // Preconditions: None
  // Postconditions: Can create a Peahat
  Peahat(string, int, int, string);
  // Name: SpecialAttack
  // Description: Defines the Peahat's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
