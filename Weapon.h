#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <iostream>
#include <string>
using namespace std;

class Weapon {
 public:
  // Name: Weapon(int damage) - Overloaded constructor
  // Description: Creates a new weapon with specific damage
  // Preconditions: None
  // Postconditions: Can be used to populate weapon or child classes
  Weapon(int);
  // Name: ~Weapon - Virtual Destructor
  // Description: Required because child classes exist
  // Preconditions: None
  // Postconditions: Nothing to deallocate
  virtual ~Weapon();
  // Name: Attack()
  // Description: Describes attack statements for weapon
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: GetDamage()
  // Description: Returns the damage
  // Preconditions: None
  // Postconditions: Returns damage
  int GetDamage();
  // Name: ImproveWeapon(int)
  // Description: Increases m_damage of the weapon by the value passed
  // Preconditions: None
  // Postconditions: Increases m_damage of this weapon by the value passed
  void ImproveWeapon(int);
  // Name: SpecialAttack()
  // Description: Used in child classes for special attacks
  // Preconditions: None
  // Postconditions: Used to call child class SpecialAttack
  virtual int SpecialAttack() = 0;
private:
  int m_damage; //Damage that the base attack does
};
#endif
