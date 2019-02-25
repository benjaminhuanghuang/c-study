ADT_NAME  =  BST
SOURCES   = $(ADT_NAME).c  BSTClient.c
OBJECTS   = $(ADT_NAME).o  BSTClient.o
HEADERS   = $(ADT_NAME).h  
EXEBIN    = BSTClient
FLAGS     = -std=c99 -Wall

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS) $(HEADERS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES) $(HEADERS)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

check:
	valgrind --leak-check=full $(EXEBIN) 
