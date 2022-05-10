#pragma once

#include "Player.hpp"
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace coup{
    class Game{
        protected:
            map<int, Player*> _players;
            int _turn;
            string _winner;
        public:
            Game();
            vector<string> players();
            string turn();
            string winner();
            void add_player(Player* player);
            void advance_turn();
    };
}