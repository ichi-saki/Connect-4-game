#pragma once

#include <iostream>
#include <string>

class player{
    public:
    std::string name;
    std::string token;
    int wins = 0;

    void print_wins(){//method to print number of player wins
        std::cout << "Player :" << name << " has " << wins << " wins" << std::endl;
    }
};
