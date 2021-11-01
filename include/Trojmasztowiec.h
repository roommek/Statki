/*! \file Trojmasztowiec.h
    \brief Header file for Trojmasztowiec module.
*/

#ifndef TROJMASZTOWIEC_H
#define TROJMASZTOWIEC_H

#include "Ship.h"


class Trojmasztowiec : public Ship
{
    public:
        Trojmasztowiec(int= 0);
        virtual ~Trojmasztowiec();
        void changeTexture();

    protected:

    private:
};

#endif // TROJMASZTOWIEC_H
