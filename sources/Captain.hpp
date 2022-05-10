#include "Player.hpp"

class Captain: public Player{
    public:
        Captain(Game* game, string name);
        void steal(Player& player);
};