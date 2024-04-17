#include "player.hpp"

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