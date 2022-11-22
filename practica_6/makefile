CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = 

all: p06_automata_simulator

p06_automata_simulator: usage.o simbolo.o alfabeto.o estado.o transiciones.o automata.o automata_main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o