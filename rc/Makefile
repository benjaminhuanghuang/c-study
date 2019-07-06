CXX = gcc
CXXFLAGS = -std=c99 -pedantic -Wvla -Wall -Wshadow  # put compiler settings here

SOURCES = *.c
EXEBIN = pa2.out

main: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEBIN) 

clean :
	rm -f *.out