#include <string>
#include <vector>

using namespace std;

namespace coup{
    class Game{
        protected:
            vector<string> _players;
            int _turn;
            string _winner;
        public:
            Game();
            vector<string> players();
            string turn();
            string winner();
            void add_player(string player);
            void advance_turn();
    };
}