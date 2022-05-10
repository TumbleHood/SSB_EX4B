#include "Player.hpp"

class Ambassador: public Player{
    public:
        Ambassador(Game* game, string name);
        void transfer(Player& from_player, Player& to_player);
};