#include "Player.hpp"

class Captain: public Player{
    protected:
        Player* _stolen;
    public:
        bool _stole;
        Captain(Game* game, string name);
        void steal(Player* player);
        void unsteal();
};