/*! \file Game.h
    \brief Header file for Game module.
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "Player.h"
#include "Ship.h"
#include "Field.h"
#include "BigField.h"
#include "GameText.h"
using namespace sf;

class Game
{
    public:
        Game();
        virtual ~Game();
        /*! \fn int menu(RenderWindow &);
        \brief wyswietla menu
        \param Window okno programu
        */
        int menu(RenderWindow &);

         /*! \fn string setPlayer(RenderWindow &);
        \brief ustawia nazwy graczy
        \param Window okno programu
        */
        string setPlayer(RenderWindow &);

         /*! \fn void draw(RenderWindow &, int);
        \brief funkcja pomocnicza przy ustawianiu statkow
        \param Window okno programu
        \param playerNum numer gracza
        */
        void draw(RenderWindow &, int);

         /*! \fn void setShips(RenderWindow &, int)
        \brief ustawianie statkow
        \param Window okno programu
        \param playerNum numer gracza
        */
        void setShips(RenderWindow &, int);

        /*! \fn void setField();
        \brief ustawianie pozycji pol
        */
        void setField();

         /*! \fn bool setShipPosition(RenderWindow &, int, int );
        \brief Funkcja przesowajaca statek
        \param Window okno programu
        \param n numer statku
        */
        bool setShipPosition(RenderWindow &, int, int );

        /*! \fn int isOver();
        \brief sprawdza czy gra jest skonczona
        */
        int isOver();

        /*! \fn bool turn(RenderWindow &, int);
        \brief funkcja obslugujaca ruch kazdego gracza
        \param Window okno programu
        \param i pomocniczy przy wyborze gracza, ktory ma ture
        */
        bool turn(RenderWindow &, int);

        /*! \fn void drawAll(RenderWindow &, int=0);
        \brief rysuje plansze i statki
        \param Window okno programu
        \param opt opcja rysowania
        */
        void drawAll(RenderWindow &, int=0);

        /*! \fn void assignField(RenderWindow &, BigField &, bool &, int);
        \brief Przypisuje pole
        \param Window okno programu
        \param bigField duze pole
        \param isInside infomuje czy jestes w polu
        \param i numer statku
        */
        void assignField(RenderWindow &, BigField &, bool &, int);

        /*! \fn void drawAll(RenderWindow &, int=0);
        \brief tworzy graczy
        \param Window okno programu
        */
        void setPlayers(RenderWindow &);

        /*! \fn void drawAll(RenderWindow &, int=0);
        \brief zwraca gracza
        \param palyerNum numer gracza
        */
        Player * getPlayer(int);
    protected:

    private:
        Player * players[2];
};

#endif // GAME_H
