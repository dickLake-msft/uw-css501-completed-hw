CXX = g++
CXXFLAGS = -Wall -g

main: main.o Driver.o CompressedString.o
	$(CXX) $(CXXFLAGS) -o main main.o Driver.o CompressedString.o

main.o: main.cpp Driver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Driver.o: Driver.h CompressedString.h

CompressedString.o: CompressedString.h