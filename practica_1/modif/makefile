CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS =

all: p01_strings

p01_strings: simbolo.o alfabeto.o cadena.o usage.o p01_strings_main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o

