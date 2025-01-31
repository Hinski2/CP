#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,tracer")
#pragma GCC optimize("unroll-loops,vpt,split-loops,unswitch-loops") 
#pragma GCC target("arch=haswell,tune=haswell")

struct struct_board{
    int vis, win, player;
    struct_board *prev, *next[4];
    int matrix[8][8];
    int no_players[2];
    int left_bound, right_bound, up_bound, down_bound;
};

namespace globals{    
    // enum
    enum enum_DIR {
        DOWN,
        LEFT,
        RIGHT,
        UP
    };

    // constexpr
    constexpr bool debug = false;
    constexpr int no_simulates = 5;
    constexpr std::pair<int, int> dir[] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    constexpr int max_malloc_size = 125000;
    const std::string string_of_dir[] = {"DOWN", "LEFT", "RIGHT", "UP"};

    //var
    int n, m;
    int me, foe, empty = 2, hole = 3;
    struct_board board[max_malloc_size + 1];
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
        root -> up_bound = 0;
        root -> down_bound = 7;
        root -> left_bound = 0;
        root -> right_bound = 7;        
        root -> win = root -> vis = 0;
        root -> no_players[0] = root -> no_players[1] = 0;
        root -> prev = nullptr;
        root -> next[0] = root -> next[1] = root -> next[2] = root -> next[3] = nullptr;
    }
}

namespace utils{
    //! utils section
    //* time utils section
    uint64_t T0;

    extern "C" {
        int gettimeofday(struct timeval* tv, void* tz);
    }

    uint64_t get_time() { //return time in microsecunds
        struct timeval t;
        utils::gettimeofday(&t, nullptr);
        return static_cast<uint64_t>(t.tv_sec) * 1000000UL + static_cast<uint64_t>(t.tv_usec);
    }

    inline int elapsed_time(){
            return get_time() - T0;
    }

    //* random() utils section
    uint64_t seed=1;
    uint32_t randomRaw(){seed=(0x5DEECE66DUL * seed + 0xBUL) & ((1UL << 48) - 1); return(seed >> 16);}
    uint32_t random_with_boud(const uint bound){return (randomRaw() * uint64_t(bound)) >> 32;}
    uint32_t random(){return (randomRaw() * uint64_t(1e9 + 7) >> 32);}

    bool all_on_red(double prob){
        return (double) random() / UINT32_MAX < prob;
    }
}


namespace game{
    void debug_board(struct_board *board);
    void initialization();
    void get_input();
    void make_moves();
    void print_move();
    void shift(int dir, struct_board *board_idx, int player);

    // for tree
    double uct(struct_board *board);
    struct_board *select(struct_board *board);
    void expand(struct_board *board);
    std::pair<int, int> random_simulate(struct_board *board);
    void backpropagation(struct_board *board, int wins);
    void free_board(struct_board *board);
};

int main(){
    int idx = 0;
    board_malloc::initialize();
    game::initialization();

    game::make_moves();
    game::print_move();

    idx = 1;
    while(1){
        game::get_input();

        game::make_moves();
        game::print_move();
        idx++;
    }
}

namespace game{
    void backpropagation(struct_board *board, int wins){
        while(board){
            board -> win += wins;
            board -> vis += 4 * globals::no_simulates;
            board = board -> prev;
        }
    }

    void expand(struct_board *board){
        // check if its derminating state
        int wins = 0;
        if(board -> no_players[0] == 0 or board -> no_players[1] == 0){
            if(board -> no_players[globals::me]) wins = 4;
            else wins = 0;
        }
        else {
            for(const int &i: {0, 1, 2, 3}){
                board -> next[i] = board_malloc::new_board();
                struct_board *next = board -> next[i];
                *next = *board;

                next -> prev = board;
                shift(i, next, board -> player);
                next -> player = board -> player ^ 1;
                next -> next[0] = next -> next[1] = next -> next[2] = next -> next[3] = nullptr;

                int score = 0;
                for(int s = 0; s < globals::no_simulates; s++){
                    std::pair<int, int> out = random_simulate(next);
                    score += out.first == globals::me ? out.second : -out.first;
                }

                next -> win = score;
                next -> vis = globals::no_simulates;
                wins += score;
            }
        }

        backpropagation(board, wins);
    }

    struct_board *select(struct_board *board){
        if(board -> next[0] == nullptr) return board; // we are in a leaf 

        int arg_ans = 0;
        double arg_val = -1;

        for(const int &i: {0, 1, 2, 3}){
            if(board -> next[i] -> next[0] == nullptr){ // that's a leaf
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
        int wins = board -> player != board_malloc::root -> player ? board -> win : board -> vis - board -> win;

        double ans = (double) wins / board -> vis;
        ans += (double) 1.41 * std::sqrt(std::log( board -> prev ? board -> prev -> vis : board -> vis) / board -> vis);
        return ans;
    }

    void initialization(){
        std::string s;
        std::cin >> s;
        std::cin >> globals::n;
        std::cin>> globals::m;

        globals::me = s == "1" ? 1 : 0;
        globals::foe = globals::me^1;
        board_malloc::root -> player = globals::me;

        if(globals::debug){
            std::cerr << globals::me << std::endl;
            std::cerr << globals::n << std::endl;
            std::cerr << globals::m << std::endl;
        }

        std::cin.ignore();

        // here basicly do the same what in get_input but without tree reuse 
        std::string line;

        for(int i = 0; i < 8; i++){
            std::getline(std::cin, line);
            if(globals::debug) std::cerr << line << std::endl;
            for(int j = 0; j < 16; j += 2)
                if(line[j] == '0')
                    board_malloc::root -> matrix[i][j / 2] = 0, board_malloc::root -> no_players[0]++;
                else if(line[j] == '1')
                    board_malloc::root -> matrix[i][j / 2] = 1, board_malloc::root -> no_players[1]++;
                else if(line[j] == 'x')
                    board_malloc::root -> matrix[i][j / 2] = globals::hole;
                else 
                    board_malloc::root -> matrix[i][j / 2] = globals::empty;
        }

        utils::T0 = utils::get_time();
    }

    void get_input(){
        // make board and clean in
        struct_board board;
        std::string line;

        for(int i = 0; i < 8; i++){
            std::getline(std::cin, line);
            if(globals::debug) std::cerr << line << std::endl;
            for(int j = 0; j < 16; j += 2)
                if(line[j] == '0')
                    board.matrix[i][j / 2] = 0, board.no_players[0]++;
                else if(line[j] == '1')
                    board.matrix[i][j / 2] = 1, board.no_players[1]++;
                else if(line[j] == 'x')
                    board.matrix[i][j / 2] = globals::hole;
                else 
                    board.matrix[i][j / 2] = globals::empty;
        }

        bool found = false;

        for(const int idx: {0, 1, 2, 3}){
            // debug_board(board_malloc::root);
            // debug_board(board_malloc::root -> next[idx]);

            bool ok = true;
            for(int i = 0; i < 8 and ok; i++)
                for(int j = 0; j < 8 and ok; j++)
                    if(board.matrix[i][j] != board_malloc::root -> next[idx] -> matrix[i][j]) ok = false;

            if(ok == true){
                board_malloc::free_board(board_malloc::root);
                board_malloc::root = board_malloc::root -> next[idx];
                found = true;
                break;
            }
        }

        board_malloc::root -> prev = nullptr;
        // if(found == false){
        //     std::cout << "ojoj " << std::endl;
        //     exit(1);
        // }

        utils::T0 = utils::get_time();
    }

    void make_moves(){
        for(int i = 0; utils::elapsed_time() < 90'000 and board_malloc::free_idx > 4 * globals::no_simulates; i++){
            struct_board *selected = select(board_malloc::root);
            expand(selected);
        }
    }

    void debug_board(struct_board *board){
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

    }

    void free_board(struct_board *board){
        if(board -> next[0] != nullptr){
            for(const int &i: {0, 1, 2, 3}){
                free_board(board -> next[i]);
            }
        }

        board_malloc::free_board(board);
    }

    std::pair<int, int> random_simulate(struct_board *board){
        struct_board copy = *board;

        while(copy.no_players[0] and copy.no_players[1]){
            uint32_t dir = utils::random() % 4;
            shift(dir, &copy, copy.player);
            copy.player ^= 1;
        }

        return copy.no_players[0] ? std::make_pair(0, copy.no_players[0]) : std::make_pair(1, copy.no_players[1]);
    }

    void print_move(){
        int arg_ans = 0, ans_val = -1;

        for(auto &i: {0, 1, 2, 3})
            if(board_malloc::root -> next[i] -> win > ans_val){
                arg_ans = i;
                ans_val = board_malloc::root -> next[i] -> win;
            }
            
        std::string s = globals::string_of_dir[arg_ans];

        // now we can free board
        for(const int &i: {0, 1, 2, 3}){
            if(arg_ans != i){
                free_board(board_malloc::root -> next[i]);
                board_malloc::root -> next[i] = nullptr;
            }
        }

        board_malloc::free_board(board_malloc::root);
        board_malloc::root = board_malloc::root -> next[arg_ans];

        std::cout << s << std::endl;
    }

    void shift_left(struct_board *board, int l, int r, int i){
        if(l == board -> left_bound or board -> matrix[i][l - 1] == globals::hole){
            board -> no_players[board -> matrix[i][l]]--;
            board -> matrix[i][l++] = globals::empty;
        } 

        while(l <= r){
            board -> matrix[i][l - 1] = board -> matrix[i][l];
            board -> matrix[i][l] = globals::empty;
            l++;
        }
    }

    void shift_right(struct_board *board, int l, int r, int i){
        if(r == board -> right_bound or board -> matrix[i][r + 1] == globals::hole){
            board -> no_players[board -> matrix[i][r]]--; 
            board -> matrix[i][r--] = globals::empty;
        }

        while(l <= r){
            board -> matrix[i][r + 1] = board -> matrix[i][r];
            board -> matrix[i][r] = globals::empty;
            r--;
        }
    }

    void shift_up(struct_board *board, int u, int d, int j){
        if(u == board -> up_bound or board -> matrix[u - 1][j] == globals::hole){
            board -> no_players[board -> matrix[u][j]]--;
            board -> matrix[u++][j] = globals::empty;
        }

        while(u <= d){
            board -> matrix[u - 1][j] = board -> matrix[u][j];
            board -> matrix[u][j] = globals::empty;
            u++;
        }
    }

    void shift_down(struct_board *board, int u, int d, int j){
        if(d == board -> down_bound or board -> matrix[d + 1][j] == globals::hole){
            board -> no_players[board -> matrix[d][j]]--;
            board -> matrix[d--][j] = globals::empty;
        }

        while(u <= d){
            board -> matrix[d + 1][j] = board -> matrix[d][j];
            board -> matrix[d][j] = globals::empty;
            d--;
        }
    }

    bool debug_player(struct_board *board){
        int p[] = {0, 0};
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                if(board -> matrix[i][j] == 0) p[0]++;
                else if(board -> matrix[i][j] == 1) p[1]++;
        
        return p[0] == board -> no_players[0] and p[1] == board -> no_players[1];
    }

    void set_left_border(struct_board *board){
        bool shifted = true;
        while(shifted){
            shifted = false;
            int ok = true, j = board -> left_bound;
            for(int i = 0; i < 8; i++)
                if(board -> matrix[i][j] < 2) ok = false;
            
            if(ok){
                shifted = true;
                board -> left_bound++;
                for(int i = 0; i < 8; i++)
                    board -> matrix[i][j] = globals::hole;
            }
        }
    }

    void set_right_border(struct_board *board){
        bool shifted = true;
        while(shifted){
            shifted = false;

            int ok = true, j = board -> right_bound;
            for(int i = 0; i < 8; i++)
                if(board -> matrix[i][j] < 2) ok = false;
            
            if(ok){
                shifted = true;
                board -> right_bound--;
                for(int i = 0; i < 8; i++)
                    board -> matrix[i][j] = globals::hole;
            }
        }

    }

    void set_up_border(struct_board *board){
        bool shifted = true;
        while(shifted){
            shifted = false;

            int ok = true, i = board -> up_bound;
            for(int j = 0; j < 8; j++)
                if(board -> matrix[i][j] < 2) ok = false;

            if(ok){
                shifted = true;
                board -> up_bound++;
                for(int j = 0; j < 8; j++)
                    board -> matrix[i][j] = globals::hole;
            }
        }
    }

    void set_down_border(struct_board *board){
        bool shifted = true;
        while(shifted){
            shifted = false;
            int ok = true, i = board -> down_bound;
            for(int j = 0; j < 8; j++)
                if(board -> matrix[i][j] < 2) ok = false;

            if(ok){
                shifted = true;
                board -> down_bound--;
                for(int j = 0; j < 8; j++)
                    board -> matrix[i][j] = globals::hole;
            }
        }
    }

    void shift(int dir, struct_board *board, int player){
        switch(dir){
            // RIGHT
            case 2: {
                for(int i = 0; i < 8; i++){
                    int l = board -> right_bound, r;
                    while(l >= board -> left_bound){
                        if(board -> matrix[i][l] == player){
                            r = l;
                            while(r + 1 < 8 and board -> matrix[i][r + 1] < 2) r++;
                            shift_right(board, l, r, i);
                        }

                        l--;
                    }
                } 

                break;
            }

            // UP
            case 3: {
                for(int j = 0; j < 8; j++){
                    int u, d = board -> up_bound;
                    while(d <= board -> down_bound){
                        if(board -> matrix[d][j] == player){
                            u = d;
                            while(u - 1 >= 0 and board -> matrix[u - 1][j] < 2) u--;
                            shift_up(board, u, d, j);
                        }
                        d++;
                    }
                }

                break;
            }
            
            // DOWN
            case 0: {
                for(int j = 0; j < 8; j++){
                    int u = board -> down_bound, d;
                    while(u >= board -> up_bound){
                        if(board -> matrix[u][j] == player){
                            d = u;
                            while(d + 1 < 8 and board -> matrix[d + 1][j] < 2) d++;
                            shift_down(board, u, d, j);
                        }
                        u--;
                    }
                }

                break;
            }

            // LEFT
            case 1: {
                for(int i = 0; i < 8; i++){
                    int l, r = board -> left_bound;
                    while(r <= board -> right_bound){
                        if(board -> matrix[i][r] == player){
                            l = r; 
                            while(l - 1 >= 0 and board -> matrix[i][l - 1] < 2) l--;
                            shift_left(board, l, r, i);
                        }
                        r++;
                    }
                }

                break;  
            }
        }

        set_up_border(board);
        set_down_border(board);
        set_right_border(board);
        set_left_border(board);

        // if(!debug_player(board))
        //     std::cout << "XD" << std::endl;

        // debug_board(board);
    }
}