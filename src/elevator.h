#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__

#define MAX_ELEVATOR 3
#define MAX_FLOOR 6
#define UP 1
#define STOP 0
#define DOWN -1

struct Elevator
{
  int Location;
  int Direction;
  int CallCount;
  int InElevatorCount;
};

struct Elevator e[MAX_ELEVATOR];

// Determines the distance between the person and elevator
// It does that while considering the direction of the two objects
int CalculateDistance(int pId, int eId);

// Calculates the closest elevator to the person
int GetClosestElevator(int num);

// Moves the elevator based on its calls, direction and location
void MoveElevator(void);

#endif