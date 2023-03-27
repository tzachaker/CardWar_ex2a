#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
using namespace std;


TEST_CASE("The beginning of the game") {
    Player p1("Alice");
    Player p2("Bob");

    CHECK_THROWS(Game{p1, p1}); //p1 can't play with himself
    CHECK(p1.stacksize()==0); //starting position in the beginning of the game
    CHECK(p2.stacksize()==0); //starting position in the beginning of the game
    CHECK(p1.cardesTaken()==0); //starting position in the beginning of the game
    CHECK(p2.cardesTaken()==0); //starting position in the beginning of the game

    Game game(p1, p2);

    CHECK(p1.stacksize()==26); //starting position in the beginning of the game
    CHECK(p2.stacksize()==26); //starting position in the beginning of the game
    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.cardesTaken()==0); //starting position in the beginning of the game
    CHECK(p2.cardesTaken()==0); //starting position in the beginning of the game
    CHECK(p1.cardesTaken() == p2.cardesTaken());
    CHECK_THROWS(game.printWiner()); //There is no winner at first
}


TEST_CASE("The cards left") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll(); 
    CHECK(p1.cardesTaken()==0); //all the cards left
    CHECK(p2.cardesTaken()==0); //all the cards left
    CHECK(p1.cardesTaken()+p2.cardesTaken()==52); //the cards complete to 52
}


TEST_CASE("One turn") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();

    CHECK(p1.stacksize() <= 25); 
    CHECK(p2.stacksize() <= 25); 
    CHECK(p1.cardesTaken() >= 0); 
    CHECK(p2.cardesTaken() >= 0); 
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner()); 
    CHECK_NOTHROW(game.printLog()); 
    CHECK_NOTHROW(game.printStats()); 
}


TEST_CASE("Five turns") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    for (int i=0; i<5; i++) 
        CHECK_NOTHROW(game.playTurn());
        
    CHECK(p1.stacksize() <= 21); 
    CHECK(p2.stacksize() <= 21); 
    CHECK(p1.cardesTaken() >= 0); 
    CHECK(p2.cardesTaken() >= 0); 
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner()); 
    CHECK_NOTHROW(game.printLog()); 
    CHECK_NOTHROW(game.printStats()); 
}
