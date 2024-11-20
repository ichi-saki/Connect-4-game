#pragma once

#include <iostream>
#include <string>

class player{
    public:
    std::string name;
    std::string game_piece;
    int wins = 0;
    
    void print_won(){
        std::cout << "Player :" << name << " won!" << std::endl;
    }
    void print_wins(){
        std::cout << "Player :" << name << " has " << wins << " wins" << std::endl;
    }
};


/*
methods can be
---printing_board---
---check_win---
??
class board{
};


methods can be 
---rematch---
clears 
1 player names
2 tokens
3 board
4 wins
---new match---
clears board
lets winner go first 

class gamestate{
};
*/
