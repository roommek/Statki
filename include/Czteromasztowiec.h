/*! \file Czteromasztowiec.h
    \brief Header file for Czteromasztowiec module.
*/

#ifndef CZTEROMASZTOWIEC_H
#define CZTEROMASZTOWIEC_H

#include <Ship.h>


class Czteromasztowiec : public Ship
{
    public:
        Czteromasztowiec(int= 0);
        virtual ~Czteromasztowiec();
        void changeTexture();

    protected:

    private:
};
#endif // CZTEROMASZTOWIEC_H
