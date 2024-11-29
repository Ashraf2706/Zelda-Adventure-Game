#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <iostream>
#include <string>
using namespace std;

//The parent class for all of the scary enemies
class Enemy {
 public:
  // Name: Enemy(string name, int hp, int damage, string desc)
  // Description: Used to populate variables in enemy
  // Preconditions: None
  // Postconditions: Used to populate child class data
  Enemy(string, int, int, string);
  // Name: Enemy Destructor
  // Description: Virtual destructor for an enemy
  // Preconditions: None
  // Postconditions: Does nothing but cannot be omitted
  virtual ~Enemy();
  // Name: Attack()
  // Description: Describes attack statements for Enemy
  // Preconditions: None
  // Postconditions: Returns damage
  int Attack();
  // Name: SpecialAttack()
  // Description: Purely virtual SpecialAttack
  // Preconditions: None
  // Postconditions: Must be implemented in child classes
  virtual int SpecialAttack() = 0;
  // Name: GetName()
  // Description: Returns enemy name
  // Preconditions: None
  // Postconditions: Returns enemy name
  string GetName();
  // Name: GetHealth
  // Description: Returns enemy health (used for battle)
  // Preconditions: None
  // Postconditions: Returns enemy health
  int GetHealth();
  // Name: SetHealth
  // Description: Used to update enemy health (used for battle)
  // Preconditions: None
  // Postconditions: Updates enemy health
  void SetHealth(int);
  // Name: GetDamage
  // Description: Returns enemy damage (used for battle)
  // Preconditions: None
  // Postconditions: Returns enemy damage
  int GetDamage();
  // Name: GetDesc
  // Description: Returns the description of the enemy (used in Look)
  // Preconditions: None
  // Postconditions: Returns the description of the enemy
  string GetDesc();
  // Name: Overloaded <<
  // Description: Prints the details of an enemy
  // Preconditions: None
  // Postconditions: returns an ostream with output of enemy
  friend ostream& operator<<(ostream&, Enemy&);
private:
  string m_name; //Name of the enemy
  int m_health; //Total health for this enemy
  int m_damage; //Max damage for this enemy
  string m_desc; //Description of the enemy
};
#endif
