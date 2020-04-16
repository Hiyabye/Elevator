app.out: main.o person.o elevator.o
	@gcc -o app.out main.o person.o elevator.o
	@echo "Linked all files"

main.o: main.c person.h elevator.h
	@gcc -c -o main.o main.c
	@echo "Builded main.c"

person.o: person.c person.h elevator.h
	@gcc -c -o person.o person.c
	@echo "Builded person.c"

elevator.o: elevator.c person.h elevator.h
	@gcc -c -o elevator.o elevator.c
	@echo "Builded elevator.c"

clean:
	@rm -f *.o
	@echo "Removed all object files"