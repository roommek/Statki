#include "../include/Trojmasztowiec.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Trojmasztowiec::Trojmasztowiec(int number)
{
    type=3;
    position.x=640 + number*180;
    position.y= 410;
    texture.loadFromFile("assets/statek3.png");
    try{
            if (!texture.loadFromFile("assets/statek3.png"))
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
    drawing.setPosition(640 + number*180, 410);
    homePosition = Vector2f(640 + number*180, 410);
    number++;
}

Trojmasztowiec::~Trojmasztowiec()
{
    //dtor
}

void Trojmasztowiec::changeTexture()
{
     texture.loadFromFile("assets/statek3DESTROYED.png");
     try{
            if (!texture.loadFromFile("assets/statek3DESTROYED.png"))
                throw(texture);
        }
    catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }
}
