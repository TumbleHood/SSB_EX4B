#include "Player.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"

void Player::income(){
    reset_turn();
    _coins++;
}

void Player::foreign_aid(){
    reset_turn();
    _coins += 2;
    _played_foreign_aid = true;
}

int Player::coins(){
    return _coins;
}

string Player::role(){
    return _role;
}

string Player::get_name(){
    return _name;
}

void Player::coup(Player* player){ //except for assassin
    reset_turn();
    if (coins() < 7){
        throw invalid_argument("Player does not have enough coins to coup!");
    }
    _game->remove_player(player);
}

void Player::reset_turn(){
    if (role() == "Captain"){
        ((Captain*)this)->_stole = false;
    }
    else if (role() == "Assassin"){
        ((Assassin*)this)->_couped = false;
    }
    else if (role() == "Ambassador"){
        ((Ambassador*)this)->_transfered = false;
    }
    _played_foreign_aid = false;
}