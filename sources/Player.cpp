#include "Player.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"

Player::Player(Game& game, string name){
    _game = &game;
    _name = move(name);
    _coins = 0;
    _played_foreign_aid = false;
    _game->add_player(this);
}

void Player::income(){
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
    _coins++;
    _game->advance_turn();
}

void Player::foreign_aid(){
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
    _coins += COIN_FOR_FOREIGN_AID;
    _played_foreign_aid = true;
    _game->advance_turn();
}

int Player::coins() const{
    return _coins;
}

string Player::role(){
    return _role;
}

string Player::get_name(){
    return _name;
}

void Player::coup(Player& player){ //except for assassin
    if (!_game->_ongoing && (_game->players().size() > MAX_PLAYERS || _game->players().size() < MIN_PLAYERS)){
        throw invalid_argument("Not enough players!");
    }
    _game->_ongoing = true;
    if (_game->real_turn() != this){
        throw invalid_argument("Not your turn");
    }
    reset_turn();
    if (coins() < COINS_FOR_COUP){
        throw invalid_argument("Player does not have enough coins to coup!");
    }
    _game->remove_player(&player);
    _coins -= COINS_FOR_COUP;
    _game->advance_turn();
}

void Player::reset_turn(){
    if (role() == "Captain"){
        dynamic_cast<Captain*>(this)->_stole = false;
    }
    else if (role() == "Assassin"){
        dynamic_cast<Assassin*>(this)->_couped = false;
    }
    _played_foreign_aid = false;
}

Player::~Player(){}