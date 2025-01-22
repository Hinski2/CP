#pragma once 
#include <bits/stdc++.h>
#include "globals.hpp"
#include "board.hpp"
#include "utils.hpp"

namespace game{
    int move[4];

    void print_board(int board_idx);
    void initialization();
    void get_input();
    void make_move();
    void print_move();
    int random_simulate(int board_idx);
    void shift(int dir, int board_idx, int player);
};

namespace game{
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
        globals::board[board_malloc::root].no_players[0] = 0;
        globals::board[board_malloc::root].no_players[1] = 0;

        std::string line;
        for(int i = 0; i < 8; i++){
            std::getline(std::cin, line);
            if(globals::debug) std::cerr << line << std::endl;
            for(int j = 0; j < 16; j += 2)
                if(line[j] == '0')
                    globals::board[board_malloc::root].matrix[i][j / 2] = 0, globals::board[board_malloc::root].no_players[0]++;
                else if(line[j] == '1')
                    globals::board[board_malloc::root].matrix[i][j / 2] = 1, globals::board[board_malloc::root].no_players[1]++;
                else if(line[j] == 'x')
                    globals::board[board_malloc::root].matrix[i][j / 2] = globals::hole;
                else 
                    globals::board[board_malloc::root].matrix[i][j / 2] = globals::empty;
        }

        globals::board[board_malloc::root].prev = -1;

        // set bounds
        // up
        for(int i = 0; i < 8; i++){
            int ok = true;
            for(int j = 0; j < 8 and ok; j++)
                if(globals::board[board_malloc::root].matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                globals::board[board_malloc::root].up_bound = i;
                break;
            }
            
        }

        // down
        for(int i = 7; i >= 0; i--){
            int ok = true;
            for(int j = 0; j < 8 and ok; j++)
                if(globals::board[board_malloc::root].matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                globals::board[board_malloc::root].down_bound = i;
                break;
            }
            
        }

        // right
        for(int j = 7; j >= 0; j--){
            int ok = true;
            for(int i = 0; i < 8 and ok; i++)
                if(globals::board[board_malloc::root].matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                globals::board[board_malloc::root].right_bound = j;
                break;
            }
        }

        // left
        for(int j = 0; j < 8; j++){
            int ok = true;
            for(int i = 0; i < 8 and ok; i++)
                if(globals::board[board_malloc::root].matrix[i][j] != globals::hole) ok = false;
            
            if(ok == false){
                globals::board[board_malloc::root].left_bound = j;
                break;
            }
        }

    }

    void make_move(){
        move[0] = move[1] = move[2] = move[3] = 0;
        
        for(int dir = 0; dir < 4; dir++){
            for(int i = 0; i < 1500; i++){
                globals::board[globals::max_malloc_size] = globals::board[board_malloc::root];
                shift(dir, globals::max_malloc_size, globals::me);
                // print_board(globals::max_malloc_size); //!!!!!!!!!!!!!!
                if(random_simulate(globals::max_malloc_size) == globals::me) move[dir]++;
            }
        }
    }

    void print_board(int board_idx){
        std::cerr << std::endl;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++)
            if(globals::board[board_idx].matrix[i][j] == 0)
                std::cerr << "0 ";
            else if(globals::board[board_idx].matrix[i][j] == 1)
                std::cerr << "1 ";
            else if(globals::board[board_idx].matrix[i][j] == 2)
                std::cerr << "- ";
            else
                std::cerr << "x ";

            std::cerr << std::endl;
        }
    }

    int random_simulate(int board_idx){
        int player = globals::foe;
        while(globals::board[board_idx].no_players[0] and globals::board[board_idx].no_players[1]){
            uint32_t dir = utils::random() % 4;
            shift(dir, board_idx, player);
            // print_board(board_idx); //!!!!!!!!!!!!!!!!!!
            player ^= 1;
        }

        return globals::board[board_idx].no_players[0] ? 0 : 1;
    }

    void print_move(){
        int arg_ans = 0, ans_val = -1;
        if(move[0] > ans_val){
            arg_ans = 0;
            ans_val = move[0];
        }
        if(move[1] > ans_val){
            arg_ans = 1;
            ans_val = move[1];
        }
        if(move[2] > ans_val){
            arg_ans = 2;
            ans_val = move[2];
        }
        if(move[3] > ans_val){
            arg_ans = 3;
            ans_val = move[3];
        }

        std::cout << globals::string_of_dir[arg_ans] << std::endl;
    }

    void shift(int dir, int board_idx, int player){
        switch(dir){
            // RIGHT
            case 2: {
                for(int i = 0; i < 8; i++){
                    int j = 0, end, jump;
                    while(j < 8){
                        if(globals::board[board_idx].matrix[i][j] == player){
                            end = j;
                            while(end + 1 < 8 and globals::board[board_idx].matrix[i][end + 1] < 2) end++;
                            jump = end + 1;

                            if(end + 1 == 8 or globals::board[board_idx].matrix[i][end + 1] == globals::hole){
                                if(globals::board[board_idx].matrix[i][end] < 2)
                                    globals::board[board_idx].no_players[globals::board[board_idx].matrix[i][end]]--;
                                globals::board[board_idx].matrix[i][end] = globals::empty, end--;
                            }
                            
                            while(j <= end){
                                globals::board[board_idx].matrix[i][end + 1] = globals::board[board_idx].matrix[i][end];
                                globals::board[board_idx].matrix[i][end] = globals::empty, end--;
                            }

                            j = jump;
                        }
                        else
                            j++;
                    }
                } 
                
                int ok = true, i = globals::board[board_idx].down_bound;
                for(int j = 0; j < 8; j++)
                    if(globals::board[board_idx].matrix[i][j] != globals::empty) ok = false;
                
                if(ok)
                    globals::board[board_idx].down_bound++;

                break;  
            }

            // UP
            case 0: {
                for(int j = 0; j < 8; j++){
                    int i = 0, end, jump;
                    while(i < 8){
                        if(globals::board[board_idx].matrix[i][j] == player){
                            end = i;
                            while(end + 1 < 8 and globals::board[board_idx].matrix[end + 1][j] < 2) end++;
                            jump = end + 1;

                            if(end + 1 == 8 or globals::board[board_idx].matrix[end + 1][j] == globals::hole){
                                if(globals::board[board_idx].matrix[end][j] < 2)
                                    globals::board[board_idx].no_players[globals::board[board_idx].matrix[end][j]]--;
                                globals::board[board_idx].matrix[end][j] = globals::empty, end--;
                            }

                            while(i <= end){
                                globals::board[board_idx].matrix[end + 1][j] = globals::board[board_idx].matrix[end][j];
                                globals::board[board_idx].matrix[end][j] = globals::empty, end--;
                            }

                            i = jump;
                        }
                        else 
                            i++;
                    }
                }

                int ok = true, j = globals::board[board_idx].left_bound;
                for(int i = 0; i < 8; i++)
                    if(globals::board[board_idx].matrix[i][j] != globals::empty) ok = false;

                if(ok)
                    globals::board[board_idx].left_bound++;

                break;
            }
            
            // DOWN
            case 3: {
                for(int j = 0; j < 8; j++){
                    int i = 7, end, jump;
                    while(i >= 0){
                        if(globals::board[board_idx].matrix[i][j] == player){
                            end = i;
                            while(end - 1 >= 0 and globals::board[board_idx].matrix[end - 1][j] < 2) end--;
                            jump = end - 1;

                            if(end - 1 < 0 or globals::board[board_idx].matrix[end - 1][j] == globals::hole){
                                if(globals::board[board_idx].matrix[end][j] < 2)
                                    globals::board[board_idx].no_players[globals::board[board_idx].matrix[end][j]]--;
                                globals::board[board_idx].matrix[end][j] = globals::empty, end++;
                            }

                            while(i >= end){
                                globals::board[board_idx].matrix[end - 1][j] = globals::board[board_idx].matrix[end][j];
                                globals::board[board_idx].matrix[end][j] = globals::empty, end++;
                            }

                            i = jump;
                        }
                        else 
                            i--;
                    }
                }

                int ok = true, j = globals::board[board_idx].right_bound;
                for(int i = 0; i < 8; i++)
                    if(globals::board[board_idx].matrix[i][j] != globals::empty) ok = false;

                if(ok)
                    globals::board[board_idx].right_bound--;
                break;
            }

            // LEFT
            case 1: {
                for(int i = 0; i < 8; i++){
                    int j = 7, end, jump;
                    while(j >= 0){
                        if(globals::board[board_idx].matrix[i][j] == player){
                            end = j; 
                            while(end - 1 >= 0 and globals::board[board_idx].matrix[i][end - 1] < 2) end--;
                            jump = end - 1;

                            if(end - 1 < 0 or globals::board[board_idx].matrix[i][end - 1] == globals::hole){
                                if(globals::board[board_idx].matrix[i][end] < 2)
                                    globals::board[board_idx].no_players[globals::board[board_idx].matrix[i][end]]--;
                                globals::board[board_idx].matrix[i][end] = globals::empty, end++;
                            }

                            while(j >= end){
                                globals::board[board_idx].matrix[i][end - 1] = globals::board[board_idx].matrix[i][end];
                                globals::board[board_idx].matrix[i][end] = globals::empty, end++;
                            }
                            
                            j = jump;
                        }
                        else 
                            j--;
                    }
                }

                int ok = true, i = globals::board[board_idx].up_bound;
                for(int j = 0; j < 8; j++)
                    if(globals::board[board_idx].matrix[i][j] != globals::empty) ok = false;
                
                if(ok)
                    globals::board[board_idx].up_bound--;
                break;
            }
        }
    }
}