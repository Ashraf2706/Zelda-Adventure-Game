#ifndef _GAME_H_
#define _GAME_H_

//Includes of required classes
#include "Area.h"
#include "Hero.h"
#include "Enemy.h"
#include "Armos.h"
#include "Moblin.h"
#include "Peahat.h"
#include "Weapon.h"
#include "Sword.h"
#include "Bomb.h"
#include "Boomerang.h"

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//************************Constants*********************
// HERO CONSTANTS
const int HERO_HEALTH = 8; //starting health for hero

//GAME CONSTANTS
const int START_AREA = 0; //starting area number
const char DELIMITER = '|'; //delimiter for input file (map file)
const int COST_IMPROVEMENT = 3; //number of rupees per 1 increase in damage
const int RUPEES_WIN = 2; //number of rupees earned per enemy win

// ENEMY CONSTANTS
const string ARMOS_NAME = "Armos"; //armos name
const string MOBLIN_NAME = "Moblin"; //moblin name
const string PEAHAT_NAME = "Peahat"; //peahat name
const int ARMOS_HEALTH = 10;  //starting health for armos
const int MOBLIN_HEALTH = 12; //starting health for moblin
const int PEAHAT_HEALTH = 14; //starting health for peahat
const int ARMOS_DAMAGE = 3; //starting damage for armos
const int MOBLIN_DAMAGE = 2; //starting damage for moblin
const int PEAHAT_DAMAGE = 1; //starting damage for peahat
const string ARMOS_DESC = "A statue stands here."; //armos desc
const string MOBLIN_DESC = "A bulldog looking Moblin stands here."; //moblin desc
const string PEAHAT_DESC = "A PeaHat flutters through the air."; //peahat desc
//******************************************************

class Game {
public:
  // Name: Game(string filename) - Overloaded Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: Initializes all game variables to defaults (constants)
  // including m_myHero (null), m_curEnemy (null), filename (passed value),
  // and starting area (START_AREA)
  Game(string);
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated
  //                 in Game (weapons, enemies, and map)
  ~Game();
  // Name: LoadMap()
  // Description: Dynamically creates areas and inserts them into
  //              the m_myMap vector
  // Note: the size of the map is not known - you should not use constants
  //       Also, you can use stoi to convert strings to integers
  // Precondition: m_filename is populated
  // Postcondition: Map is populated with area objects.
  void LoadMap();
  // Name: HeroCreation()
  // Description: Populates m_myHero and asks name
  // Preconditions: None
  // Postconditions: m_myHero is populated (and m_name in m_myHero)
  void HeroCreation();
  // Name: Look()
  // Description: Displays the current area's description and
  //              the current enemy's desc (if there is one) otherwise, says
  //              "It is peaceful here."
  // Preconditions: None
  // Postconditions: None
  void Look();
  // Name: StartGame()
  // Description: Welcomes the player to the game. Calls LoadMap, HeroCreation,
  //              Randomizes an enemy, Look, and Action
  // Preconditions: Input file must exist
  // Postconditions: Map is loaded, User has chosen a hero to play with,
  //                 prints the starting area, chooses a random enemy
  //                 and calls action
  void StartGame();
  // Name: Action()
  // Description: Menu for game. Displays menu.
  //              Player can look, move, attack, improve weapon, stats, or quit
  //              Can only attack if there is actually a enemy in this area
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies
  void Action();
  // Name: RandomEnemy()
  // Description: Used to dynamically allocated a random enemy
  //              (25% chance of nothing, 25% chance of Armos, 25% of Moblin, and
  //               25% of Peahat.)
  // Preconditions: None
  // Postconditions: Populates m_curEnemy (sets to nullptr if nothing)
  void RandomEnemy();
  // Name: ImproveWeapon
  // Description: Allows user to improve their weapon
  // Preconditions: For each COST_IMPROVEMENT, damage in the weapon increases
  //                by one.
  // Postconditions: m_curHero's weapon is improved
  void ImproveWeapon();
  // Name: Move
  // Description: Asks a player which direction they would like to move.
  //              Moves player from one area to another (updates m_curArea)
  //              Once successfully moved, chooses a new random enemy and
  //              Calls Look
  // Preconditions: Must be valid move (area must exist)
  // Postconditions: Displays area information and new monster
  void Move();
  // Name: Attack
  // Description: Allows player to attack an enemy.
  // Preconditions: Must have enemy Enemy in current area
  // Postconditions: Checks to make sure that there is an enemy to fight.
  //                 Asks the user if they want to use a normal or special attack
  //                 Updates health(hp) as battle continues.
  //                 Both Hero and Enemy attack every round until
  //                 one or more has <= 0 health
  //                 May need to deallocate enemy Enemy to prevent memory leaks.
  //                 When either Enemy or Hero <= 0 health, calls ProcessBattle
  void Attack();
  // Name: Stats()
  // Description: Displays the information about the hero (name, health, rupees)
  // Preconditions: None
  // Postconditions: None
  void Stats();
  // Name: ProcessBattle
  // Description: Called when either the enemy or hero have no health left
  //       Displays who won (Enemy, Hero, mutual destruction)
  //       If hero wins, gives RUPEES_WIN and resets health to starting value
  // Preconditions: Enemy or hero are <= 0 health
  // Postconditions: 
  void ProcessBattle(bool enemyAlive, bool alive);
private:
  vector<Area*> m_myMap; // Vector for holding all areas in game
  Hero* m_myHero; // Hero pointer for Hero (Player)
  int m_curArea; // Current area that player (Hero) is in
  Enemy* m_curEnemy; // Current enemy loaded for current area
  string m_filename; //Name of the input file for the map (holds area objects)
};

#endif
