OBJS	= main.o stack.o queue.o list.o trees.o
SOURCE	= main.cpp stack.cpp queue.cpp list.cpp trees.cpp
HEADER	= core.h stack.h queue.h list.h trees.h
OUT	= Data_structures
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

stack.o: stack.cpp
	$(CC) $(FLAGS) stack.cpp 

queue.o: queue.cpp
	$(CC) $(FLAGS) queue.cpp 

list.o: list.cpp
	$(CC) $(FLAGS) list.cpp

trees.o: trees.cpp
	$(CC) $(FLAGS) trees.cpp

clean:
	rm -f $(OBJS) $(OUT)