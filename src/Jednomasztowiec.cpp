#include "../include/Jednomasztowiec.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Jednomasztowiec::Jednomasztowiec(int number)
{
    type=1;
    position.x=600 + number*60;
    position.y=210;
    texture.loadFromFile("statek1.png");
    try{
            if (!texture.loadFromFile("statek1.png"))
                throw(texture);
        }
    catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }
    drawing.setTexture(texture);
    drawing.setOrigin(drawing.getLocalBounds().left + drawing.getLocalBounds().width/2.0f,
                      drawing.getLocalBounds().top  + drawing.getLocalBounds().height/2.0f);
    drawing.setPosition(600 + number*60, 210);
    homePosition = Vector2f(600 + number*60, 210);
    number++;
}

Jednomasztowiec::~Jednomasztowiec()
{
    //dtor
}

void Jednomasztowiec::changeTexture()
{
    texture.loadFromFile("statek1DESTROYED.png");
    try{
            if (!texture.loadFromFile("statek1DESTROYED.png"))
                throw(texture);
    }
    catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }
}
