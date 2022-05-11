#include "Player.hpp"

class Ambassador: public Player{
    protected:
    public:
        Ambassador(Game& game, string name);
        static void block(Player& player);
        void transfer(Player& from_player, Player& to_player);
        ~Ambassador();
};