#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include "board.hpp"
#include "player.hpp"

class Game {
    public:
        Board board;
        Player player1;
        Player player2;
        Game();

        std::tuple<Player, Player> init_players();
};

#endif