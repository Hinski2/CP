#pragma once 
#include <bits/stdc++.h>
#include "globals.hpp"

struct struct_board{
    int vis, win, player;
    struct_board *prev, *next[4];
    int matrix[8][8];
    int no_players[2];
    int left_bound, right_bound, up_bound, down_bound;
};

namespace board_malloc{
    int free_idx = globals::max_malloc_size - 1;
    struct_board *free[globals::max_malloc_size];
    struct_board *root;

    struct_board *new_board(){
        return free[free_idx--];
    }

    void free_board(struct_board *board){
        free[++free_idx] = board;
    }

    void initialize(){
        for(int i = globals::max_malloc_size - 1, j = 0; i >= 0; i--, j++)
            free[j] = &globals::board[i];

        root = new_board();        
    }
}