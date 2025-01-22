#pragma once 
#include<bits/stdc++.h>
#include "h/utils.hpp"
#include "h/game.hpp"
#include "h/board.hpp"
#include "h/globals.hpp"

int main(){
    board_malloc::initialize();
    game::initialization();

    while(1){
        game::get_input();
        game::make_move();
        game::print_move();
    }
}