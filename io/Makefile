APP_NAME  =  io-demo
SOURCES   = $(APP_NAME).c  
OBJECTS   = $(APP_NAME).o  
#HEADERS   = $(APP_NAME).h  
EXEBIN    = $(APP_NAME).exe
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