OBJS	= main.o stack.o
SOURCE	= main.cpp stack.cpp
HEADER	= core.h stack.h
OUT	= Program
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

stack.o: stack.cpp
	$(CC) $(FLAGS) stack.cpp 


clean:
	rm -f $(OBJS) $(OUT)