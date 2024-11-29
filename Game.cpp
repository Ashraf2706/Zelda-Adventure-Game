#include "Game.h"

// Name: Game(string filename) - Overloaded Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
// including m_myHero (null), m_curEnemy (null), filename (passed value),
// and starting area (START_AREA)
Game::Game(string filename){
  m_filename = filename;
  m_curArea = START_AREA;
  m_myHero = nullptr;
  m_curEnemy = nullptr;
}
// Name: ~Game
// Description: Destructor
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated
//                 in Game (weapons, enemies, and map)
Game::~Game(){
  //delete hero
  delete m_myHero;
  m_myHero = nullptr;
  //delete enemy
  delete m_curEnemy;
  m_curEnemy = nullptr;
  //delete map
  for(unsigned int i = 0; i < m_myMap.size(); i++){
    delete m_myMap[i];
    m_myMap[i] = nullptr;
  }
  m_myMap.clear();
}
// Name: LoadMap()
// Description: Dynamically creates areas and inserts them into
//              the m_myMap vector
// Note: the size of the map is not known - you should not use constants
//       Also, you can use stoi to convert strings to integers
// Precondition: m_filename is populated
// Postcondition: Map is populated with area objects.
void Game::LoadMap(){
  // Open file stream
  ifstream file(m_filename);
  
  string name, desc, stringID, stringNorth, stringEast, stringSouth, stringWest, temp;
  int id, north,east,south,west;

  while(getline(file, stringID, DELIMITER)){
    getline(file, name, DELIMITER);
    getline(file, desc, DELIMITER);
    getline(file, stringNorth, DELIMITER);
    getline(file, stringEast, DELIMITER);
    getline(file, stringSouth, DELIMITER);
    getline(file, stringWest, DELIMITER);
    getline(file, temp); // getline to move to next line

    //convert string directions to ints
    id = stoi(stringID);
    north = stoi(stringNorth);
    east = stoi(stringEast);
    south = stoi(stringSouth);
    west = stoi(stringWest);

    Area* map = new Area(id, name, desc, north, east, south, west);
    m_myMap.push_back(map);

    map = nullptr;
  }
  file.close();
}
// Name: HeroCreation()
// Description: Populates m_myHero and asks name
// Preconditions: None
// Postconditions: m_myHero is populated (and m_name in m_myHero)
void Game::HeroCreation(){
  string name;
  //asks for hero's name
  cout << "Hero Name: " ;
  cin >> name;
  m_myHero = new Hero(name, HERO_HEALTH);
}
// Name: Look()
// Description: Displays the current area's description and
//              the current enemy's desc (if there is one) otherwise, says
//              "It is peaceful here."
// Preconditions: None
// Postconditions: None
void Game::Look(){
  m_myMap[m_curArea] -> PrintArea(); //outputs current location with exits

  if(m_curEnemy != nullptr){
    cout << m_curEnemy -> GetDesc(); //enemy's description
    cout << endl;
  }else{
    cout << "It is peaceful here" << endl;
  }
}
// Name: StartGame()
// Description: Welcomes the player to the game. Calls LoadMap, HeroCreation,
//              Randomizes an enemy, Look, and Action
// Preconditions: Input file must exist
// Postconditions: Map is loaded, User has chosen a hero to play with,
//                 prints the starting area, chooses a random enemy
//                 and calls action
void Game::StartGame(){
  cout << "Welcome to Zelda!" << endl;
  LoadMap();
  HeroCreation();
  RandomEnemy(); //gives random enemy
  Look();
  Action(); //calls menu
}
// Name: Action()
// Description: Menu for game. Displays menu.
//              Player can look, move, attack, improve weapon, stats, or quit
//              Can only attack if there is actually a enemy in this area
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies
void Game::Action(){
  int choice;
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Enemy" << endl;
    cout << "4. Improve Weapon" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;

    cin >> choice;
  
    switch(choice){
      case 1:
        Look();
        break;
      case 2:
        Move();
        break;
      case 3:
        Attack();
        break;
      case 4:
        ImproveWeapon();
        break;
      case 5:
        Stats();
        break;
      case 6:
        cout << "Good bye!" << endl;
        break;
    }
    if(m_myHero->GetHealth() <= 0){//if the hero is dead, end the game.
      choice = 6;
    }
  }
  while(choice != 6);
}
// Name: RandomEnemy()
// Description: Used to dynamically allocated a random enemy
//              (25% chance of nothing, 25% chance of Armos, 25% of Moblin, and
//               25% of Peahat.)
// Preconditions: None
// Postconditions: Populates m_curEnemy (sets to nullptr if nothing)
void Game::RandomEnemy(){
  srand(time(NULL));
  int enemy = rand() % 4; //random number from 0 to 3

  if(enemy == 0){ //no enemies
    cout << endl;
  }else if(enemy == 1){
    m_curEnemy = new Armos(ARMOS_NAME, ARMOS_HEALTH, ARMOS_DAMAGE, ARMOS_DESC);
  }else if(enemy == 2){
    m_curEnemy = new Moblin(MOBLIN_NAME, MOBLIN_HEALTH, MOBLIN_DAMAGE, MOBLIN_DESC);
  }else{
    m_curEnemy = new Peahat(PEAHAT_NAME, PEAHAT_HEALTH, PEAHAT_DAMAGE,  PEAHAT_DESC);
  }
}
// Name: ImproveWeapon
// Description: Allows user to improve their weapon
// Preconditions: For each COST_IMPROVEMENT, damage in the weapon increases
//                by one.
// Postconditions: m_curHero's weapon is improved
void Game::ImproveWeapon(){
  int rupeesSpent, value;
  int rupeesEarned = m_myHero -> GetRupee(); //amount of rupees earned
  int upgradeValue = rupeesEarned / COST_IMPROVEMENT;
  // if the player has enough rupees to upgrade weapon 
  if(rupeesEarned >= COST_IMPROVEMENT){
    cout << "How much would you like to improve your weapon? (max " << upgradeValue << ")" << endl;
    cin >> value;
    //upgrading weapon according to value
    m_myHero -> ImproveWeapon(value);
    cout << "You have succesfully improved your weapon." << endl;
    rupeesSpent = value * COST_IMPROVEMENT;
    m_myHero -> SetRupee(rupeesEarned - rupeesSpent); // setting new amount of rupees
  }else{
    cout << "No enough rupees" << endl;
  }
}
// Name: Move
// Description: Asks a player which direction they would like to move.
//              Moves player from one area to another (updates m_curArea)
//              Once successfully moved, chooses a new random enemy and
//              Calls Look
// Preconditions: Must be valid move (area must exist)
// Postconditions: Displays area information and new monster
void Game::Move(){
  char direction;
  do{
    cout << "Which direction? (N E S W)" << endl;
    cin >> direction;
  }
  while(m_myMap.at(m_curArea) -> CheckDirection(direction) == -1);
  if(m_myMap.at(m_curArea) -> CheckDirection(direction) != -1){
    if(m_curEnemy != nullptr){
      delete m_curEnemy;
      m_curEnemy = nullptr;
    }
    m_curArea = m_myMap.at(m_curArea) -> CheckDirection(direction);
    RandomEnemy();
    Look();
  }else{
    cout << "there is no move here!" << endl;
  }
}
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
void Game::Attack(){
  int choice = 0; //int for attack type
  int damage = 0; //int for damage done

  if(m_curEnemy != nullptr){//attack if there is an enemy
    if((m_myHero -> GetHealth() >= 1) && (m_curEnemy -> GetHealth() >= 1)){ //both hero and enemy alive
      while(choice < 1 or choice > 2){
      cout << "1. Normal Attack" << endl;
      cout << "2. Special Attack" << endl;
      cin >> choice;
      }
      switch(choice){
        case 1:
          damage = m_myHero -> Attack(); //perform normal attack
          break;
        case 2:
          damage = m_myHero -> SpecialAttack();//perform special attack
          break;
        default:
          cout << "Invalid Choice! Please try again." << endl;
          break;
      }
    }
    cout << "You do " << damage << " points of damage" << endl;
    // calculate the damage done to enemy
    m_curEnemy -> SetHealth(m_curEnemy -> GetHealth() - damage);
    damage = 0; // set damage back to zero
    //now its enemy's turn
    //randomly select attack type with 25% chance for special attack
    srand(time(NULL));
    int attackType = rand() % 4;
    if(attackType >= 1){
      damage = m_curEnemy -> Attack();
      cout << m_curEnemy->GetName() << " attacks!" << endl;
    }else{
      damage = m_curEnemy -> SpecialAttack();
    }
    //calculate damage done to hero
    m_myHero -> SetHealth(m_myHero -> GetHealth() - damage);

    //Check if either hero or enemy is alive
    bool heroAlive = true;
    bool enemyAlive = true;

    if(m_myHero -> GetHealth() <= 0){//if hero is dead
      cout << "The " << m_curEnemy->GetName() << " smashes you!" << endl;
      cout << "You take " << damage << " points of damage." << endl;
      heroAlive = false;
    }
    else if(m_curEnemy -> GetHealth() <= 0){//if enemy is dead
      enemyAlive = false;
    }
    else if(m_myHero -> GetHealth() >= 0 && m_curEnemy -> GetHealth() >= 0){//if both are alive
    cout << *m_myHero; //hero details
    cout << *m_curEnemy;//enemy details
    }
    ProcessBattle(enemyAlive, heroAlive);  
  }else{
    cout << "No enemies in this area." << endl; //if there is no enemy to fight
  }
}
// Name: Stats()
// Description: Displays the information about the hero (name, health, rupees)
// Preconditions: None
// Postconditions: None
void Game::Stats(){
  cout << "Name: " << m_myHero -> GetName() << endl;
  cout << "Health: " << m_myHero -> GetHealth() << endl;
  // amount of rupees recieved
  cout << "Rupees: " << m_myHero -> GetRupee() << endl;
}
// Name: ProcessBattle
// Description: Called when either the enemy or hero have no health left
//       Displays who won (Enemy, Hero, mutual destruction)
//       If hero wins, gives RUPEES_WIN and resets health to starting value
// Preconditions: Enemy or hero are <= 0 health
// Postconditions: 
void Game::ProcessBattle(bool enemyAlive, bool alive){
  if(enemyAlive == true and alive == true){//if both are alive, continue fight
    Attack();
  }else if(enemyAlive == false and alive == true){//if enemy is dead
    cout << "You've killed the " << m_curEnemy->GetName() << "." << endl;
    cout << "You have earned " << RUPEES_WIN << " rupees." << endl;
    m_myHero->SetHealth(HERO_HEALTH);//set health back to start health
    m_myHero->SetRupee(m_myHero->GetRupee() + RUPEES_WIN); //give rupee reward
    delete m_curEnemy; //delete enemy
    m_curEnemy = nullptr;
  }else if(enemyAlive == true and alive == false){//if hero dead
    cout << "The enemy has defeated you. Try again!" << endl;
    delete m_curEnemy;
    m_curEnemy = nullptr;
  }else if(enemyAlive == false and alive == false){//if both are dead
    cout << "Mutual Destruction. Both sides lost their lives. Try again!" << endl;
    delete m_curEnemy;
    m_curEnemy = nullptr;
  }
}