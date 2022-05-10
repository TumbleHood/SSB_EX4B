#include "Contessa.hpp"
#include "Assassin.hpp"

Contessa::Contessa(Game& game, string name) : Player(game, name){
    _role = "Contessa";
}

void Contessa::block(Player& player){
    if (player.role() != "Assassin"){
        throw invalid_argument("Contessa can only block an Assassin!");
    }
    if (!((Assassin*)&player)->_couped){
        throw invalid_argument("Assassin did not coup!");
    }
    ((Assassin*)&player)->uncoup();
}

Contessa::~Contessa(){}