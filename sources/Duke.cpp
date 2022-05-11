#include "Duke.hpp"

Duke::Duke(Game& game, string name) : Player(game, move(name)){
    _role = "Duke";
}

void Duke::tax(){
    if (!_game->_ongoing && (_game->players().size() > MAX_PLAYERS || _game->players().size() < MIN_PLAYERS)){
        throw invalid_argument("Not enough players!");
    }
    _game->_ongoing = true;
    if (_game->real_turn() != this){
        throw invalid_argument("Not your turn");
    }
    if (coins() >= COINS_FOR_MUST_COUP){
        throw invalid_argument("You must coup when you have 10 coins or more!");
    }
    reset_turn();
    _coins += COIN_FOR_TAX;
    _game->advance_turn();
}

void Duke::block(Player& player){
    if (!player._played_foreign_aid){
        throw invalid_argument("Player did not play foreign aid!");
    }
    player._coins -= COIN_FOR_FOREIGN_AID;
    player._played_foreign_aid = false;
}

Duke::~Duke(){}