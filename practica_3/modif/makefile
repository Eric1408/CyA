CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS =

all: CalculadoraRPN_P03

CalculadoraRPN_P03: simbolo.o alfabeto.o cadena.o lenguaje.o notacion_polaca.o usage.o calculadoraRPN.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o

