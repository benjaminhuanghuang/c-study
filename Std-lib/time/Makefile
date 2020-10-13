C      = gcc
FLAGS  = -Wall -std=c11 -g


all: time-demo.exe max-time.exe

clean:
	rm -f *.exe

%.exe : %.c Makefile
	$(C) -o $*.exe $(FLAGS) $*.c