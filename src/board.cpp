#include "board.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

Board::Board() {
    board = std::vector<std::vector<char>> (3, std::vector<char>(3, '.'));
}

/**
* Display board.
*/
void Board::print_board() {
    for(int row = 0; row < board.size(); row++) {
        for(int col = 0; col < board[row].size(); col ++) {
        std::cout << board[row][col] << " ";
        };
        std::cout << std::endl;
    };
        std::cout << std::endl;
}

/**
* Place player pawn on board.
*
*@param shape Shape of pawn we want to place.
*@param coordinates Coordinates of pawn we want to place.
*@return false if we wan't place the pawn, true if we success placing it.
*/
bool Board::place_pawn(const char& shape, const std::tuple<int, int>& coordinates) {
    int row = std::get<0>(coordinates);
    int col = std::get<1>(coordinates);
    bool check = check_coordinates(row, col);
    if (check == false) {
        return false;
    }
    board[row][col] = shape;
    return true;
};

/**
* Check if coordinate exists inside our board.
*
*@param row Y value of our coordinate.
*@param col X value of our coordinate.
*@return true if coordinate exists inside our board, else return false.
*/
bool Board::check_coordinates(const int row, const int col) {
    bool row_check = row < board.size() && row >= 0;
    bool col_check = col < board[0].size() && col >= 0;
    bool exists = board[row][col] == '.';
    return row_check && col_check && exists;
}

/**
*Check if shape pawn fill a col. It ends the game.
*
*@param shape Shape we want to check.
*@return true if the game end, else false.
*/
bool Board::check_cols(const char& shape) {
    bool end = true;

    for (int col = 0; col < board[0].size(); col++) {
        end = true;
        for (int row = 0; row < board.size(); row++) {
            end = end && board[row][col] == shape;
        }
    }
    return end;
}

/**
*Check if shape pawn fill a row. It ends the game.
*
*@param shape Shape we want to check.
*@return true if the game end, else false.
*/
bool Board::check_rows(const char& shape) {
    bool end = true;

    for (int row = 0; row < board.size(); row++) {
        end = true;
        for (int col = 0; col < board[0].size(); col ++) {
            end = end && board[row][col] == shape;
        }
    }
    return end;
}

/**
*Check if shape pawn fill a diagonal. It ends the game.
*
*@param shape Shape we want to check.
*@return true if the game end, else false.
*/
bool Board::check_diags(const char& shape) {
    bool end = true;
    bool end2 = true;

    for (int idx = 0; idx < board.size(); idx++) {
        end = end && board[idx][idx] == shape;
        int idx2 = board.size() - idx - 1;
        end2 = end2 && board[idx2][idx] == shape;
    }
    return end || end2;
}

/**
*Check if player with shape pawns win the game.
*
*@param shape Shape we want to check.
*@return true if the game end, else false.
*/
bool Board::check_end_game(const char& shape){
    bool cols = check_cols(shape);
    bool rows = check_rows(shape);
    bool diags = check_diags(shape);

    return cols || rows || diags;
}