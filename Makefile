# make          # compile all binary
# make clean    # remove all objects and executable files
# $@            # Name of the current target
# $^            # List of dependencies of the current target

CC = gcc        # compiler to use
CFLAGS = -W -Wall
TARGET = app.out
OBJECTS = main.o person.o elevator.o

all : $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Linked all object files"

main.o: src/main.c src/person.h src/elevator.h
	@$(CC) $(CFLAGS) -c -o $@ src/main.c
	@echo "Builded main.o"

person.o: src/person.c src/person.h src/elevator.h
	@$(CC) $(CFLAGS) -c -o $@ src/person.c
	@echo "Builded person.o"

elevator.o: src/elevator.c src/person.h src/elevator.h
	@$(CC) $(CFLAGS) -c -o $@ src/elevator.c
	@echo "Builded elevator.o"

.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm $(OBJECTS)
	@echo "Removed all object files"