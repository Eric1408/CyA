CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS = 

all: multbigint

multbigint: usage.o karatsuba.o BigInt.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o