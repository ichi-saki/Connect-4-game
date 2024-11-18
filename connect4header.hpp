#pragma once

#include <iostream>
#include <string>

class player{
    public:
    std::string name;
    std::string token;
    int wins = 0;
    void print_won(){
        std::cout << "Player :" << name << " won!" << std::endl;
    }
    void print_wins(){
        std::cout << "Player :" << name << " has " << wins << " wins" << std::endl;
    }
};
