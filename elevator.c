#include <stdio.h>
#include "person.h"
#include "elevator.h"

int CalculateDistance(int pId, int eId)
{
	if (e[eId].Direction == STOP)
	{
		if (p[pId].Location >= e[eId].Location)
		{
			return p[pId].Location - e[eId].Location;
		}
		else
		{
			return e[eId].Location - p[pId].Location;
		}
	}
	else if (e[eId].Direction == UP)
	{
		if (p[pId].Direction == UP)
		{
			if (p[pId].Location >= e[eId].Location)
			{
				return p[pId].Location - e[eId].Location;
			}
			else
			{
				return (MAX_FLOOR - p[pId].Location) + (MAX_FLOOR - e[eId].Location);
			}
		}
		else
		{
			if (p[pId].Location >= e[eId].Location)
			{
				return (MAX_FLOOR - e[eId].Location) + (MAX_FLOOR - p[pId].Location);
			}
			else
			{
				return (MAX_FLOOR - e[eId].Location) + (MAX_FLOOR - p[pId].Location);
			}
		}
	}
	else if (e[eId].Direction == DOWN)
	{
		if (p[pId].Direction == DOWN)
		{
			if (e[eId].Location >= p[pId].Location)
			{
				return e[eId].Location - p[pId].Location;
			}
			else
			{
				return (e[eId].Location - 1) + (p[pId].Location - 1);
			}
		}
		else
		{
			if (e[eId].Location >= p[pId].Location)
			{
				return (e[eId].Location - 1) + (p[pId].Location - 1);
			}
			else
			{
				return (e[eId].Location - 1) + (p[pId].Location - 1);
			}
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't find distance between %c and Elevator %d.\n", pId + 65, eId + 1);
		exit(1);
	}
}

int GetClosestElevator(int num)
{
	int i, j, distance[MAX_ELEVATOR];

	for (i = 0; i < MAX_ELEVATOR; i++)
	{
		distance[i] = CalculateDistance(num, i);
	}

	for (i = 0; ; i++)
	{
		for (j = 0; j < MAX_ELEVATOR; j++)
		{
			if (distance[j] == i)
			{
				return j;
			}
		}
	}
}

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