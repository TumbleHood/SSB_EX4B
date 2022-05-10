#include "Assassin.hpp"

Assassin::Assassin(Game* game, string name){
    _game = game;
    _name = name;
    _role = "assassin";
    _coins = 0;
    _assassinated = nullptr;
    _assassinated_number = 0;
    _couped = false;
    game->add_player(this);
}

void Assassin::coup(Player* player){
    reset_turn();
    if (coins() < 3){
        throw invalid_argument("Player does not have enough coins to coup!");
    }
    _assassinated = player;
    _assassinated_number = _game->get_player_number(player);
    _game->remove_player(player);
    _couped = true;
}

void Assassin::uncoup(){
    _game->add_player(_assassinated, _assassinated_number);
    _assassinated = nullptr;
    _assassinated_number = 0;
    _couped = false;
}

Assassin::~Assassin(){}