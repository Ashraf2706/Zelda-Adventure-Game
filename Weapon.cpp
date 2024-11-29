#include "Weapon.h"

// Name: Weapon(int damage) - Overloaded constructor
// Description: Creates a new weapon with specific damage
// Preconditions: None
// Postconditions: Can be used to populate weapon or child classes
Weapon::Weapon(int damage){
  m_damage = damage;
}
// Name: ~Weapon - Virtual Destructor
// Description: Required because child classes exist
// Preconditions: None
// Postconditions: Nothing to deallocate
Weapon::~Weapon(){}
// Name: Attack()
// Description: Describes attack statements for weapon
// Preconditions: None
// Postconditions: Returns damage
int Weapon::Attack(){
  return m_damage;
}
// Name: GetDamage()
// Description: Returns the damage
// Preconditions: None
// Postconditions: Returns damage
int Weapon::GetDamage(){
  return m_damage;
}
// Name: ImproveWeapon(int)
// Description: Increases m_damage of the weapon by the value passed
// Preconditions: None
// Postconditions: Increases m_damage of this weapon by the value passed
void Weapon::ImproveWeapon(int value){
  m_damage += value;
}
