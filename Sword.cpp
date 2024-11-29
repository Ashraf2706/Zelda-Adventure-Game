#include "Sword.h"

// Name: Sword(int damage)
// Description: Creates a new Sword
// Preconditions: None
// Postconditions: Can create a Sword
Sword::Sword(int damage):Weapon(damage){}
// Name: SpecialAttack
// Description: Defines the Sword's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Sword::SpecialAttack(){
  cout << "You slash twice with a sword" << endl;
  //sword damage details
  srand(time(NULL));
  int swordAttack = (rand() % (GetDamage() + 1) + 1) * 2;
  return swordAttack;
}