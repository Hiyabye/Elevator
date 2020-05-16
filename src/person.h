#ifndef __PERSON_H__
#define __PERSON_H__

#include <stdbool.h>

#define MAX_PERSON 6
#define UP 1
#define STOP 0
#define DOWN -1

struct Person
{
  int Location;
  int Destination;
  int Direction;
  bool Call;
  int ClosestElevator;
  bool InElevator;
};

struct Person p[MAX_PERSON];

// Calls the elevator by the person's input
void CallElevator(void);

// Gets the closest elevator for the person
// Also it manages the movement of the person
void CheckElevator(void);

// This function outputs the location of the person
void CheckPerson(void);

#endif