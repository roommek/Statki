/*! \file Dwumasztowiec.h
    \brief Header file for Dwumasztowiec module.
*/

#ifndef DWUMASZTOWIEC_H
#define DWUMASZTOWIEC_H

#include "Ship.h"


class Dwumasztowiec : public Ship
{
    public:
        Dwumasztowiec(int= 0);
        virtual ~Dwumasztowiec();
        void changeTexture();

    protected:

    private:
};


#endif // DWUMASZTOWIEC_H
