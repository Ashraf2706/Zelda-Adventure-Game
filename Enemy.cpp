#include "Enemy.h"

// Name: Enemy(string name, int hp, int damage, string desc)
// Description: Used to populate variables in enemy
// Preconditions: None
// Postconditions: Used to populate child class data
Enemy::Enemy(string name, int hp, int damage, string desc){
  m_name = name;
  m_health = hp;
  m_damage = damage;
  m_desc = desc;
}
// Name: Enemy Destructor
// Description: Virtual destructor for an enemy
// Preconditions: None
// Postconditions: Does nothing but cannot be omitted
Enemy::~Enemy(){}
// Name: Attack()
// Description: Describes attack statements for Enemy
// Preconditions: None
// Postconditions: Returns damage
int Enemy::Attack(){
  return m_damage;
}
// Name: SpecialAttack()
// Description: Purely virtual SpecialAttack
// Preconditions: None
// Postconditions: Must be implemented in child classes
//virtual int Enemy::SpecialAttack() = 0{}
// Name: GetName()
// Description: Returns enemy name
// Preconditions: None
// Postconditions: Returns enemy name
string Enemy::GetName(){
  return m_name;
}
// Name: GetHealth
// Description: Returns enemy health (used for battle)
// Preconditions: None
// Postconditions: Returns enemy health
int Enemy::GetHealth(){
  return m_health;
}
// Name: SetHealth
// Description: Used to update enemy health (used for battle)
// Preconditions: None
// Postconditions: Updates enemy health
void Enemy::SetHealth(int hp){
  m_health = hp;
}
// Name: GetDamage
// Description: Returns enemy damage (used for battle)
// Preconditions: None
// Postconditions: Returns enemy damage
int Enemy::GetDamage(){
  return m_damage;
}
// Name: GetDesc
// Description: Returns the description of the enemy (used in Look)
// Preconditions: None
// Postconditions: Returns the description of the enemy
string Enemy::GetDesc(){
  return m_desc;
}
// Name: Overloaded <<
// Description: Prints the details of an enemy
// Preconditions: None
// Postconditions: returns an ostream with output of enemy
ostream& operator<<(ostream& output, Enemy& enemy){
  output << enemy.GetName() <<
  ": Health: " << enemy.GetHealth() << 
  ": Damage: " << enemy.GetDamage() << endl;
  return output;

}
