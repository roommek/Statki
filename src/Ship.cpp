#include "Ship.h"

Ship::Ship(){
    horizontal=true;
    assigned = false;
    damage = 0;
    sunk = false;
}


bool Ship::isHover(RenderWindow & window){
    if(    sf::Mouse::getPosition(window).x > (drawing.getPosition().x - drawing.getGlobalBounds().width/2.0f )
        && sf::Mouse::getPosition(window).x < (drawing.getPosition().x + drawing.getGlobalBounds().width/2.0f )
        && sf::Mouse::getPosition(window).y > (drawing.getPosition().y - drawing.getGlobalBounds().height/2.0f )
        && sf::Mouse::getPosition(window).y < (drawing.getPosition().y + drawing.getGlobalBounds().height/2.0f ) ){

        return true;
    }
    return false;
}

void Ship::setRotation(){
    drawing.setRotation(drawing.getRotation() + 90);
    fixPosition();
    if(horizontal) horizontal = false;
    else horizontal = true;
}

int Ship::getLeft(){
    return ( position.x - ( drawing.getGlobalBounds().width/2.0f ) );
}


int Ship::getTop(){
    return ( position.y - ( drawing.getGlobalBounds().height/2.0f ) );

}

void Ship::fixPosition(){
    drawing.setOrigin(drawing.getLocalBounds().left + drawing.getLocalBounds().width/2.0f,
                      drawing.getLocalBounds().top  + drawing.getLocalBounds().height/2.0f);
}

Ship::~Ship()
{
    //dtor
}


void Ship::goHome(){
    position.x = homePosition.x;
    position.y = homePosition.y;
    drawing.setPosition(homePosition.x, homePosition.y);
}


int Ship::getType(){
    return type;
}

void Ship::setType(int x){
    type=x;
}

Vector2f Ship::getPosition(){
    return position;
}

Vector2f Ship::setPosition(int type, int value){
   if(type) position.y=value;
   else  position.x=value;
}

Sprite Ship::getDrawing(){
    return drawing;
}

Sprite * Ship::setDrawing(){
    return &drawing;
}
void Ship::setHorizontal(bool input_horizontal){
    horizontal = input_horizontal;
}
bool Ship::getHorizontal(){
    return horizontal;
}
void Ship::setAssigned(bool input_assigned){
    assigned = input_assigned;
}
bool Ship::getAssigned(){
    return assigned;
}
void Ship::setSunk(bool input_sunk){
    sunk = input_sunk;
}
bool Ship::getSunk(){
    return sunk;
}
void Ship::setDamage(int input_damage){
    damage = input_damage;
}
int Ship::getDamage(){
    return damage;
}
