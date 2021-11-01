/*! \file Field.h
    \brief Header file for Field module.
*/
#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>


#include "Ship.h"

using namespace std;
using namespace sf;

class Field
{
    public:
        Field(Vector2f);
        Field();
        virtual ~Field();

        /*! \fn Ship * getMember();
        \brief Zwraca wskaznik na przypisany statek
        */
        Ship * getMember();

        /*! \fn void setMember(Ship *);
        \brief Przypisuje statek
        \param input_member wskaznik na statek
        */
        void setMember(Ship *);

        /*! \fn  bool getAssigned();
        \brief Zwraca true jesli przypisany statek
        */
        bool getAssigned();

        /*! \fn void setAssigned(bool);
        \brief Ustawia zmienna assigned na true
        \param input_assigned nowa wartosc zmiennej do ustawienia
        */
        void setAssigned(bool);

        /*! \fn bool getBoom();
        \brief Zwraca true jesli pole bylo juz klikniete
        */
        bool getBoom();

        /*! \fn void setBoom(bool);
        \brief Ustawia wartosc zmiennej boom
        \param input_boom nowa wartosc zmiennej
        */
        void setBoom(bool);

        /*! \fn Vector2f getPosition();
        \brief Zwraca pozycje pola
        */
        Vector2f getPosition();

        /*! \fn Vector2f setPosition(int, int);
        \brief Ustawia pozycje statku
        \param type ktora wspolrzedna jesli 0 to X w innym przypadku Y
        \param value nowa wartosc wspolrzednej
        */
        Vector2f setPosition(int, int);

        /*! \fn Vector2f getSizes();
        \brief Zwraca wymiary pola
        */
        Vector2f getSizes();

        /*! \fn Vector2f setSizes(int, int);
        \brief Ustawia wymiary pola
        \param type - typ wspolrzednej, jesli 0 to X, w innym przypadku Y
        \param y nowa wartosc wspolrzednej
        */
        Vector2f setSizes(int, int);

        /*! \fn Texture * getTexture();
        \brief Zwraca wskaznik na teksture
        */
        Texture * getTexture();

        /*! \fn Sprite *getDrawing();
        \brief Zwraca wskaznik nasprite'a
        */
        Sprite *getDrawing();

    private:
        Vector2f position, sizes;
        Ship * member;
        bool assigned;
        bool boom;
        Texture texture;
        Sprite drawing;

};

#endif // FIELD_H
