#include "Player.h"

Player::Player(string input_name): name(input_name), hits(0){}

Player::~Player()
{
    //dtor
}

string Player::getName(){
    return name;
}
void Player::setName(string input_name){
    name = input_name;
}
int Player::getHits(){
    return hits;
}
void Player::setHits(int input_hits){
    hits = input_hits;
}
BigField * Player::getBigField(){
    return &bigField;
}
