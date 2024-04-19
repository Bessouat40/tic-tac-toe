#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include <tuple>

#include "board.hpp"
#include "player.hpp"

class Game {
    public:
        Board board;
        std::tuple<Player, Player> players;
        Player winner;
        int player_playing;
        std::tuple<Player, Player> init_players();
        void play();
        Game();
};

#endif