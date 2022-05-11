#include "Ambassador.hpp"
#include "Captain.hpp"

Ambassador::Ambassador(Game& game, string name) : Player(game, move(name)){
    _role = "Ambassador";
}

void Ambassador::transfer(Player& from_player, Player& to_player){
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
    if (from_player.coins() == 0){
        throw invalid_argument("Player does not have enough coins!");
    }
    from_player._coins--;
    to_player._coins++;
    _game->advance_turn();
}

void Ambassador::block(Player& player){
    if (player.role() != "Captain"){
        throw invalid_argument("Ambassador can only block a Captian!");
    }
    if (!dynamic_cast<Captain*>(&player)->_stole){
        throw invalid_argument("Player did not steal!");
    }
    dynamic_cast<Captain*>(&player)->unsteal();
}

Ambassador::~Ambassador(){}