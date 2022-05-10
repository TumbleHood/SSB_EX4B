#include "Game.hpp"

using namespace coup;

Game::Game(){
    _players = map<int, Player*>();
    _turn = 0;
    _winner = "";
}

vector<string> Game::players(){
    vector<string> name_list;
    for (pair<int, Player*> element : _players){
        name_list.push_back(element.second->get_name());
    }
    return name_list;
}

string Game::turn(){
    return players().at(_turn);
}

string Game::winner(){
    return _winner;
}

void Game::add_player(Player* player){
    _players.insert(pair<int, Player*>(_players.size(), player));
}

void Game::advance_turn(){
    if (_turn++ >= _players.size()){
        _turn = 0;
    }
}