#include "Player.hpp"

void Player::income(){
    _coins++;
}

void Player::foreign_aid(){
    _coins += 2;
}

int Player::coins(){
    return _coins;
}

string Player::role(){
    return _role;
}