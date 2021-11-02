#include "../include/Dwumasztowiec.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Dwumasztowiec::Dwumasztowiec(int number)
{
    type=2;
    position.x=620+ number*120;
    position.y=310;
    texture.loadFromFile("assets/statek2.png");
    try{
            if (!texture.loadFromFile("assets/statek2.png"))
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
    drawing.setPosition(620+ number*120, 310);
    homePosition = Vector2f(620+ number*120, 310);
    number++;
}

Dwumasztowiec::~Dwumasztowiec()
{
    //dtor
}

void Dwumasztowiec::changeTexture()
{
     texture.loadFromFile("assets/statek2DESTROYED.png");
     try{
            if (!texture.loadFromFile("assets/statek2DESTROYED.png"))
                throw(texture);
        }
    catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }
}
