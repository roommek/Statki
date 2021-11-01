#include "../include/BigField.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Czteromasztowiec::Czteromasztowiec(int number)
{
    type=4;
    position.x=660+ number*160;
    position.y=510;
    texture.loadFromFile("statek4.png");
    try{
            if (!texture.loadFromFile("statek4.png"))
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
    drawing.setPosition(660+ number*160, 510);
    homePosition = Vector2f(660+ number*160, 510);
    number++;
}

Czteromasztowiec::~Czteromasztowiec()
{
    //dtor
}

void Czteromasztowiec::changeTexture()
{
     texture.loadFromFile("statek4DESTROYED.png");
     try{
            if (!texture.loadFromFile("statek4DESTROYED.png"))
                throw(texture);
        }
    catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }
}
