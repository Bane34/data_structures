OBJS	= main.o stack.o queue.o
SOURCE	= main.cpp stack.cpp queue.cpp
HEADER	= core.h stack.h queue.h
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


clean:
	rm -f $(OBJS) $(OUT)