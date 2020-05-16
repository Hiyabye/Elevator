#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "elevator.h"

// Determines the distance between the person and elevator
// It does that while considering the direction of the two objects
// TODO - Change MAX_FLOOR to the highest destination of the elevator
// TODO - Maybe simplify the function by merging same parts?
int CalculateDistance(int pId, int eId)
{
	if (e[eId].Direction == STOP)
	{
		// The elevator isn't moving, and the person is located higher than the elevator
		if (p[pId].Location >= e[eId].Location)
		{
			// Solution: Subtract the elevator's location from the person's location
			return p[pId].Location - e[eId].Location;
		}
		// The elevator isn't moving, and the person is located lower than the elevator
		else
		{
			// Solution: Subtract the person's location from the elevator's location
			return e[eId].Location - p[pId].Location;
		}
	}
	else if (e[eId].Direction == UP)
	{
		if (p[pId].Direction == UP)
		{
			// The elevator is going up, and the person wants to go up too
			// The person is located higher than the elevator
			if (p[pId].Location >= e[eId].Location)
			{
				// Solution: Subtract the elevator's location from the person's location
				return p[pId].Location - e[eId].Location;
			}
			// The elevator is going up, and the person wants to go up too
			// The person is located lower than the elevator
			else
			{
				/*
				// Solution: The elevator moves to the person in 3 steps
				// 1. The elevator goes to the top (Top doesn't mean the highest floor, 
				// it means the highest destination of the people in the elevator)
				// 2. After it reachs the top, it will move downwards
				// 3. The elevator reachs to the person's location going down
				*/
				return (MAX_FLOOR - p[pId].Location) + (MAX_FLOOR - e[eId].Location);
			}
		}
		else
		{
			// The elevator is going up, but the person wants to go down
			// The person is located higher than the elevator
			if (p[pId].Location >= e[eId].Location)
			{
				/*
				// Solution: The elevator moves to the person in 3 steps
				// 1. The elevator moves to the top (The top doesn't mean the highest floor,
				// it means the highest destination of the people in the elevator)
				// 2. After it reachs the top, it moves in a downward direction
				// 3. The elevator reachs to the person's location while going down
				*/
				return (MAX_FLOOR - e[eId].Location) + (MAX_FLOOR - p[pId].Location);
			}
			// The elevator is going up, but the person wants to go down
			// The person is located lower than the elevator
			else
			{
				/*
				// Solution: The elevator moves to the person in 3 steps
				// 1. The elevator moves to the top (The top doesn't mean the highest floor,
				// it means the highest destination of the people in the elevator)
				// 2. After it reachs the top, it moves in a downward direction
				// 3. The elevator reachs to the person's location going down
				*/
				return (MAX_FLOOR - e[eId].Location) + (MAX_FLOOR - p[pId].Location);
			}
		}
	}
	else if (e[eId].Direction == DOWN)
	{
		if (p[pId].Direction == DOWN)
		{
			// The elevator is going down, and the person wants to go down too
			// The person is located lower than the elevator
			if (e[eId].Location >= p[pId].Location)
			{
				// Solution: Subtract the person's location from the elevator's location
				return e[eId].Location - p[pId].Location;
			}
			// Both the elevator and the person is going down
			// The person is located higher than the elevator
			else
			{
				/*
				// Solution: The elevator moves to the person in 3 steps
				// 1. The elevator moves to the bottom (The bottom doesn't mean the first floor,
				// it means the lowest destination of the people in the elevator)
				// 2. After it reachs the bottom, it moves in a upward direction
				// 3. The elevator reachs to the person's location going up
				*/
				return (e[eId].Location - 1) + (p[pId].Location - 1);
			}
		}
		else
		{
			// The elevator is going down, but the person wants to go up
			// The person is located lower than the elevator
			if (e[eId].Location >= p[pId].Location)
			{
				/*
				// Solution: The elevator moves to the person in 3 steps
				// 1. The elevator moves to the bottom (The bottom doesn't mean the first floor,
				// it means the lowest destination of the people in the elevator)
				// 2. After it reachs the bottom, it moves in a upward direction
				// 3. The elevator reachs to the person's location going up
				*/
				return (e[eId].Location - 1) + (p[pId].Location - 1);
			}
			// The elevator is going down, but the person wants to go up
			// The person is located higher than the elevator
			else
			{
				/*
				// Solution: The elevator moves to the person in 3 steps
				// 1. The elevator moves to the bottom (The bottom doesn't mean the first floor,
				// it means the lowest destination of the people in the elevator)
				// 2. After it reachs the bottom, it moves in a upward direction
				// 3. The elevator reachs to the person's location going up
				*/
				return (e[eId].Location - 1) + (p[pId].Location - 1);
			}
		}
	}
	else
	{
		// Error: Can't find elevator's direction
		fprintf(stderr, "Error! Can't find distance between %c and Elevator %d.\n", pId + 65, eId + 1);
		exit(-1);
	}
}

// Calculates the closest elevator to the person
int GetClosestElevator(int num)
{
	int i, j;
	int distance[MAX_ELEVATOR];
	int min = MAX_FLOOR * 2;	// Setting the default value of this just for safety
	int key;

	// Calculates the distance of every elevator to the person
	for (i = 0; i < MAX_ELEVATOR; i++)
	{
		distance[i] = CalculateDistance(num, i);
		
		// If the calculated distance is smaller than min, swap it
		if (distance[i] < min)
		{
			min = distance[i];
			key = i;
		}
	}

	return key;
}

// Moves the elevator based on its calls, direction and location
void MoveElevator(void)
{
	int i;

	for (i = 0; i < MAX_ELEVATOR; i++)
	{
		if (e[i].Direction == STOP)
		{
			printf("Elevator %d : At floor %d\n", i + 1, e[i].Location);
		}
		else if (e[i].Direction == UP)
		{
			e[i].Location++;
			printf("Elevator %d : %d->%d\n", i + 1, e[i].Location - 1, e[i].Location);
		}
		else if (e[i].Direction == DOWN)
		{
			e[i].Location--;
			if (e[i].Location < 1)
			{
				e[i].Location = 1;
				e[i].Direction = STOP;
				printf("Elevator %d : At floor %d\n", i + 1, e[i].Location);
			}
			else if (e[i].Location > MAX_FLOOR)
			{
				e[i].Location = MAX_FLOOR;
				e[i].Direction = STOP;
				printf("Elevator %d : At floor %d\n", i + 1, e[i].Location);
			}
			else
			{
				printf("Elevator %d : %d->%d\n", i + 1, e[i].Location + 1, e[i].Location);
			}
		}
	}
}