#include "Player.hpp"

class Assassin: public Player{
    protected:
        Player* _assassinated;
    public:
        bool _couped;
        Assassin(Game* game, string name);
        virtual void coup(Player* player);
        void uncoup();
};