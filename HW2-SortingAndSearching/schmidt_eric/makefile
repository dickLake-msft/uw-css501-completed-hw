CXX = g++
CXXFLAGS = -Wall -g

main: main.o Driver.o List.o Player.o
	$(CXX) $(CXXFLAGS) -o main main.o Driver.o List.o Player.o

main.o: main.cpp Driver.h List.h Player.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Driver.o: Driver.h List.h Player.h

List.o: List.h Player.h

Player.o: Player.h