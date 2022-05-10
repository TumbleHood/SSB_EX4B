#include "Game.hpp"

using namespace coup;

class Player{
    protected:
        Game* _game;
        string _name;
        string _role;
    public:
        int _coins;
        void income();
        void foreign_aid();
        void coup(Player& player);
        string role();
        int coins();
        virtual void block() = 0;
};