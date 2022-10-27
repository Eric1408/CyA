CXX = g++
CXXFLAGS = -std=c++14 -g -Wall
LDFLAGS =

all: p04_code_analyzer

p04_code_analyzer: analyzer.o var.o loop.o comment.o description.o usage.o analyzer_main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -rf *.o

