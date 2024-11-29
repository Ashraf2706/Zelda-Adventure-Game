#include "Boomerang.h"

// Name: Boomerang(int damage)
// Description: Creates a new Boomerang
// Preconditions: None
// Postconditions: Can create a Boomerang
Boomerang::Boomerang(int damage):Weapon(damage){}

// Name: SpecialAttack
// Description: Defines the Boomerang's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Boomerang::SpecialAttack(){
  srand(time(NULL));
  int attack = rand() % GetDamage() + 1;//number btn 1 and damage
  int boomerangAttack = attack * 2;
  cout << "You throw a boomerang and it does " << attack
  <<" damage on the way out and " << attack << " damage on the way back!" << endl;
  //damage details
  return boomerangAttack;
}