/*Title: Area.h
Author: Prof. Dixon
Date: 10/29/2023
Description: This class defines areas in UMBC Zelda
*/

#ifndef AREA_H //Header Guard
#define AREA_H //Header Guard
#include <iostream>
#include <string>
using namespace std;

//Enum defining the directions in array n/N = 0, e/E = 1, s/S = 2, w/W = 3
enum direction{n=0,N=0,e=1,E=1,s=2,S=2,w=3,W=3};

class Area {
 public:
  //Name: Area (Overloaded Constructor)
  //Precondition: Must have valid input for each part of a area
  // First int is the unique identifier for this particular area.
  // The first string is the name of the area
  // The second string is the description of the area
  // The last four ints are the unique identifier for adjacent areas
  //     (-1 = no path)
  // North, East, South, and West
  //Postcondition: Creates a new area
  Area(int, string, string, int, int, int, int);
  //Name: GetName
  //Precondition: Must have valid area
  //Postcondition: Returns area name as string
  string GetName();
  //Name: GetID
  //Precondition: Must have valid area
  //Postcondition: Returns area id as int
  int GetID();
  //Name: GetDesc
  //Precondition: Must have valid area
  //Postcondition: Returns area desc as string
  string GetDesc();
  //Name: CheckDirection
  //Precondition: Must have valid area
  //You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
  //returns the ID of the area in that direction
  //Postcondition: Returns id of area in that direction if the exit exists
  //If there is no exit in that direction, returns -1
  int CheckDirection(char myDirection);
  //Name: PrintArea
  //Precondition: Area must be complete
  //Postcondition: Outputs the area name, area desc, then possible exits
  void PrintArea();
 private:
  int m_ID; //Unique int for area number
  string m_name; //Name of area
  string m_desc; //Description of area
  int m_direction[4]; //Array holding area to north, east, south, west (-1 if no exit)
};
#endif //Header Guard
