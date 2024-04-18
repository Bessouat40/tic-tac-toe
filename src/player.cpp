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
    std::cout << "Player " << name << " / shape : " << shape << std::endl << std::endl ;
}

/**
*Player place his pawn on the board.
*
*@param board Board where both players are playing.
*@param coordinates Coordinates where the player want to place its pawn.
*@return false if we can't place the pawn at this place, else return true.
*/
void Player::play(const Board& board, std::tuple<int, int> coordinates) {
    bool placed = board.place_pawn(shape, coordinates);
    if (placed == false) {
        std::cout << "You can't place your pawn here, please retry..." << std::endl;
        return false;
    }
    return true;
}