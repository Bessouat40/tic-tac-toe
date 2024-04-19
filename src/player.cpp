#include "player.hpp"
#include "board.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

Player::Player(const std::string& player_name, const char& shape) {
    name = player_name;
    this->shape = shape;
}

/**
* Display player informations.
*/
void Player::print_player() {
    std::cout << "Player " << name;
}

/**
* Display player as a winner.
*/
void Player::print_player_as_winner() {
    std::cout << "Player " << name << " is the winner !!! 👏" << std::endl;
}

/**
*Player place his pawn on the board.
*
*@param board Board where both players are playing.
*@param coordinates Coordinates where the player want to place its pawn.
*@return false if we can't place the pawn at this place, else return true.
*/
bool Player::play(Board& board, std::tuple<int, int> coordinates) {
    bool placed = board.place_pawn(shape, coordinates);
    if (placed == false) {
        std::cout << "You can't place your pawn here, please retry..." << std::endl;
        return false;
    }
    return true;
}

/**
* Get pawn placement and try to play.
*
*@param board Board we're playing on.
*@return true if pawn placement success, else return false.
*/
bool Player::play_round(Board& board) {
    int row;
    int col;
    print_player();
    std::cout << " please select a row : ";
    std::cin >> row;
    print_player();
    std::cout << " please select a column : ";
    std::cin >> col;
    bool success = play(board, std::tuple<int,int> {row - 1, col - 1});
    return success;
}