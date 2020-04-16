app.out: elevator.o
	@gcc -o app.out elevator.o
	@echo "Linked all files"

elevator.o: elevator.c
	@gcc -c -o elevator.o elevator.c
	@echo "Builded elevator.c"

clean:
	@rm -f *.o
	@echo "Removed all object files"