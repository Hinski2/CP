#pragma GCC optimize("Ofast,inline,tracer")
#pragma GCC optimize("unroll-loops,vpt,split-loops,unswitch-loops") 

#include <bits/stdc++.h>
using namespace std;

//! define sections
#define fi first 
#define se second
typedef pair<int, int> pii;

//! utils section
//* time utils section
uint64_t T0;

extern "C" {
    int gettimeofday(struct timeval* tv, void* tz);
}

uint64_t get_time() { //return time in microsecunds
    struct timeval t;
    gettimeofday(&t, nullptr);
    return static_cast<uint64_t>(t.tv_sec) * 1000000UL + static_cast<uint64_t>(t.tv_usec);
}

inline int elapsed_time(){
        return get_time() - T0;
}

//* random() utils section
uint32_t state = 2463534242;
uint32_t my_random(){   //implementation of xorshift32
    uint32_t x = state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    state = x;
    return x;
}

bool all_on_red(double prob){
    return (double) my_random() / UINT32_MAX < prob;
}

//! const values
static const int mak = 425;
static const int time_limit_first_turn = 990'000;
static const int time_limit = 45'000;
static const bool debug = false;
static const int max_output_size = 10;
static const int inf = 1e6 + 7;

//! enums
enum enum_tile{
    ok,
    bad,
    cat,
    home,
    idk
};

enum enum_dir{
    S_dir,  // (1, 0)
    W_dir,  // (0, -1)
    E_dir,  // (0, 1)
    N_dir   // (-1, 0)
};
static pii dir[] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // S, W, E, N 

inline char char_of_enum_dir(int d){
    switch(d){
        case S_dir:
            return 'S';
        case W_dir:
            return 'W';
        case E_dir:
            return 'E';
        case N_dir:
            return 'N';
    }

    return 'X';
}

//! data
int vision_range;
int home_distance_h, home_distance_v;
int dist[mak][mak];
enum_tile grid[mak][mak];
pii v_start, v_goal;

//! utils section
inline enum_tile enum_tile_of_char(char c){
    switch(c){
        case 'L':
            return cat;
        case 'H':
            return home;
        case '.':
            return ok;
        case '#':
            return bad;
        case '?':
            return idk;
    }
    return idk;
}

inline bool ok_coord(int x, int y){
    return 0 < x and x < mak - 1 and 0 < y and y < mak - 1 and grid[x][y] == ok;
}

struct node{
    int fi;
    int se;
    int d;
};

//! class section
class Universe{
public:
    //! data
    Universe(){
        cin >> vision_range >> home_distance_h >> home_distance_v;
        if(debug) cerr << vision_range << ' ' << home_distance_h << ' ' << home_distance_v << endl;

        v_start = {mak / 2, mak /2};
        v_goal = {v_start.fi + home_distance_v, v_start.se + home_distance_h};

        T0 = get_time(); // start time
    }

    //! utils section

    void block_tile(int x, int y){  // we update tile from ok -> bad
        // block nodes to and from tile (x, y)
        grid[x][y] = bad;
    }

    void get_input(){
        for(int i = 0, i_pos = v_start.fi - vision_range / 2; i < vision_range; i++, i_pos++){
            for(int j = 0, j_pos = v_start.se - vision_range / 2; j < vision_range; j++, j_pos++){
                char c; cin >> c;
                enum_tile t = enum_tile_of_char(c);
                if(t == bad) block_tile(i_pos, j_pos);
                if(debug) cerr << c;
            }
            if(debug) cerr << endl;
        }
    }

    void initialize(){
        for(int i = 0; i < mak; i++){
            for(int j = 0; j < mak; j++){
                grid[i][j] = ok;
            }
        }
    }

    void compute_shortest_path(){
        for(int i = 0; i < mak; i++)
            for(int j = 0; j < mak; j++)
                dist[i][j] = inf;
        dist[v_goal.fi][v_goal.se] = 0;
        queue<node> q;
        for(auto u: dir){
            u.fi += v_goal.fi; u.se += v_goal.se;
            if(ok_coord(u.fi, u.se)) q.push({u.fi, u.se, 1});
        }

        while(!q.empty()){
            node v = q.front(); q.pop();
            if(dist[v.fi][v.se] != inf) continue;
            dist[v.fi][v.se] = v.d; 
            for(auto u: dir){
                u.fi += v.fi; u.se += v.se;
                if(ok_coord(u.fi, u.se) and dist[u.fi][u.se] == inf) q.push({u.fi, u.se, v.d + 1});
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Universe universe;
    universe.initialize();

    while(1){
        // scan universe
        universe.get_input();

        // compute shortest path
        universe.compute_shortest_path();

        // make some moves
        int mini = inf, argmini = 0;
        for(auto u: {0, 1, 2, 3}){
            if(dist[v_start.fi + dir[u].fi][v_start.se + dir[u].se] < mini){
                mini = dist[v_start.fi + dir[u].fi][v_start.se + dir[u].se];
                argmini = u;
            }
        }

        // move v_start 
        v_start.fi += dir[argmini].fi; v_start.se += dir[argmini].se;
        
        // print ans;
        cout << char_of_enum_dir(argmini) << endl;
    }
}