
# UMBC Zelda Adventure Game

## Overview
This project implements a text-based adventure game inspired by the Legend of Zelda series. The game includes dynamic hero creation, interactive battles, exploration of different areas, and management of various enemies and weapons. Players can explore a map, engage in battles with unique enemies, and improve their weapons.

## Features
1. **Hero Creation**:
   - Create and customize a hero with a random starting weapon.
   - Manage hero attributes such as health and rupees.

2. **Dynamic Map Exploration**:
   - Explore a dynamically loaded map with interconnected areas.
   - Move between areas using directional commands.

3. **Enemy Encounters**:
   - Face various enemies, each with unique attributes and special attacks.
   - Engage in battles using normal or special attacks.

4. **Weapons and Combat**:
   - Equip the hero with different types of weapons, including swords, bombs, and boomerangs.
   - Improve weapon damage using rupees earned from battles.

5. **Interactive Menu**:
   - Choose actions such as moving, attacking, improving weapons, and viewing stats.

## Files and Classes
### Core Game Mechanics
- **`Game.cpp` & `Game.h`**:
  - Manages the overall game logic, including map loading, hero creation, and gameplay actions.
  - Includes methods for exploring areas, engaging in battles, and improving weapons.

### Hero and Enemies
- **`Hero.cpp` & `Hero.h`**:
  - Implements the `Hero` class, which represents the player's character.
  - Manages hero attributes such as name, health, rupees, and weapon.
- **`Enemy.cpp` & `Enemy.h`**:
  - Parent class for all enemies, providing common attributes and methods.
  - Includes specific enemy types:
    - **`Armos.cpp` & `Armos.h`**: Stone-like enemies with smashing attacks.
    - **`Moblin.cpp` & `Moblin.h`**: Bulldog-like enemies with blast attacks.
    - **`Peahat.cpp` & `Peahat.h`**: Flying plant-like enemies with whipping attacks.

### Weapons
- **`Weapon.cpp` & `Weapon.h`**:
  - Parent class for all weapons, providing common methods such as attack and improvement.
  - Includes specific weapon types:
    - **`Sword.cpp` & `Sword.h`**: Slashes twice, causing double damage.
    - **`Bomb.cpp` & `Bomb.h`**: Explodes, causing random damage between half and double.
    - **`Boomerang.cpp` & `Boomerang.h`**: Deals damage on the way out and back.

### Map and Areas
- **`Area.cpp` & `Area.h`**:
  - Represents areas in the game, each with a unique ID, name, description, and directional connections.

## Installation and Execution
1. **Ensure all files are in the same directory**.
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o zelda_game Game.cpp Hero.cpp Enemy.cpp Armos.cpp Moblin.cpp Peahat.cpp    Weapon.cpp Sword.cpp Bomb.cpp Boomerang.cpp Area.cpp
   ```
3. Run the application:
   ```bash
   ./zelda_game <map_file.txt>
   ```

### Input File Format
The map file should contain areas in the following format, delimited by `|`:
```
<AreaID>|<AreaName>|<AreaDescription>|<NorthID>|<EastID>|<SouthID>|<WestID>
```
Example:
```
0|Starting Area|This is the starting area.|1|-1|-1|-1
1|North Area|You see a forest.|-1|2|-1|0
```

## Gameplay Instructions
### Menu Options
1. **Look**: View the current area and enemy (if present).
2. **Move**: Move to an adjacent area using N, E, S, W directions.
3. **Attack Enemy**: Engage in combat with the current area's enemy.
4. **Improve Weapon**: Spend rupees to increase weapon damage.
5. **Check Stats**: View hero's health, rupees, and weapon details.
6. **Quit**: Exit the game.

### Example Output
- **Hero Creation**:
  ```
  Hero Name: Link
  You start with a sword!
  ```
- **Area Description**:
  ```
  Starting Area
  This is the starting area.
  Possible Exits: N
  It is peaceful here.
  ```
- **Combat**:
  ```
  A Moblin blasts you with their attack!
  You do 5 points of damage.
  ```

## Dependencies
- Standard C++ libraries:
  - `<iostream>`
  - `<string>`
  - `<vector>`
  - `<fstream>`
  - `<ctime>`

## Authors
- **Ashraf Kawooya**
- UMBC CMSC 202 - Fall 2024

## License
This project is intended for educational purposes and does not include warranties or guarantees.
