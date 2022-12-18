CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
LDFLAGS =

all: monedas

monedas: usage.o voraces.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY:
	$(CXX) $(CXXFLAGS) -c $<

clean: 
	rm -rf *.o