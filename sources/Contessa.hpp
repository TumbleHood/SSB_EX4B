#include "Player.hpp"

class Contessa: public Player{
    public:
        Contessa(Game& game, string name);
        static void block(Player& player);
        ~Contessa();
};