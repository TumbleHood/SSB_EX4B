#include "Assassin.hpp"

Assassin::Assassin(Game& game, string name) : Player(game, name) {
    _role = "Assassin";
    _assassinated = nullptr;
    _assassinated_number = 0;
    _couped = false;
}

void Assassin::coup(Player& player){
    reset_turn();
    if (coins() < 3){
        throw invalid_argument("Player does not have enough coins to coup!");
    }
    _assassinated = &player;
    _assassinated_number = _game->get_player_number(&player);
    _game->remove_player(&player);
    _couped = true;
}

void Assassin::uncoup(){
    _game->add_player(_assassinated, _assassinated_number);
    _assassinated = nullptr;
    _assassinated_number = 0;
    _couped = false;
}

Assassin::~Assassin(){}