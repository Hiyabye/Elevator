#include <stdio.h>
#include "person.h"
#include "elevator.h"

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

void ClearScreen(void)
{
  system("@cls||clear");
}