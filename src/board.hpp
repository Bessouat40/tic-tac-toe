#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
// #include "player.hpp"

class Board {
    public:
        std::vector<std::vector<char>> board;
        // player1
        // player2

        Board();
        bool place_pawn(const char& shape, const std::tuple<int, int>& coordinates);
        bool check_coordinates(const int row, const int col);
        bool check_end_game(const char& shape);
        bool check_cols(const char& shape);
        bool check_rows(const char& shape);
        bool check_diags(const char& shape);
        void print_board();
};

#endif