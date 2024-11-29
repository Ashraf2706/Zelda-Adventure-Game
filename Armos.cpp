+#include "Armos.h"

// Name: Armos(string name, int health, int damage, string desc)
// Description: Creates a new Armos
// Preconditions: None
// Postconditions: Creates a new Armos
Armos::Armos(string name, int health, int damage, string desc):Enemy(name, health, damage, desc){
}

// Name: SpecialAttack
// Description: Defines the Armos's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Armos::SpecialAttack(){
  int armosDamage = GetDamage() + ARMOS_SPECIAL;
  cout << "The armos smashes you!" << endl;
  return armosDamage;
}