#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include <string>
using namespace std;

namespace ariel {
    
    class Player {
        private:
            string name;

        public:
            Player(string playerName);

            int stacksize();

            int cardesTaken();
            
    };
}
#endif
