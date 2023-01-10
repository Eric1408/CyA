CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = 

all: multbigint
#multbignint: usage.o karatsuba.o BigInt.o main.o
multbigint: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o