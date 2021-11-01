#include "../include/BigField.h"

BigField::BigField()
{
    myself.setSize(sf::Vector2f(400, 400));
    myself.setOutlineThickness(0);
    myself.setPosition(Vector2f(70, 160));

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            fields[i][j] = new Field( sf::Vector2f((myself.getPosition().x + j*40), (myself.getPosition().y + i*40)));
        }
    }

    ships[0] = new Jednomasztowiec(0);
    ships[1] = new Jednomasztowiec(1);
    ships[2] = new Jednomasztowiec(2);
    ships[3] = new Jednomasztowiec(3);
    ships[4] = new Dwumasztowiec(0);
    ships[5] = new Dwumasztowiec(1);
    ships[6] = new Dwumasztowiec(2);
    ships[7] = new Trojmasztowiec(0);
    ships[8] = new Trojmasztowiec(1);
    ships[9] = new Czteromasztowiec(0);
}


BigField::~BigField()
{
    for(int i=0; i<10; i++) delete ships[i];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            delete fields[i][j];
        }
    }
}


bool BigField::checkEmpty(Ship * ship, int x, int y){
    // x - wiersz y - kolumna
    if( ship->getHorizontal() ){// jesli poziomy
        if(ship->getType() + y > 10 || y < 0)
            return false;
        for(int i= x-1; i< x+2; i++){
            if(i<0 || i>9)
                continue;
            for(int j= y-1; j< y+ship->getType()+1; j++){
                if(j<0 || j>9)
                    continue;
                if(fields[i][j]->getMember() != nullptr)
                    return false;
            }
        }
    }

    else{    // jesli pionowy
        if(ship->getType() + x > 10 || x  < 0)
            return false;
        for(int i= x-1; i< x+ship->getType()+1; i++){
            if(i<0 || i>9)
                continue;
            for(int j= y-1; j< y+2; j++){
                if(j<0 || j>9)
                    continue;
                if(fields[i][j]->getMember() != nullptr)
                    return false;
            }
        }
    }
    return true;
}

void BigField::setEmpty(int n){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(fields[i][j]->getMember() == ships[n]){
                fields[i][j]->setMember(nullptr);
                fields[i][j]->setAssigned(false);
            }
        }
    }

}
void BigField::setAssign(Ship * ship, int x, int y){
    if( ship->getHorizontal() ){// jesli poziomy
        for(int i= x-1; i< x+2; i++){
            if(i<0 || i>9)
                continue;
            for(int j=y-1; j< y+ship->getType()+1; j++){
                if(j<0 || j>9)
                    continue;
                fields[i][j]->setAssigned(true);
            }
        }
    }

    else{    // jesli pionowy
        for(int i= x-1; i< x+ship->getType()+1; i++){
            if(i<0 || i>9)
                continue;
            for(int j= y-1; j< y+2; j++){
                if(j<0 || j>9)
                    continue;
                fields[i][j]->setAssigned(true);
            }
        }
    }



}
Field * BigField::getField(int i, int j){
   return fields[i][j];
}
Ship * BigField::getShip(int i){
    return ships[i];
}
RectangleShape * BigField::getMyself(){
    return &myself;
}
