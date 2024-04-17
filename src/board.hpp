#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>

class Board {
    public:
        std::vector<std::vector<char>> board;

        Board();
        // bool place_pawn(const std::char& shape, const std::tuple<int, int>& coordinates);
        // bool check_place(const std::tuple<int, int>& coordinates);
        void print_board();
};

#endif