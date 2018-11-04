CXX = g++
CXXFLAGS = -Wall -g

main: main.o Package.o DeliveryManager.o Driver.o
	$(CXX) $(CXXFLAGS) -o main main.o Package.o DeliveryManager.o Driver.o

main.o: main.cpp Driver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Package.o: Package.h

DeliveryManager.o: DeliveryManager.h Package.h

Driver.o: Driver.h DeliveryManager.h Package.h