/*! \file Jednomasztowiec.h
    \brief Header file for Jednomasztowiec module.
*/

#ifndef JEDNOMASZTOWIEC_H
#define JEDNOMASZTOWIEC_H

#include <Ship.h>


class Jednomasztowiec : public Ship
{
    public:
        Jednomasztowiec(int= 0);
        virtual ~Jednomasztowiec();
        void changeTexture();

    protected:

    private:
};

#endif // JEDNOMASZTOWIEC_H
