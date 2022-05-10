#include "Ambassador.hpp"

Ambassador::Ambassador(Game* game, string name){
    _game = game;
    _name = name;
    _role = "Ambassador";
    _coins = 0;
    _from_player = nullptr;
    _to_player = nullptr;
    _transfered = false;
    game->add_player(this);
}

void Ambassador::transfer(Player* from_player, Player* to_player){
    _from_player = from_player;
    _to_player = to_player;
    from_player->_coins--;
    to_player->_coins++;
    _transfered = true;
}

void Ambassador::untransfer(){
    _from_player->_coins++;
    _to_player->_coins++;
    _transfered = true;
}