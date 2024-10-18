#include <bits/stdc++.h>
using namespace std;

//! const
static const int N = 10;
static const int M = 19;
static const int moves_no = 4;
static const int max_tiles = 190;

//! enums
enum tile{
    U, 
    L,
    D,
    R,
    Empty, 
    Void,
}; 

//! structs
struct Robot{
    int x;
    int y;
    tile dir; 
};

struct position{
    int x;
    int y;

    position operator+(const position &other) const {
        return position{x + other.x, y + other.y};
    }
};


struct position_and_tile{
    int x;
    int y;
    tile dir;

    inline int s_x(int x) const{
        if(x < 0) return N - 1;
        else if(x >= N) return 0;
        return x;
    }

    inline int s_y(int y) const{
        if(y < 0) return M - 1;
        else if(y >= M) return 0;
        return y;
    }

    position_and_tile operator+(const position_and_tile &other) const {
        return position_and_tile{s_x(x + other.x), s_y(y + other.y), other.dir};
    }
};

//! data
int num_of_robot;
tile grid[N][M];
vector<Robot> robots;
vector<position> empty_tiles;
const position_and_tile dir[] = {{1, 0, U}, {0, -1, L}, {-1, 0, D}, {0, 1, R}};

//! utils
    //* time section
std::chrono::steady_clock::time_point T0;
inline int elapsed_time(){
    return chrono::duration_cast<std::chrono::milliseconds>(chrono::steady_clock::now() - T0).count();
}

    //* tile section
constexpr char char_of_tile_enum[] = {'U', 'L', 'D', 'R', '.', '#'};
constexpr int int_of_x_tile_enum[] = {-1, 0, 1, 0};
constexpr int int_of_y_tile_enum[] = {0, -1, 0, 1};

inline void set_x(int &x){
    if(x < 0) x = N - 1;
    else if(x >= N) x = 0;
}

inline void set_y(int &y){
    if(y < 0) y = M - 1;
    else if(y >= M) y = 0;
}

inline tile tile_enum_of_char(int c){
    switch(c){
        case 'U':
            return U;
        case 'L':
            return L;
        case 'D':
            return D;
        case 'R':
            return R;
        case '.':
            return Empty;
        case '#':
            return Void;
    }
    return Void;
}

    //* random section
uint32_t state = 2463534242;
uint32_t my_random(){   //implementation of xorshift32
    uint32_t x = state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    state = x;
    return x;
}


//! main classes and structures
struct Solution{
    //! data
    int score;
    uint64_t vis[N][M];
    vector<position_and_tile> arrangement;

    //! utils
    void print(){
        for(auto u: arrangement)
            cout << u.x << ' ' << u.y << ' ' << char_of_tile_enum[u.dir];
    }

    // clean visited
    inline void clean_vis(){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                vis[i][j] = 0;
    }

    constexpr u_int64_t robot_bit(const int robot_idx, const Robot &robot){
        return 1ULL << (robot_idx * 4 + robot.dir); 
    }

    void generate_arrangemetn(){
        for(auto &u: arrangement){
            vector<position_and_tile> options{{u.x, u.y, Empty}};
            for(auto o: dir){
                o = u + o;
                if(grid[o.x][o.y] != Void) options.push_back(u);
            }
            u = options[my_random() % options.size()];
        }
    }

    void overwrite_grid(){
        for(auto u: arrangement)
            grid[u.x][u.y] = u.dir;
    }

    // retuns score 
    void evaluate_score(){
        score = 0;
        clean_vis();

        int robot_idx = 0;
        for(auto robot: robots){
            while(grid[robot.x][robot.y] != Void && !(vis[robot.x][robot.y] & robot_bit(robot_idx, robot))){
                score++;
                robot.x += int_of_x_tile_enum[robot.dir], set_x(robot.x);
                robot.y += int_of_x_tile_enum[robot.dir], set_y(robot.y);
                if(grid[robot.x][robot.y] < 4)
                    robot.dir = grid[robot.x][robot.y];

                vis[robot.x][robot.y] |= robot_bit(robot_idx, robot);
            }
            robot_idx++;
        }
    }
};

class Game{
public:
    //! data
    Solution solution, best_solution;

    //! constructor and destructor
    Game(){
            get_input();
            find_empty_tiles();
            solution.arrangement.resize(empty_tiles.size());
            solution.score = 0, best_solution.score = 0;
            for(int i = 0; i < empty_tiles.size(); i++){
                solution.arrangement[i].x = empty_tiles[i].x;
                solution.arrangement[i].y = empty_tiles[i].y;
            }
    }
    ~Game(){}

    //! utils
    // finds empty tiles :)
    void find_empty_tiles(){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(grid[i][j] == Empty)
                    empty_tiles.push_back({i, j});
    }


    //! get input
    void get_input(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                char c; cin >> c;
                grid[i][j] = tile_enum_of_char(c);
                // cerr << char_of_tile_enum[grid[i][j]];              //!
            }
            // cerr << endl;                                           //!
        }

        cin >> num_of_robot;
        // cerr << num_of_robot << endl;                               //!
        robots.resize(num_of_robot);
        for(int i = 0; i < num_of_robot; i++){
            int x, y; char c;
            cin >> x >> y >> c;
            // cerr << x << ' ' << y << ' ' << c << endl;              //!
            robots[i] = {x, y, tile_enum_of_char(c)};
        }
    }

    //! main methods
    // create solution, make simulation and overwrite best_solution
    void solve(){
        solution.generate_arrangemetn();
        solution.overwrite_grid();
        solution.evaluate_score();

        if(solution.score > best_solution.score){
            best_solution = solution;
        }
    }
};

//! ans
Solution *best_solution;

int main(){
    T0 = chrono::steady_clock::now(); // start timer 
    Game game; // create game, get input and finds empty tiles

    while(1){
        game.solve();
    }
    
    game.best_solution.print();
}

// To debug: cerr << "Debug messages..." << endl;