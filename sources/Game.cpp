#include "Game.hpp"

using namespace coup;

Game::Game(){
    _players = vector<string>();
    _turn = 0;
    _winner = "";
}

vector<string> Game::players(){
    return _players;
}

string Game::turn(){
    return _players.at(_turn);
}

string Game::winner(){
    return _winner;
}

void Game::add_player(string name){
    _players.push_back(name);
}

void Game::advance_turn(){
    if (_turn++ >= _players.size()){
        _turn = 0;
    }
}