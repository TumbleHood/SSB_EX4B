#include "Captain.hpp"

Captain::Captain(Game& game, string name) : Player(game, name){
    _role = "Captain";
    _stolen = nullptr;
    _stole = false;
}

void Captain::steal(Player& player){
    reset_turn();
    player._coins -= 2;
    _coins += 2;
    _stolen = &player;
    _stole = true;
}

void Captain::unsteal(){
    _stolen->_coins += 2;
    _coins -= 2;
    _stole = false;
}

void Captain::block(Player& player){
    if (player.role() != "Captain"){
        throw invalid_argument("Captain can only block a Captian!");
    }
    if (!((Captain*)&player)->_stole){
        throw invalid_argument("Player did not steal!");
    }
    ((Captain*)&player)->unsteal();
}

Captain::~Captain(){}