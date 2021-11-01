#include "../include/Field.h"
#include <fstream>

Field::Field(Vector2f vect)
{
    sizes.x = 40;
    sizes.y = 40;
    position.x = vect.x;
    position.y = vect.y;
    texture.loadFromFile( "puste pole.png");
    try{
            if (!texture.loadFromFile("puste pole.png"))
                throw(texture);
        }
    catch(Texture){
            std::ofstream errorFile ("logs.txt");
            errorFile << "error texture is missing" << std::endl;
            errorFile.close();
            exit(0);
    }
    drawing.setTexture(texture);
    drawing.setPosition(vect.x, vect.y);
    member = nullptr;
    assigned=false;
    boom=false;
}

Field::~Field()
{
    //dtor
}
Ship * Field::getMember(){
    return member;
}
void Field::setMember(Ship * input_member){
    member = input_member;
}
bool Field::getAssigned(){
    return assigned;
}
void Field::setAssigned(bool input_assigned){
    assigned = input_assigned;
}
bool Field::getBoom(){
    return boom;
}
void Field::setBoom(bool input_boom){
    boom = input_boom;
}

Vector2f Field::getPosition(){
    return position;
}

Vector2f Field::setPosition(int type, int value){
    if(type) position.y=value;
    else position.x=value;
}

Vector2f Field::getSizes(){
     return sizes;
}

Vector2f Field::setSizes(int type, int value){
    if(type) sizes.y=value;
    else sizes.x=value;
}

Texture * Field::getTexture(){
    return &texture;
}

Sprite * Field::getDrawing(){
    return &drawing;
}
