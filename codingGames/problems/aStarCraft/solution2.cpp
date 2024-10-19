#pragma GCC optimize("Ofast,inline,tracer")
#pragma GCC optimize("unroll-loops,vpt,split-loops,unswitch-loops") 
#pragma GCC target("arch=haswell,tune=haswell")

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
const position_and_tile dir[] = {{-1, 0, U}, {0, -1, L}, {1, 0, D}, {0, 1, R}};
vector<vector<position_and_tile>> possible_moves;

//! utils
//* time section
uint64_t T0;

extern "C" {
    int gettimeofday(struct timeval* tv, void* tz);
}

uint64_t getTime() { //return time in microsecunds
    struct timeval t;
    gettimeofday(&t, nullptr);
    return static_cast<uint64_t>(t.tv_sec) * 1000000UL + static_cast<uint64_t>(t.tv_usec);
}

inline int elapsed_time(){
        return getTime() - T0;
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

//* vis section
uint64_t vis[N][M];

// clean visited
inline void clean_vis(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            vis[i][j] = 0;
}

//! main classes and structures
struct Solution{
    //! data
    int score;
    vector<position_and_tile> arrangement;

    //! utils
    void print(){
        for(auto u: arrangement){
            if(u.dir == Empty) continue;
            cout << u.y << ' ' << u.x << ' ' << char_of_tile_enum[u.dir] << ' ';
        }
        cout << '\n';
    }

    constexpr u_int64_t robot_bit(const int robot_idx, const Robot &robot){
        return 1ULL << (robot_idx * 4 + robot.dir); 
    }

    void generate_arrangemetn(){
        for(int i = 0; i < empty_tiles.size(); i++)
            arrangement[i] = possible_moves[i][my_random() % possible_moves[i].size()];
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
                vis[robot.x][robot.y] |= robot_bit(robot_idx, robot);

                robot.x += int_of_x_tile_enum[robot.dir], set_x(robot.x);
                robot.y += int_of_y_tile_enum[robot.dir], set_y(robot.y);
                if(grid[robot.x][robot.y] < 4)
                    robot.dir = grid[robot.x][robot.y];
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
            T0 = getTime();      // start timer 
            find_empty_tiles();

            solution.arrangement.resize(empty_tiles.size());
            best_solution.arrangement.resize(empty_tiles.size());
            solution.score = 0, best_solution.score = 0;

            generate_possible_moves();
    }
    ~Game(){}

    //! utils
    inline bool has_a_neighbour_arrow(int x, int y){
        for(auto u: dir){
            u.x += x; set_x(u.x);
            u.y += y; set_y(u.y);
            if(grid[x][y] < 4) return 1;
        }
        return 0;
    }

    inline pair<int, int> surrounding_void(int x, int y){
        pair<int, int> ans = {0, 0};
        for(auto u: dir){
            u.x += x; set_x(u.x);
            u.y += y; set_y(u.y);
            if(grid[u.x][u.y] == Void){
                ans.first += (int_of_x_tile_enum[u.dir] != 0);
                ans.second += (int_of_y_tile_enum[u.dir] != 0);
            }
        }

        return ans;
    }

    // finds appropriate empty tiles, here i reduce search space 
    void find_empty_tiles(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] != Empty) continue;
                // check numb of surrounding void
                auto [x, y] = surrounding_void(i, j);

                // if (2, 0) or (0, 2) or (0, 0) and !has_a_neighbour_arrow skipp
                if(((x == 2 && y == 0) || (x == 0 && y == 2) || (x == 0 && y == 0)) && !has_a_neighbour_arrow(i, j)) continue;

                // it's a good place to put arrow
                empty_tiles.push_back({i, j});
            }
        }
    }

    void generate_possible_moves(){
        possible_moves.resize(empty_tiles.size());
        for(int i = 0; i < empty_tiles.size(); i++){
            auto [x, y] = empty_tiles[i];
            for(auto u: dir){
                u.x += x, u.y += y;
                set_x(u.x), set_y(u.y);
                if(grid[u.x][u.y] != Void) possible_moves[i].push_back({x, y, u.dir});
            }
            possible_moves[i].push_back({x, y, Empty});
        }
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
            cin >> y >> x >> c;
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
Solution best_solution;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Game game;                              // create game, get input and finds empty tiles

    while(elapsed_time() < 990'000){
        game.solve();
    }
    
    game.best_solution.print();
}