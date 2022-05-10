#include "Duke.hpp"

Duke::Duke(Game* game, string name){
    _game = game;
    _name = name;
    _role = "Duke";
    _coins = 0;
    game->add_player(this);
}

void Duke::tax(){
    reset_turn();
    _coins += 3;
}

void Duke::block(Player* player){
    if (!player->_played_foreign_aid){
        throw invalid_argument("Player did not play foreign aid!");
    }
    player->_coins -= 2;
    player->_played_foreign_aid = false;
}

Duke::~Duke(){}