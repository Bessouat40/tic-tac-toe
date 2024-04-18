#include "game.hpp"
#include "board.hpp"
#include "player.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

/**
* Init players with users inputs.
*/
std::tuple<Player, Player> Game::init_players() {
    std::string player1_name;
    std::string player2_name;

    char player1_shape;
    char player2_shape;

    std::cout << "Enter Player 1 name : ";
    std::cin >> player1_name;

    std::cout << "Enter Player 1 shape : ";
    std::cin >> player1_shape;

    std::cout << "Enter Player 2 name : ";
    std::cin >> player2_name;

    std::cout << "Enter Player 2 shape : ";
    std::cin >> player2_shape;

    std::cout << std::endl;

    return {Player(player1_name, player1_shape), Player(player2_name, player2_shape)};
}

Game::Game() {
    board = Board();
    std::tuple<Player, Player> players = init_players();
    player1 = std::get<0>(players);
    player2 = std::get<1>(players);
}


