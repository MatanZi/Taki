CXX = g++
CXXFLAGS = -std=c++0x

all: main.o Card.o Game.o Player.o
	$(CXX) $(CXXFLAGS) main.o Card.o Game.o Player.o
	./a.out

Card.o: Card.cpp Card.h
	$(CXX) $(CXXFLAGS) -c Card.cpp -o Card.o

Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp -o Game.o

Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out
