#include "src/board.hpp"
#include "src/player.hpp"
#include "src/game.hpp"

#include <iostream>
#include <string>
#include <tuple>

int main() {
    Game game = Game();
    game.play();
    game.winner.print_player_as_winner();
}