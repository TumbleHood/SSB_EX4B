#include "Player.hpp"

class Duke: public Player{
    public:
        Duke(Game& game, string name);
        void tax();
        void block(Player& player);
        ~Duke();

};