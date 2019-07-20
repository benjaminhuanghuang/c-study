EXEBIN    = pa4
SOURCES   = pa4.c hashtable.c
FLAGS     = -std=c99 -Wall

all: $(EXEBIN)

$(EXEBIN) : $(SOURCES)
	gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic $(SOURCES) -o $(EXEBIN)

clean :
	rm -f $(EXEBIN)
