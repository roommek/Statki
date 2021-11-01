#include "../include/GameText.h"

GameText::GameText(sf::String & input , sf::Font & font, int textSize, sf::Vector2f position, sf::Uint32 style, sf::Color color)
                   :text(input, font, textSize){

    sf::FloatRect Rect = text.getLocalBounds();
    text.setOrigin(Rect.left + Rect.width/2.0f, Rect.top  + Rect.height/2.0f);
    text.setPosition(position);
    text.setStyle(style);
    text.setFillColor(color);
}

GameText::~GameText()
{
    //dtor
}
bool GameText::isHover(sf::RenderWindow & window){
    if(sf::Mouse::getPosition(window).x > (text.getPosition().x - text.getLocalBounds().width/2.0f )
                    && sf::Mouse::getPosition(window).x < (text.getPosition().x + text.getLocalBounds().width/2.0f )
                    && sf::Mouse::getPosition(window).y > (text.getPosition().y - text.getLocalBounds().height/2.0f )
                    && sf::Mouse::getPosition(window).y < (text.getPosition().y + text.getLocalBounds().height/2.0f ))

        return true;
    else
        return false;
}
