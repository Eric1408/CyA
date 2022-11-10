CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = 

all: p06_automata_simulator

p06_automata_simulator: usage.o automata.o estado.o alfabeto.o simbolo.o automata_main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o