#include "Duke.hpp"

Duke::Duke(Game& game, string name) : Player(game, name){
    _role = "Duke";
}

void Duke::tax(){
    reset_turn();
    _coins += 3;
}

void Duke::block(Player& player){
    if (!player._played_foreign_aid){
        throw invalid_argument("Player did not play foreign aid!");
    }
    player._coins -= 2;
    player._played_foreign_aid = false;
}

Duke::~Duke(){}