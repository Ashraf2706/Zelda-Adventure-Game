#include "Moblin.h"

// Name:  Moblin(string name, int health, int damage, string desc)
// Description: Creates a new Moblin
// Preconditions: None
// Postconditions: Can create a Moblin
Moblin::Moblin(string name, int health, int damage, string desc):Enemy(name, health, damage, desc){
}

// Name: SpecialAttack
// Description: Defines the Moblin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Moblin::SpecialAttack(){
  cout << "A Moblin blasts you with their attack"  << endl;
  return MOBLIN_SPECIAL;
}