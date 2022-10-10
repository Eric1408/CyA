CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS =

all: lenguajesP02

lenguajesP02: simbolo.o alfabeto.o cadena.o lenguaje.o usage.o lenguajesP02.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o

