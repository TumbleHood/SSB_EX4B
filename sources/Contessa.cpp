#include "Contessa.hpp"

Contessa::Contessa(Game* game, string name){
    _game = game;
    _name = name;
    _role = "Contessa";
    _coins = 0;
    game->add_player(name);
}