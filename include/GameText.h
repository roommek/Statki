/*! \file GameText.h
    \brief Header file for GameText module.
*/

#ifndef GAMETEXT_H
#define GAMETEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>


class GameText
{
    public:
        sf::Text text;
        GameText(sf::String &, sf::Font &, int, sf::Vector2f, sf::Uint32, sf::Color );
        virtual ~GameText();
        bool isHover(sf::RenderWindow &);
    protected:

    private:
};

#endif // GAMETEXT_H
