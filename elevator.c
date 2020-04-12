#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PERSON 6
#define MAX_ELEVATOR 3
#define MAX_FLOOR 6
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

struct Elevator
{
  int Location;
  int Direction;
  int CallCount;
  int InElevatorCount;
};

struct Person p[MAX_PERSON];
struct Elevator e[MAX_ELEVATOR];

void CallElevator(void);
void CheckElevator(void);
int CalculateDistance(int pId, int eId);
int GetClosestElevator(int num);
void MoveElevator(void);
void CheckPerson(void);
void ClearScreen(void);

int main(void)
{
	int i;

	for (i = 0; i < MAX_PERSON; i++)
	{
		p[i].Location = 1;
		p[i].Destination = 0;
		p[i].Direction = STOP;
		p[i].Call = false;
		p[i].ClosestElevator = -1;
		p[i].InElevator = false;
	}

	for (i = 0; i < MAX_ELEVATOR; i++)
	{
		e[i].Location = 1;
		e[i].Direction = STOP;
		e[i].CallCount = 0;
		e[i].InElevatorCount = 0;
	}

	i = 1;

	while (1)
	{
		printf("[Move %d]\n", i);
		CallElevator();
		printf("\n");
		CheckElevator();
		printf("[Result %d]\n", i);
		MoveElevator();
		CheckPerson();
		printf("\n");
		printf("Press any key to continue...");
		getc(stdin);
    getc(stdin);
    ClearScreen();
		i++;
	}
	return 0;
}

void CallElevator(void)
{
	int i, input;

	for (i = 0; i < MAX_PERSON; i++)
	{
		if (p[i].Call == false && p[i].InElevator == false)
		{
			printf("%c : You are currently at Floor %d. Would you like to call the elevator? (1. Yes, 0. No)\n", i + 65, p[i].Location);
		CallElevatorAgain:
			printf("Type here: ");
			scanf("%d", &input);
			if (input == 1)			p[i].Call = true;
			else if (input == 0)	p[i].Call = false;
			else
			{
				printf("Invalid input! Please try again.\n");
				goto CallElevatorAgain;
			}
		}
		if (p[i].Call == true && p[i].ClosestElevator == -1)
		{
			printf("%c : Which direction would you go to? (1. Up, -1. Down, 0. Cancel)\n", i + 65);
		TypeDirectionAgain:
			printf("Type here: ");
			scanf("%d", &p[i].Direction);
			if (p[i].Direction == DOWN)
			{
				if (p[i].Location == 1)
				{
					printf("%c : You can't go lower than floor 1! Please try again.\n", i + 65);
					goto TypeDirectionAgain;
				}
				else
				{
					printf("Person %c called the elevator to go down.\n", i + 65);
				}
			}
			else if (p[i].Direction == UP)
			{
				if (p[i].Location == MAX_FLOOR)
				{
					printf("%c : You can't go higher than floor %d! Please try again.\n", i + 65, MAX_FLOOR);
					goto TypeDirectionAgain;
				}
				else
				{
					printf("Person %c called the elevator to go up.\n", i + 65);
				}
			}
			else if (p[i].Direction == STOP)
			{
				p[i].Call = false;
				printf("Person %c canceled the call.\n", i + 65);
			}
		}
	}
}

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

void CheckElevator(void)
{
	int i;

	for (i = 0; i < MAX_PERSON; i++)
	{
		if (p[i].Call == true && p[i].ClosestElevator == -1)
		{
			p[i].ClosestElevator = GetClosestElevator(i);
			if (p[i].Location >= e[i].Location)
			{
				e[p[i].ClosestElevator].Direction = UP;
			}
			else
			{
				e[p[i].ClosestElevator].Direction = DOWN;
			}
			e[p[i].ClosestElevator].CallCount++;
		}

		// Got on any elevator
		if (e[p[i].ClosestElevator].Location == p[i].Location && p[i].InElevator == false)
		{
			e[p[i].ClosestElevator].CallCount--;
			e[p[i].ClosestElevator].InElevatorCount++;
			printf("%c : Got on elevator %d\n", i + 65, p[i].ClosestElevator + 1);
			p[i].InElevator = true;

			printf("%c : Which floor would you go to?\n", i + 65);
		TypeDestinationAgain:
			printf("Type here : ");
			scanf("%d", &p[i].Destination);
			if (p[i].Destination < 1)
			{
				printf("%c : You can't go lower than floor 1! Please try again.\n", i + 65);
				goto TypeDestinationAgain;
			}
			else if (p[i].Destination > MAX_FLOOR)
			{
				printf("%c : You can't go higher than floor %d! Please try again.\n", i + 65, MAX_FLOOR);
				goto TypeDestinationAgain;
			}
			if (p[i].Direction == UP && p[i].Destination < p[i].Location)
			{
				printf("%c : The destination you entered is not the way you want to go. Please try again.\n", i + 65);
				goto TypeDestinationAgain;
			}
			if (p[i].Direction == DOWN && p[i].Destination > p[i].Location)
			{
				printf("%c : The destination you entered is not the way you want to go. Please try again.\n", i + 65);
				goto TypeDestinationAgain;
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

void CheckPerson(void)
{
	int i;

	for (i = 0; i < MAX_PERSON; i++)
	{
		if (p[i].InElevator == true)
		{
			if (e[p[i].ClosestElevator].Direction == UP)
			{
				p[i].Location++;
				printf("%c : %d->%d (Elevator %d, Destination: Floor %d)\n", i + 65, p[i].Location - 1, p[i].Location, p[i].ClosestElevator + 1, p[i].Destination);
			}
			else if (e[p[i].ClosestElevator].Direction == DOWN)
			{
				p[i].Location--;
				printf("%c : %d->%d (Elevator %d, Destination: Floor %d)\n", i + 65, p[i].Location + 1, p[i].Location, p[i].ClosestElevator + 1, p[i].Destination);
			}

			// If the person arrived at the destination
			if (p[i].Destination == p[i].Location)
			{
				e[p[i].ClosestElevator].InElevatorCount--;
				if (e[p[i].ClosestElevator].InElevatorCount == 0 && e[p[i].ClosestElevator].CallCount == 0)
				{
					e[p[i].ClosestElevator].Direction = STOP;
				}
				p[i].InElevator = false;
				p[i].ClosestElevator = -1;
				p[i].Call = false;
				printf("%c : Left on floor %d\n", i + 65, p[i].Location);
			}
		}
		else
		{
			printf("%c : Is at floor %d\n", i + 65, p[i].Location);
		}
	}
}

void ClearScreen(void)
{
  system("@cls||clear");
}