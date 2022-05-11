#include "Player.hpp"

class Captain: public Player{
    protected:
        Player* _stolen;
        int _coins_stolen;
    public:
        bool _stole;
        Captain(Game& game, string name);
        static void block(Player& player);
        void steal(Player& player);
        void unsteal();
        ~Captain();
};