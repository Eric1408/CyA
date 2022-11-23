CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = 

all: dfa2grammar

dfa2grammar: alfabeto.o simbolo.o gramatica.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o