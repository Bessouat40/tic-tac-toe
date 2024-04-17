#include "src/board.hpp"
#include <iostream>
#include <string>
#include <tuple>

int main() {
    Board board = Board();
    board.print_board();

    char shape = 'o';
    char shape2 = 'x';
    std::tuple<int, int> coordinates = {2, 0};
    std::tuple<int, int> coordinates2 = {1, 1};
    std::tuple<int, int> coordinates3 = {0, 2};

    board.place_pawn(shape, coordinates);
    board.print_board();

    board.place_pawn(shape, coordinates2);
    board.print_board();

    board.place_pawn(shape, coordinates3);
    board.print_board();

    std::cout << board.check_end_game(shape) <<std::endl;
}