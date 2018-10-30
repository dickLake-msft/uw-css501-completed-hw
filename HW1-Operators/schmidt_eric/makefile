CXX = g++
CXXFLAGS = -Wall -g

main: main.o Color.o Driver.o
	$(CXX) $(CXXFLAGS) -o main main.o Color.o Driver.o

main.o: main.cpp Color.h Driver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Driver.o: Driver.h Color.h

Color.o: Color.h