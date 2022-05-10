#include "Player.hpp"

class Ambassador: public Player{
    protected:
        Player* _from_player;
        Player* _to_player;
    public:
        bool _transfered;
        Ambassador(Game* game, string name);
        void block(Player* player);
        void transfer(Player* from_player, Player* to_player);
        void untransfer();
};