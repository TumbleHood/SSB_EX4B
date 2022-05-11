#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <exception>

#define MAX_PLAYERS 6
#define MIN_PLAYERS 2
#define COINS_FOR_COUP 7
#define COINS_FOR_MUST_COUP 10
#define COIN_FOR_ASSASSINATION 3
#define COIN_FOR_STEAL 2
#define COIN_FOR_TAX 3
#define COIN_FOR_FOREIGN_AID 2

using namespace std;

namespace coup{
    class Player;
    class Game{
        unordered_map<int, Player*> _players;
        int _turn;
        public:
            bool _ongoing;
            Game();
            vector<string> players();
            string turn();
            Player* real_turn();
            string winner();
            void add_player(Player* player);
            void add_player(Player* player, int number);
            void advance_turn();
            void remove_player(Player* player);
            int get_player_number(Player* player);
    };
}