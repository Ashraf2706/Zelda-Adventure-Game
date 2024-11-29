#include "Bomb.h"

// Name: Bomb(int damage)
// Description: Creates a new Bomb
// Preconditions: None
// Postconditions: Can create a Bomb
Bomb::Bomb(int damage):Weapon(damage){}

// Name: SpecialAttack
// Description: Defines the Bomb's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Bomb::SpecialAttack(){
  cout << "You throw the bomb and it explodes" << endl;
  int halfDamage = GetDamage() / 2; //half damage
  int doubleDamage = 2 * GetDamage();//double damage
  srand(time(NULL));
  int bombAttack = rand() % (doubleDamage - halfDamage + 1) + halfDamage;//number btn half damage and double damage
  return bombAttack;
}