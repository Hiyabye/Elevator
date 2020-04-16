#include <stdio.h>
#include "person.h"
#include "elevator.h"

void CallElevator(void)
{
	int i, input, notCallCount = 0;

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
		if (p[i].Call == false)
		{
			notCallCount++;
		}
	}

	if (notCallCount == MAX_PERSON)
	{
		printf("It seems nobody called the elevator.\nThank you for using this program!\n");
		exit(0);
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