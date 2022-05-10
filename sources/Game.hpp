#pragma once

#include <string>
#include <vector>
#include <map>
#include <exception>

using namespace std;

namespace coup{
    class Player;
    class Game{
        map<int, Player*> _players;
        int _turn;
        string _winner;
        public:
            Game();
            vector<string> players();
            string turn();
            string winner();
            void add_player(Player* player);
            void add_player(Player* player, int number);
            void advance_turn();
            void remove_player(Player* player);
            int get_player_number(Player* player);
    };
}