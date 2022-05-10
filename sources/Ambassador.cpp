#include "Ambassador.hpp"
#include "Captain.hpp"

Ambassador::Ambassador(Game& game, string name) : Player(game, name){
    _role = "Ambassador";
    _from_player = nullptr;
    _to_player = nullptr;
    _transfered = false;
}

void Ambassador::transfer(Player& from_player, Player& to_player){
    reset_turn();
    _from_player = &from_player;
    _to_player = &to_player;
    from_player._coins--;
    to_player._coins++;
    _transfered = true;
}

void Ambassador::untransfer(){
    _from_player->_coins++;
    _to_player->_coins++;
    _transfered = true;
}

void Ambassador::block(Player& player){
    if (player.role() != "Captain"){
        throw invalid_argument("Ambassador can only block a Captian!");
    }
    if (!((Captain*)&player)->_stole){
        throw invalid_argument("Player did not steal!");
    }
    ((Captain*)&player)->unsteal();
}

Ambassador::~Ambassador(){}