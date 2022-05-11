#include "Captain.hpp"

Captain::Captain(Game& game, string name) : Player(game, move(name)){
    _role = "Captain";
    _stolen = nullptr;
    _stole = false;
    _coins_stolen = 0;
}

void Captain::steal(Player& player){
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
    if (player.coins() == 0){
        _coins_stolen = 0;
    }
    else if (player.coins() == 1){
        player._coins--;
        _coins++;
        _coins_stolen = 1;
    }
    else{
        player._coins -= COIN_FOR_STEAL;
        _coins += COIN_FOR_STEAL;
        _coins_stolen = COIN_FOR_STEAL;
    }
    _stolen = &player;
    _stole = true;
    _game->advance_turn();
}

void Captain::unsteal(){
    _stolen->_coins += _coins_stolen;
    _coins -= _coins_stolen;
    _stole = false;
}

void Captain::block(Player& player){
    if (player.role() != "Captain"){
        throw invalid_argument("Captain can only block a Captian!");
    }
    if (!dynamic_cast<Captain*>(&player)->_stole){
        throw invalid_argument("Player did not steal!");
    }
    dynamic_cast<Captain*>(&player)->unsteal();
}

Captain::~Captain(){}