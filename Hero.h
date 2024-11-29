#ifndef _HERO_H_
#define _HERO_H_
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Sword.h"
#include "Boomerang.h"
#include "Bomb.h"
using namespace std;

//The class that describes the hero! User can rename but the generic name is Link

//****CONSTANTS******
const int WEAPON_BASE = 3; //Used for all normal attacks

class Hero {
 public:
  // Name: Hero(string name, int health) - Overloaded Constructor
  // Description: Used for hero. Provides random weapon using RandomWeapon.
  // Preconditions: None
  // Postconditions: Used to populate hero (Link)
  Hero(string,int);
  // Name: ~Hero Destructor
  // Description: Deallocates the weapon
  // Preconditions: None
  // Postconditions: Used to deallocate anything dynamically allocated
  ~Hero();
  // Name: Attack()
  // Description: Calls the weapon's attack
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: GetName()
  // Description: Returns the current name
  // Preconditions: None
  // Postconditions: Returns the current name
  string GetName();
  // Name: SetName()
  // Description: Updates m_name with a new name
  // Preconditions: None
  // Postconditions: Updates m_name
  void SetName(string);
  // Name: GetHealth()
  // Description: Returns the health of the hero
  // Preconditions: None
  // Postconditions: Returns the health of the hero
  int GetHealth();
  // Name: SetHealth(int)
  // Description: Updates m_health of the hero
  // Preconditions: None
  // Postconditions: Updates m_health of the hero
  void SetHealth(int);
  // Name: GetRupee()
  // Description: Returns the rupee of the hero
  // Preconditions: None
  // Postconditions: Returns the rupee of the hero
  int GetRupee();
  // Name: SetRupee(int)
  // Description: Updates m_rupee of the hero
  // Preconditions: None
  // Postconditions: Updates m_rupee of the hero
  void SetRupee(int);
  // Name: RandomWeapon
  // Description: Dynamically allocates random weapon (sword, bomb, or boomerang)
  //              Indicates which weapon the hero starts with.
  // Preconditions: Called when hero is instantiated
  // Postconditions: Updates m_weapon to point at random weapon
  void RandomWeapon();
  // Name: ImproveWeapon()
  // Description: Improves m_weapon (1 damage for each 3 rupees) by calling
  //              the weapon's ImproveWeapon
  // Preconditions: None
  // Postconditions: Increases m_weapon and decreases m_rupees
  void ImproveWeapon(int);
  // Name: SpecialAttack()
  // Description: Calls the weapon's special attack
  // Preconditions: None
  // Postconditions: Used to attack an enemy using the weapon's special attack
  int SpecialAttack();
  // Name: Overloaded <<
  // Description: Prints the details of the hero (just name and health)
  // Preconditions: None
  // Postconditions: Returns an ostream with output of hero
  friend ostream& operator<<(ostream&, Hero&);
private:
  string m_name; //Name of the hero
  int m_health; //Total health for this hero
  int m_rupees; //Money held by the hero
  Weapon* m_weapon; //Weapon that the hero is wielding (used for damage)
};
#endif
