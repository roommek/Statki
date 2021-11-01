/*! \file Player.h
    \brief Header file for Player module.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>


#include "Field.h"
#include "BigField.h"
#include "Ship.h"
#include "Jednomasztowiec.h"
#include "Dwumasztowiec.h"
#include "Trojmasztowiec.h"
#include "Czteromasztowiec.h"



using namespace sf;

class Player
{
    public:
        Player(string = "");
        virtual ~Player();

        /*! \fn string getName();
        \brief Zwraca nazwe gracza
        */
        string getName();

        /*! \fn void setName(string);
        \brief Ustawia nazwe gracza
        \param input_name nazwa gracza
        */
        void setName(string);

        /*! \fn int getHits();
        \brief Zwraca ilosc trafien
        */
        int getHits();

        /*! \fn void setHits(int);
        \brief Ustawia ilosc trafien
        \param input_hits ilosc trafien
        */
        void setHits(int);
        BigField * getBigField();
    protected:

    private:
        BigField bigField;
        string name;
        int hits;
};

#endif // PLAYER_H
