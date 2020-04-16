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

int CalculateDistance(int pId, int eId);
int GetClosestElevator(int num);
void MoveElevator(void);

#endif