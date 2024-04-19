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
    players = init_players();
    player_playing = 0;
}

/**
* Function for playing tic-tac-toe.
*
*@return winner Player.
*/
void Game::play() {
    int row;
    int col;
    Player _player = (player_playing == 0) ? std::get<0>(players) : std::get<1>(players);
    _player.print_player();
    std::cout << " please select a row : ";
    std::cin >> row;
    _player.print_player();
    std::cout << " please select a column : ";
    std::cin >> col;
    bool success = _player.play(board, std::tuple<int,int> {row - 1, col - 1});
    board.print_board();
    if (success == false) {
        play();
        return;
    }
    bool win = board.check_end_game(_player.shape);
    if (win == true) {
        winner = _player;
        return;
    }
    player_playing = (player_playing + 1) % 2;
    play();
    return;
}
