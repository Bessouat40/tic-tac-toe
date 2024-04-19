#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "board.hpp"

#include <vector>
#include <string>

class Player {
    public:
        std::string name;
        char shape;

        Player() = default;
        Player(const std::string& player_name, const char& shape);
        void print_player();
        void print_player_as_winner();
        bool play(Board& board, std::tuple<int, int> coordinates);
        bool play_round(Board& board);
};

#endif