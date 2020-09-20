#------------------------------------------------------------------------------
# Sandy Sang
# Zsang
# 11/12/2017
# lab4
#------------------------------------------------------------------------------

ADT_NAME  =  BST
SOURCES   = $(ADT_NAME).c  $(ADT_NAME)Client.c
OBJECTS   = $(ADT_NAME).o  $(ADT_NAME)Client.o
HEADERS   = $(ADT_NAME).h  
EXEBIN    = $(ADT_NAME)Client
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
