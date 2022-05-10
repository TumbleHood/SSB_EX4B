#include "Game.hpp"
#include "Player.hpp"

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
    return players().at((size_t)_turn);
}

string Game::winner(){
    return _winner;
}

void Game::add_player(Player* player){
    _players.insert(pair<int, Player*>(_players.size(), player));
}

void Game::add_player(Player* player, int number){
    map<int, Player*> temp = map<int, Player*>();
    int i = 0;
    for (pair<int, Player*> element: _players){
        if (element.first == number){
            temp.insert(pair<int, Player*>(number, player));
            i++;
        }
        temp.insert(pair<int, Player*>(element.first + i, element.second));
    }
    _players = map<int, Player*>(temp);
}

void Game::advance_turn(){
    if (_turn++ >= _players.size()){
        _turn = 0;
    }
}

void Game::remove_player(Player* player){
    map<int, Player*> temp = map<int, Player*>(_players);
    int i = 0;
    for (pair<int, Player*> element: _players){
        if (element.second == player){
            i--;
        }
        else{
            temp.insert(pair<int, Player*>(element.first - i, element.second));
        }
    }
    _players = map<int, Player*>(temp);
}

int Game::get_player_number(Player* player){
    for (pair<int, Player*> element: _players){
        if (element.second == player){
            return element.first;
        }
    }
    return -1;
}