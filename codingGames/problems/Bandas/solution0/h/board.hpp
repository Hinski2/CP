#pragma once 
#include <bits/stdc++.h>
#include "globals.hpp"

struct struct_board{
    int prev, next[4];
    int matrix[8][8];
    int no_players[2];
    int left_bound, right_bound, up_bound, down_bound;
};

namespace board_malloc{
    int free_idx = globals::max_malloc_size - 1;
    int free[globals::max_malloc_size];
    int root;

    int new_board(){
        return free[free_idx--];
    }

    void free_board(int idx){
        free[++free_idx] = idx;
    }

    void initialize(){
        for(int i = globals::max_malloc_size - 1, j = 0; i >= 0; i--, j++)
            free[j] = i;

        root = new_board();        
    }
}