BREAKPOINTS = 
OPTIMIZE = 

all: lsalg.cpp lsrun.cpp
	g++ lsrun.cpp $(BREAKPOINTS) -g $(OPTIMIZE) -std=c++17 -o lsrun.bin

opt: OPTIMIZE = -O2
opt: all

d: BREAKPOINTS = -D MYDEBUG_BREAK
d: all