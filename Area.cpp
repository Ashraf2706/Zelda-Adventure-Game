#include "Area.h"

//Name: Area (Overloaded Constructor)
//Precondition: Must have valid input for each part of a area
// First int is the unique identifier for this particular area.
// The first string is the name of the area
// The second string is the description of the area
// The last four ints are the unique identifier for adjacent areas
//     (-1 = no path)
// North, East, South, and West
//Postcondition: Creates a new area
Area::Area(int ID, string name, string desc, int north, int east, int south, int west){
  m_ID = ID;
  m_name = name;
  m_desc = desc;
  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;
}
//Name: GetName
//Precondition: Must have valid area
//Postcondition: Returns area name as string
string Area::GetName(){
  return m_name;
}
//Name: GetID
//Precondition: Must have valid area
//Postcondition: Returns area id as int
int Area::GetID(){
  return m_ID;
}
//Name: GetDesc
//Precondition: Must have valid area
//Postcondition: Returns area desc as string
string Area::GetDesc(){
  return m_desc;
}
//Name: CheckDirection
//Precondition: Must have valid area
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the area in that direction
//Postcondition: Returns id of area in that direction if the exit exists
//If there is no exit in that direction, returns -1
int Area::CheckDirection(char myDirection){
  if(myDirection == 'n' or myDirection == 'N'){
    return m_direction[n];
  }else if(myDirection == 'e' or myDirection == 'E'){
    return m_direction[e];
  }else if(myDirection == 's' or myDirection == 'S'){
    return m_direction[s];
  }else if(myDirection == 'w' or myDirection == 'W'){
    return m_direction[w];
  }else{
    return -1;
  }
}
//Name: PrintArea
//Precondition: Area must be complete
//Postcondition: Outputs the area name, area desc, then possible exits
void Area::PrintArea(){
  cout << GetName() << endl;
  cout << GetDesc() << endl;
  cout << "Possible Exits: ";
  //check each direction if it is an exit
  if(m_direction[direction::n] != -1){
    cout << "N ";
  }
  if(m_direction[direction::e] != -1){
    cout << "E ";
  }
  if(m_direction[direction::s] != -1){
    cout << "S ";
  }
  if(m_direction[direction::w] != -1){
    cout << "W ";
  }
  cout << endl;
}