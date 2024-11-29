#include "Hero.h"

// Name: Hero(string name, int health) - Overloaded Constructor
// Description: Used for hero. Provides random weapon using RandomWeapon.
// Preconditions: None
// Postconditions: Used to populate hero (Link)
Hero::Hero(string name, int health){
  m_name = name;
  m_health = health;
  m_rupees = 0;
  m_weapon = nullptr;
  RandomWeapon(); //assigns random weapon to hero
}
// Name: ~Hero Destructor
// Description: Deallocates the weapon
// Preconditions: None
// Postconditions: Used to deallocate anything dynamically allocated
Hero::~Hero(){
  delete m_weapon;
}
// Name: Attack()
// Description: Calls the weapon's attack
// Preconditions: None
// Postconditions: Returns damage
int Hero::Attack(){
  if(m_weapon){
    return m_weapon->Attack();
  }
  return 0;
}
// Name: GetName()
// Description: Returns the current name
// Preconditions: None
// Postconditions: Returns the current name
string Hero::GetName(){
  return m_name;
}
// Name: SetName()
// Description: Updates m_name with a new name
// Preconditions: None
// Postconditions: Updates m_name
void Hero::SetName(string name){
  m_name = name;
}
// Name: GetHealth()
// Description: Returns the health of the hero
// Preconditions: None
// Postconditions: Returns the health of the hero
int Hero::GetHealth(){
  return m_health;
}
// Name: SetHealth(int)
// Description: Updates m_health of the hero
// Preconditions: None
// Postconditions: Updates m_health of the hero
void Hero::SetHealth(int health){
  m_health = health;
}
// Name: GetRupee()
// Description: Returns the rupee of the hero
// Preconditions: None
// Postconditions: Returns the rupee of the hero
int Hero::GetRupee(){
  return m_rupees;
}
// Name: SetRupee(int)
// Description: Updates m_rupee of the hero
// Preconditions: None
// Postconditions: Updates m_rupee of the hero
void Hero::SetRupee(int rupees){
  m_rupees = rupees;
}
// Name: RandomWeapon
// Description: Dynamically allocates random weapon (sword, bomb, or boomerang)
//              Indicates which weapon the hero starts with.
// Preconditions: Called when hero is instantiated
// Postconditions: Updates m_weapon to point at random weapon
void Hero::RandomWeapon(){
  srand(time(NULL));
  int randomWeaponType = rand() % 3;

  switch(randomWeaponType){
    case 0:
      m_weapon = new Sword(WEAPON_BASE); //adds sword to weapon
      cout << "You start with a sword!" << endl;
      cout << endl;
      break;
    case 1:
      m_weapon = new Bomb(WEAPON_BASE);//adds bomb to weapon
      cout << "You start with bombs!" << endl;
      cout << endl;
      break;
    case 2:
      m_weapon = new Boomerang(WEAPON_BASE);//adds boomerang to weapon
      cout << "You start with a boomerang!" << endl;
      cout << endl;
      break;
  }
}
// Name: ImproveWeapon()
// Description: Improves m_weapon (1 damage for each 3 rupees) by calling
//              the weapon's ImproveWeapon
// Preconditions: None
// Postconditions: Increases m_weapon and decreases m_rupees
void Hero::ImproveWeapon(int amount){
  if(m_weapon){
    m_weapon -> ImproveWeapon(amount);
    m_rupees -= amount;
  }
}
// Name: SpecialAttack()
// Description: Calls the weapon's special attack
// Preconditions: None
// Postconditions: Used to attack an enemy using the weapon's special attack
int Hero::SpecialAttack(){
  if(m_weapon){
    return m_weapon->SpecialAttack();
  }
  return 0;
}
// Name: Overloaded <<
// Description: Prints the details of the hero (just name and health)
// Preconditions: None
// Postconditions: Returns an ostream with output of hero
ostream& operator<<(ostream& output, Hero& hero){
 output << hero.m_name << " Health: " << hero.m_health << endl;
 return output;
}