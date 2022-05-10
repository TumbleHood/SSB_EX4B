#include "Assassin.hpp"

Assassin::Assassin(Game* game, string name){
    _game = game;
    _name = name;
    _role = "assassin";
    _coins = 0;
    _assassinated = nullptr;
    _couped = false;
    game->add_player(this);
}

void Assassin::coup(Player* player){
    
}