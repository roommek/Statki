LIBS=-lsfml-graphics -lsfml-window -lsfml-system

gra: main.o BigField.o Czteromasztowiec.o Dwumasztowiec.o Field.o Game.o GameText.o GameWindow.o Jednomasztowiec.o Player.o Ship.o Trojmasztowiec.o 
	g++ -o gra main.o BigField.o Czteromasztowiec.o Dwumasztowiec.o Field.o Game.o GameText.o GameWindow.o Jednomasztowiec.o Player.o Ship.o Trojmasztowiec.o $(LIBS)
	
main.o: main.cpp include/BigField.h include/Czteromasztowiec.h include/Trojmasztowiec.h include/Dwumasztowiec.h include/Jednomasztowiec.h include/Game.h include/GameText.h include/Player.h include/Ship.h
	g++ -c main.cpp 

BigField.o: src/BigField.cpp include/BigField.h
	g++ -c src/BigField.cpp

Czteromasztowiec.o: src/Czteromasztowiec.cpp include/Czteromasztowiec.h
	g++ -c src/Czteromasztowiec.cpp

Dwumasztowiec.o: src/Dwumasztowiec.cpp include/Dwumasztowiec.h 
	g++ -c src/Dwumasztowiec.cpp

Field.o: src/Field.cpp include/Field.h
	g++ -c src/Field.cpp

Game.o: src/Game.cpp include/Game.h
	g++ -c src/Game.cpp

GameText.o: src/GameText.cpp include/GameText.h
	g++ -c src/GameText.cpp

GameWindow.o: src/GameWindow.cpp include/GameWindow.h
	g++ -c src/GameWindow.cpp

Jednomasztowiec.o: src/Jednomasztowiec.cpp include/Jednomasztowiec.h 
	g++ -c src/Jednomasztowiec.cpp

Player.o: src/Player.cpp include/Player.h
	g++ -c src/Player.cpp

Ship.o: src/Ship.cpp include/Ship.h
	g++ -c src/Ship.cpp

Trojmasztowiec.o: src/Trojmasztowiec.cpp include/Trojmasztowiec.h 
	g++ -c src/Trojmasztowiec.cpp

clean:
	rm *.o gra