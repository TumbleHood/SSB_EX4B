#include "Captain.hpp"

Captain::Captain(Game* game, string name){
    _game = game;
    _name = name;
    _role = "Captain";
    _coins = 0;
    game->add_player(name);
}

void Captain::steal(Player& player){
    player._coins -= 2;
    _coins += 2;
}