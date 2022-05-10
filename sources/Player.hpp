#pragma once

#include "Game.hpp"

using namespace coup;

class Player{
    protected:
        Game* _game;
        string _name;
        string _role;
    public:
        int _coins;
        bool _played_foreign_aid;
        void income();
        void foreign_aid();
        void coup(Player* player);
        string role();
        int coins();
        string get_name();
        void reset_turn();
};