#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include <string>
using namespace std;

namespace ariel {
  
  class Game {
    private:
  
    public:
      Game(Player player1, Player player2);

      void playTurn();

      void printLastTurn();

      void playAll();

      void printWiner();

      void printLog();

      void printStats();
      
  };
}
#endif