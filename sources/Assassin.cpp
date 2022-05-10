#include "Assassin.hpp"

Assassin::Assassin(Game* game, string name){
    _game = game;
    _name = name;
    _role = "assassin";
    _coins = 0;
    game->add_player(name);
}