#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

class Player {
    public:
        std::string name;
        char shape;

        Player() = default;
        Player(const std::string& player_name, const char& shape);
        void print_player();
};

#endif