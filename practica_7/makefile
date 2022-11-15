CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = 

all: dfa2grammar

dfa2grammar: usage.o automata.o estado.o alfabeto.o simbolo.o automata_main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o