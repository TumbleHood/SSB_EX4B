#include "Contessa.hpp"
#include "Assassin.hpp"

Contessa::Contessa(Game& game, string name) : Player(game, move(name)){
    _role = "Contessa";
}

void Contessa::block(Player& player){
    if (player.role() != "Assassin"){
        throw invalid_argument("Contessa can only block an Assassin!");
    }
    if (!dynamic_cast<Assassin*>(&player)->_couped){
        throw invalid_argument("Assassin did not coup!");
    }
    dynamic_cast<Assassin*>(&player)->uncoup();
}

Contessa::~Contessa(){}