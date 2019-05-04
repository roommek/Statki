/*! \file BigField.h
    \brief Header file for BigField module.
*/

#ifndef BIGFIELD_H
#define BIGFIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "Field.h"
#include "Ship.h"
#include "Jednomasztowiec.h"
#include "Dwumasztowiec.h"
#include "Trojmasztowiec.h"
#include "Czteromasztowiec.h"



class BigField
{
    public:
        BigField();
        virtual ~BigField();

        /*! \fn bool checkEmpty(Ship *, int, int);
        \brief sprawdza czy pole na ktoremy chcemy postawic statek jest puste czy zajete
        \param Ship statek, ktory chcemy postawic
        \param x pierwsza wspolrzedna.
        \param x druga wspolrzedna.
        */
        bool checkEmpty(Ship *, int, int);

        /*! \fn void setEmpty(int);
        \brief Ustawia pola na puste po przeniesieniu statku
        \param n numer statku
        */
        void setEmpty(int);

        /*! \fn void setAssign(Ship *, int, int);
        \brief Ustawia pola na zajete po ustawieniu statku
        \param ship umieszczany statek
        \param x wspolrzedna
        \param y wspolrzedna
        */
        void setAssign(Ship *, int, int);
        Field * getField(int, int);
        Ship * getShip(int);
        RectangleShape * getMyself();
    protected:

    private:
        RectangleShape myself;
        Field *fields[10][10];
        Ship * ships[10];


};

#endif // BIGFIELD_H
