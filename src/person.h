#ifndef __PERSON_H__
#define __PERSON_H__

#include <stdlib.h>
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

void CallElevator(void);
void CheckElevator(void);
void CheckPerson(void);

#endif