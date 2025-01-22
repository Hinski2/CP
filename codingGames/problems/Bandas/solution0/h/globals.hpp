#pragma once 
#include <bits/stdc++.h>
#include "board.hpp"

namespace globals{    
    // enum
    enum enum_DIR {
        DOWN,
        LEFT,
        RIGHT,
        UP
    };

    // constexpr
    constexpr bool debug = true;
    constexpr std::pair<int, int> dir[] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    constexpr int max_malloc_size = 10000;
    const std::string string_of_dir[] = {"DOWN", "LEFT", "RIGHT", "UP"};

    //var
    int n, m;
    int me, foe, empty = 2, hole = 3;
    struct_board board[max_malloc_size + 1];
};