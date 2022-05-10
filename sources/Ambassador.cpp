#include "Ambassador.hpp"

Ambassador::Ambassador(Game* game, string name){
    _game = game;
    _name = name;
    _role = "Ambassador";
    _coins = 0;
    game->add_player(name);
}

void Ambassador::transfer(Player& from_player, Player& to_player){
    from_player._coins--;
    to_player._coins++;
}