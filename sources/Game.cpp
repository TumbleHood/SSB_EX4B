#include "Game.hpp"
#include "Player.hpp"
#include <iostream>

using namespace coup;

Game::Game(){
    _players = unordered_map<int, Player*>();
    _turn = 0;
    _ongoing = false;
}

vector<string> Game::players(){
    vector<string> name_list;
    for (int i = 0; i < MAX_PLAYERS; i++){
        if (_players.find(i) != _players.end()){
            name_list.push_back(_players.at(i)->get_name());
        }
    }
    return name_list;
}

string Game::turn(){
    return players().at((size_t)_turn);
}

Player* Game::real_turn(){
    return _players.at(_turn);
}

string Game::winner(){
    if (!_ongoing){
        throw invalid_argument("Game hasn't started yet!");
    }
    if (players().size() > 1){
        throw invalid_argument("Game is not over yet!");
    }
    return _players.at(0)->get_name();
}

void Game::add_player(Player* player){
    if (_ongoing){
        throw invalid_argument("Can't join mid-game!");
    }
    if (players().size() == MAX_PLAYERS){
        throw invalid_argument("Too many players!");
    }
    int player_turn = _players.size();
    if (_players.empty()){
        player_turn = 0;
    }
    _players.insert(pair<int, Player*>(player_turn, player));
}

void Game::add_player(Player* player, int number){
    unordered_map<int, Player*> temp = unordered_map<int, Player*>();
    for (pair<int, Player*> element: _players){
        if (element.first >= number){
            temp.insert(pair<int, Player*>(element.first+1, element.second));
        }
        else{
            temp.insert(element);
        }
    }
    temp.insert(pair<int, Player*>(number, player));
    _players = unordered_map<int, Player*>(temp);
    if (_turn >= number){
        advance_turn();
    }
}

void Game::remove_player(Player* player){
    int number = -1;
    for (pair<int, Player*> element: _players){
        if (element.second == player){
            number = element.first;
            break;
        }
    }
    if (number == -1){
        throw invalid_argument("Player is already couped!");
    }
    unordered_map<int, Player*> temp = unordered_map<int, Player*>();
    for (pair<int, Player*> element: _players){
        if (element.second != player){
            if (element.first > number){
                temp.insert(pair<int, Player*>(element.first-1, element.second));
            }
            else{
                temp.insert(element);
            }
        }
    }
    _players = unordered_map<int, Player*>(temp);
    if (_turn > number){
        _turn--;
    }
}

void Game::advance_turn(){
    _turn = (_turn + 1) % (int)_players.size();
}

int Game::get_player_number(Player* player){
    for (pair<int, Player*> element: _players){
        if (element.second == player){
            return element.first;
        }
    }
    return -1;
}