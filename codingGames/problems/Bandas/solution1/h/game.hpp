#pragma once 
#include <bits/stdc++.h>
#include "globals.hpp"
#include "board.hpp"
#include "utils.hpp"

namespace game{
    void print_board(struct_board *board);
    void initialization();
    void get_input();
    void make_moves();
    void print_move();
    void shift(int dir, struct_board *board_idx, int player);

    // for tree
    double uct(struct_board *board);
    struct_board *select(struct_board *board);
    void expand(struct_board *board);
    int random_simulate(struct_board *board);
    void backpropagation(struct_board *board, int wins);
    void free_board(struct_board *board);
};

namespace game{
    void backpropagation(struct_board *board, int wins){
        while(board){
            board -> win += wins;
            board -> vis += 4;
            board = board -> prev;
        }
    }

    void expand(struct_board *board){
        int wins = 0;
        for(const int &i: {0, 1, 2, 3}){
            board -> next[i] = board_malloc::new_board();
            struct_board &next = *(board -> next[i]);

            next.prev = board;
            next.player = board -> player ^ 1;
            shift(i, board -> next[i], board -> player);

            int score = random_simulate(board -> next[i]);
            next.win = score;
            next.vis = 1;
            wins += score;
        }

        backpropagation(board, wins);
    }

    struct_board *select(struct_board *board){
        if(board -> vis <= 1) return board; // we are in a leaf 

        int arg_ans = 0;
        double arg_val = -1;

        for(const int &i: {0, 1, 2, 3}){
            if(board -> next[i] -> vis <= 1){ // that's a leaf
                arg_ans = i;
                break;
            }

            double uct_val = uct(board -> next[i]);
            if(uct_val > arg_val){
                arg_val = uct_val;
                arg_ans = i;
            }
        }

        return select(board -> next[arg_ans]);
    }

    double uct(struct_board *board){
        double ans = (double) board -> win / board -> vis;
        ans += (double) 1.41421356237 * std::sqrt(std::log( board -> prev ? board -> prev -> vis : board -> vis) / board -> vis);
        return ans;
    }

    void initialization(){
        std::string s;
        std::cin >> s;
        std::cin >> globals::n;
        std::cin>> globals::m;

        globals::me = s == "1" ? 1 : 0;
        globals::foe = globals::me^1;

        if(globals::debug){
            std::cerr << globals::me << std::endl;
            std::cerr << globals::n << std::endl;
            std::cerr << globals::m << std::endl;
        }

        std::cin.ignore();
    }

    void get_input(){
        board_malloc::root -> no_players[0] = 0;
        board_malloc::root -> no_players[1] = 0;

        std::string line;
        for(int i = 0; i < 8; i++){
            std::getline(std::cin, line);
            if(globals::debug) std::cerr << line << std::endl;
            for(int j = 0; j < 16; j += 2)
                if(line[j] == '0')
                    board_malloc::root -> matrix[i][j / 2] = 0, board_malloc::root -> no_players[0]++;
                else if(line[j] == '1')
                    board_malloc::root -> matrix[i][j / 2] = 1, board_malloc:: root -> no_players[1]++;
                else if(line[j] == 'x')
                    board_malloc::root -> matrix[i][j / 2] = globals::hole;
                else 
                    board_malloc::root -> matrix[i][j / 2] = globals::empty;
        }

        board_malloc::root -> prev = nullptr;
        board_malloc::root -> win = board_malloc::root -> vis = 0;
        board_malloc::root -> player == globals::me;

        // set bounds
        // up
        for(int i = 0; i < 8; i++){
            int ok = true;
            for(int j = 0; j < 8 and ok; j++)
                if(board_malloc::root -> matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                board_malloc::root -> up_bound = i;
                break;
            }
            
        }

        // down
        for(int i = 7; i >= 0; i--){
            int ok = true;
            for(int j = 0; j < 8 and ok; j++)
                if(board_malloc::root -> matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                board_malloc::root -> down_bound = i;
                break;
            }
            
        }

        // right
        for(int j = 7; j >= 0; j--){
            int ok = true;
            for(int i = 0; i < 8 and ok; i++)
                if(board_malloc::root -> matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                board_malloc::root -> right_bound = j;
                break;
            }
        }

        // left
        for(int j = 0; j < 8; j++){
            int ok = true;
            for(int i = 0; i < 8 and ok; i++)
                if(board_malloc::root ->  matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                board_malloc::root -> left_bound = j;
                break;
            }
        }
    }

    void make_moves(){
        for(int i = 0; i < 5000; i++){
            struct_board *selected = select(board_malloc::root);
            expand(selected);
        }
    }

    void print_board(struct_board *board){
        std::cerr << std::endl;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++)
            if(board -> matrix[i][j] == 0)
                std::cerr << "0 ";
            else if(board -> matrix[i][j] == 1)
                std::cerr << "1 ";
            else if(board -> matrix[i][j] == 2)
                std::cerr << "- ";
            else
                std::cerr << "x ";

            std::cerr << std::endl;
        }

        // now we can free board
        for(const int &i: {0, 1, 2, 3}){
            free_board(board_malloc::root -> next[i]);
        }
    }

    void free_board(struct_board *board){
        if(board -> vis > 1){
            for(const int &i: {0, 1, 2, 3}){
                free_board(board -> next[i]);
            }
        }

        board_malloc::free_board(board);
    }

    int random_simulate(struct_board *board){
        struct_board copy = *board;

        while(copy.no_players[0] and copy.no_players[1]){
            uint32_t dir = utils::random() % 4;
            shift(dir, &copy, copy.player);
            copy.player ^= 1;
        }

        return copy.no_players[0] ? 0 : 1;
    }

    void print_move(){
        int arg_ans = 0, ans_val = -1;

        for(auto &i: {0, 1, 2, 3})
            if(board_malloc::root -> next[i] -> win > ans_val){
                arg_ans = i;
                ans_val = board_malloc::root -> next[i] -> win;
            }

        std::cout << globals::string_of_dir[arg_ans] << std::endl;
    }

    void shift(int dir, struct_board *board, int player){
        switch(dir){
            // RIGHT
            case 2: {
                for(int i = 0; i < 8; i++){
                    int j = 0, end, jump;
                    while(j < 8){
                        if(board -> matrix[i][j] == player){
                            end = j;
                            while(end + 1 < 8 and board -> matrix[i][end + 1] < 2) end++;
                            jump = end + 1;

                            if(end + 1 == 8 or board -> matrix[i][end + 1] == globals::hole){
                                if(board -> matrix[i][end] < 2)
                                    board -> no_players[board -> matrix[i][end]]--;
                                board -> matrix[i][end] = globals::empty, end--;
                            }
                            
                            while(j <= end){
                                board -> matrix[i][end + 1] = board -> matrix[i][end];
                                board -> matrix[i][end] = globals::empty, end--;
                            }

                            j = jump;
                        }
                        else
                            j++;
                    }
                } 
                
                int ok = true, i = board -> down_bound;
                for(int j = 0; j < 8; j++)
                    if(board -> matrix[i][j] != globals::empty) ok = false;
                
                if(ok)
                    board -> down_bound++;

                break;  
            }

            // UP
            case 0: {
                for(int j = 0; j < 8; j++){
                    int i = 0, end, jump;
                    while(i < 8){
                        if(board -> matrix[i][j] == player){
                            end = i;
                            while(end + 1 < 8 and board -> matrix[end + 1][j] < 2) end++;
                            jump = end + 1;

                            if(end + 1 == 8 or board -> matrix[end + 1][j] == globals::hole){
                                if(board -> matrix[end][j] < 2)
                                    board -> no_players[board -> matrix[end][j]]--;
                                board -> matrix[end][j] = globals::empty, end--;
                            }

                            while(i <= end){
                                board -> matrix[end + 1][j] = board -> matrix[end][j];
                                board -> matrix[end][j] = globals::empty, end--;
                            }

                            i = jump;
                        }
                        else 
                            i++;
                    }
                }

                int ok = true, j = board -> left_bound;
                for(int i = 0; i < 8; i++)
                    if(board -> matrix[i][j] != globals::empty) ok = false;

                if(ok)
                    board -> left_bound++;

                break;
            }
            
            // DOWN
            case 3: {
                for(int j = 0; j < 8; j++){
                    int i = 7, end, jump;
                    while(i >= 0){
                        if(board -> matrix[i][j] == player){
                            end = i;
                            while(end - 1 >= 0 and board -> matrix[end - 1][j] < 2) end--;
                            jump = end - 1;

                            if(end - 1 < 0 or board -> matrix[end - 1][j] == globals::hole){
                                if(board -> matrix[end][j] < 2)
                                    board -> no_players[board -> matrix[end][j]]--;
                                board -> matrix[end][j] = globals::empty, end++;
                            }

                            while(i >= end){
                                board -> matrix[end - 1][j] = board -> matrix[end][j];
                                board -> matrix[end][j] = globals::empty, end++;
                            }

                            i = jump;
                        }
                        else 
                            i--;
                    }
                }

                int ok = true, j = board -> right_bound;
                for(int i = 0; i < 8; i++)
                    if(board -> matrix[i][j] != globals::empty) ok = false;

                if(ok)
                    board -> right_bound--;
                break;
            }

            // LEFT
            case 1: {
                for(int i = 0; i < 8; i++){
                    int j = 7, end, jump;
                    while(j >= 0){
                        if(board -> matrix[i][j] == player){
                            end = j; 
                            while(end - 1 >= 0 and board -> matrix[i][end - 1] < 2) end--;
                            jump = end - 1;

                            if(end - 1 < 0 or board -> matrix[i][end - 1] == globals::hole){
                                if(board -> matrix[i][end] < 2)
                                    board -> no_players[board -> matrix[i][end]]--;
                                board -> matrix[i][end] = globals::empty, end++;
                            }

                            while(j >= end){
                                board -> matrix[i][end - 1] = board -> matrix[i][end];
                                board -> matrix[i][end] = globals::empty, end++;
                            }
                            
                            j = jump;
                        }
                        else 
                            j--;
                    }
                }

                int ok = true, i = board -> up_bound;
                for(int j = 0; j < 8; j++)
                    if(board -> matrix[i][j] != globals::empty) ok = false;
                
                if(ok)
                    board -> up_bound--;
                break;
            }
        }
    }
}