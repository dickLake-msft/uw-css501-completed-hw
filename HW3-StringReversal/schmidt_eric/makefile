CXX = g++
CXXFLAGS = -Wall -g

main: main.o Driver.o List.o
	$(CXX) $(CXXFLAGS) -o main main.o Driver.o List.o

main.o: main.cpp Driver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Driver.o: Driver.h List.h

List.o: List.h