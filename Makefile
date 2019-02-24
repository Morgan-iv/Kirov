BREAKPOINTS = 
OPTIMIZE = 

all: lsalg.hpp lsrun.cpp mypprint.hpp
	g++ lsrun.cpp $(BREAKPOINTS) -g $(OPTIMIZE) -std=c++17 -o lsrun.bin

opt: OPTIMIZE = -O2
opt: all

d: BREAKPOINTS = -D MYDEBUG_BREAK
d: all
