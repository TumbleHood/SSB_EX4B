#include "Assassin.hpp"

Assassin::Assassin(Game& game, string name) : Player(game, move(name)) {
    _role = "Assassin";
    _assassinated = nullptr;
    _assassinated_number = 0;
    _couped = false;
}

void Assassin::coup(Player& player){
    if (!_game->_ongoing && (_game->players().size() > MAX_PLAYERS || _game->players().size() < MIN_PLAYERS)){
        throw invalid_argument("Not enough players!");
    }
    _game->_ongoing = true;
    if (_game->real_turn() != this){
        throw invalid_argument("Not your turn");
    }
    reset_turn();
    if (coins() < COIN_FOR_ASSASSINATION){
        throw invalid_argument("Player does not have enough coins to coup!");
    }
    if (coins() < COINS_FOR_COUP){
        _assassinated = &player;
        _assassinated_number = _game->get_player_number(&player);
        _game->remove_player(&player);
        _coins -= COIN_FOR_ASSASSINATION;
        _couped = true;
        _game->advance_turn();
    }
    else{
        Player::coup(player);
    }
}

void Assassin::uncoup(){
    _game->add_player(_assassinated, _assassinated_number);
    _assassinated = nullptr;
    _assassinated_number = 0;
    _couped = false;
}

Assassin::~Assassin(){}