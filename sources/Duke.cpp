#include "Duke.hpp"

Duke::Duke(Game* game, string name){
    _game = game;
    _name = name;
    _role = "Duke";
    _coins = 0;
    game->add_player(name);
}

void Duke::tax(){
    _coins += 3;
}