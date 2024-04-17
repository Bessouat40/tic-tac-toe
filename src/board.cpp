#include "board.hpp"

#include <iostream>
#include <vector>
#include <string>

Board::Board() {
    board = std::vector<std::vector<char>> (3, std::vector<char>(3, '.'));
}

void Board::print_board() {
    for(int row = 0; row < board.size(); row++) {
        for(int col = 0; col < board[row].size(); col ++) {
        std::cout << board[row][col] << " ";
        };
        std::cout << std::endl;
    };
}