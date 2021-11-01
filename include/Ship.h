/*! \file Ship.h
    \brief Header file for Ship module.
*/

#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <iostream>



using namespace sf;

class Ship
{
    public:
        Ship();
        virtual ~Ship();

        /*! \fn bool isHover(RenderWindow &);
        \brief Zwraca true jesli myszka na statku
        \param window - okno programu
        */
        bool isHover(RenderWindow &);

        /*! \fn void setRotation();
        \brief Obraca statek
        */
        void setRotation();

        /*! \fn void fixPosition();
        \brief Poprawia pozycje statku po obrocie
        */
        void fixPosition();

        /*! \fn int getLeft();
        \brief Zwraca wspolrzedna X lewego skrajnego punktu statku
        */
        int getLeft();

        /*! \fn int getTop();
        \brief Zwraca wspolrzedna Y gornego skrajnego punktu statku
        */
        int getTop();

        /*! \fn void goHome();
        \brief Przesuwa statek z powrotem na pozycje poczatkowa
        */
        void goHome();

        /*! \fn virtual void changeTexture()=0;
        \brief Czysto wirtualna funkcja do zmiany tekstury
        */
        virtual void changeTexture()=0;

        /*! \fn int getType();
        \brief Zwraca typ statku
        */
        int getType();
        void setType(int);
        Vector2f getPosition();

        /*! \fn Vector2f setPosition(int, int);
        \brief Ustawia pozycje statku
        \param type - typ wspolrzednej, jesli 0 to X, w innym przypadku Y
        \param y wspolrzedna
        */
        Vector2f setPosition(int, int);
        Sprite getDrawing();
        Sprite *setDrawing();
        void setHorizontal(bool);
        bool getHorizontal();
        void setAssigned(bool);
        bool getAssigned();
        void setSunk(bool);
        bool getSunk();
        void setDamage(int);

        /*! \fn int getDamage();
        \brief Zwraca ilosc otrzymanych obrazen
        */
        int getDamage();


    protected:
        Vector2f position;
        Texture texture;
        Sprite drawing;
        bool horizontal;
        int type;
        bool assigned;
        int damage;
        bool sunk;
        Vector2f homePosition;

};

#endif // SHIP_H
