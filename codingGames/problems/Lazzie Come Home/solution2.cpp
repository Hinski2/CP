/*
    some informations about D* lite:
        * if we don't know if somewhere is obastacle we assume we can go through
        * we find paths from v_goal to v_start contrary to LPA*
        
    math notation
        * g(v): represetns smallest known cost from v to v_goal
        * rhs(v): (right hand side) represents minimal cost to go to v based on v's neighbours
    
    how it works:
        1. inicialization
            * we set all g(v) := inf, rhs(v) := inf
            * we set g(v_goal) := inf, rhs(v_goal) := 0 
            * we set all grid to ok
        2. update
            * if g(v) != rhs(v): 
                v is inconsistent and we add v to priority queue
            * if g(v) == rhs(v):
                v is consistent and we remove it from priority queue 
        3.
        TODO


        full implementation of algorithm: https://idm-lab.org/bib/abstracts/papers/aaai02b.pdf
*/

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
static const int max_map_size = 205;
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
int g[mak][mak], rhs[mak][mak], c[mak][mak][4];
enum_tile grid[mak][mak];
pii v_start, v_goal, v_last;
int no_moves_per_tour;

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

inline int h(int x, int y){
    return abs(x - v_goal.fi) + abs(y - v_goal.se); // our v_start hanges, so we have to adjust it with k_m
}

//! pq section
struct Key{
    int k1;
    int k2;

    // should this be before other? 
    bool operator<(const Key &other) const{
        if(k1 == other.k1)
            return k2 < other.k2;
        return k1 < other.k1;
    }
};

struct Node{
    int x; 
    int y;
    Key key;

    // should this be before other?
    bool operator<(const Node &other) const{
        return key < other.key;
    }
};

Key calculate_key(int x, int y){
    int k1 = min(g[x][y], rhs[x][y]) + h(x, y);
    int k2 = min(g[x][y], rhs[x][y]);
    return Key{k1, k2};
}

inline bool ok_coord(int x, int y){
    return 0 < x and x < mak - 1 and 0 < y and y < mak - 1;
}

multiset<Node> open;
multiset<Node>::iterator open_key[mak][mak];

//! class section
class Universe{
public:
    //! data
    int move[1];
    Universe(){
        cin >> vision_range >> home_distance_h >> home_distance_v;
        if(debug) cerr << vision_range << ' ' << home_distance_h << ' ' << home_distance_v << endl;

        v_start = {mak / 2, mak /2};
        v_goal = {v_start.fi + home_distance_v, v_start.se + home_distance_h};

        T0 = get_time(); // start time
        no_moves_per_tour = 1;
    }

    //! utils section
    void update_tile(int x, int y){
        if(!(v_start.fi == x and v_start.se == y)){
            rhs[x][y] = inf;
            for(auto num: {0, 1, 2, 3})
                rhs[x][y] = min(rhs[x][y], g[x + dir[num].fi][y + dir[num].se] + c[x + dir[num].fi][y + dir[num].se][3 - num]);
        }

        // remove node from open list
        if(open_key[x][y] != open.end()){
            open.erase(open_key[x][y]);
            open_key[x][y] = open.end();
        }

        //if g(v) != rhs(v) add v to open
        if(g[x][y] != rhs[x][y]){
            auto itr = open.insert(Node{x, y, calculate_key(x, y)});
            open_key[x][y] = itr;
        }
    }

    void block_tile(int x, int y){  // we update tile from ok -> bad
        // block nodes to and from tile (x, y)
        grid[x][y] = bad;
        
        for(auto u: {0, 1, 2, 3}) 
            c[x][y][u] = inf;

        c[x - 1][y][0] = inf;
        c[x][y + 1][1] = inf;
        c[x][y - 1][2] = inf;
        c[x + 1][y][3] = inf;

        update_tile(x, y);
        for(auto u: dir) // updae all neighbours of (x, y)
            if(ok_coord(x + u.fi, y + u.se)) update_tile(x + u.fi, y + u.se);
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
        // set all tiles to ok
        // set g and rhs
        for(int i = 0; i < mak; i++){
            for(int j = 0; j < mak; j++){
                grid[i][j] = ok;
                g[i][j] = inf;
                rhs[i][j] = inf;
                open_key[i][j] = open.end();
                for(auto u: {0, 1, 2, 3})
                    c[i][j][u] = 1; 
            }
        }

        // set v_goal
        rhs[v_start.fi][v_start.se] = 0;

        // append start pos on open list
        auto itr = open.insert(Node{v_start.fi, v_start.se, calculate_key(v_start.fi, v_start.se)});
        open_key[v_start.fi][v_start.se] = itr;

        // set a border around map not to exit it 
        for(int i = 0; i < mak; i++){
            c[mak - 1][i][0] = inf; 
            c[i][0][1] = inf;
            c[i][mak - 1][2] = inf;
            c[0][i][3] = inf;
        }
    }

    void compute_shortest_path(){
        while(open.begin() -> key < calculate_key(v_goal.fi, v_goal.se) or rhs[v_goal.fi][v_goal.se] != g[v_goal.fi][v_goal.se]){
            Node u = *open.begin();
            open.erase(open_key[u.x][u.y]);
            open_key[u.x][u.y] = open.end();

            if(g[u.x][u.y] > rhs[u.x][u.y]){ // set g(u):= rhs(u), update all neigbours
                g[u.x][u.y] = rhs[u.x][u.y];
            }
            else{ //set g(u):= inf, update all neighbours and u
                g[u.x][u.y] = inf;
                update_tile(u.x, u.y);
            }

            for(auto d: dir){
                d.fi += u.x, d.se += u.y;
                if(ok_coord(d.fi, d.se)) update_tile(d.fi, d.se);
            }
        }
    }

    void print_moves(){
        for(int i = 0; i < no_moves_per_tour; i++){
            cout << char_of_enum_dir(move[i]);
        }
        cout << endl;
    }

    void print_map(){
        for(int i = 0; i < mak; i++){
            for(int j = 0; j < mak; j++){
                if(g[i][j] == inf) cout << "INF";
                else if(g[i][j] < 10) cout << ' ' << rhs[i][j];
                else cout << rhs[i][j];
                cout << ' ';
            }
            cout << endl;
        }
    }

    int get_move(){
        int last = 0;
        pii current = v_goal;
        while(current != v_start){
            int mini = inf, argmini = 0;
            for(auto u: {0, 1, 2, 3}){
                int cost = g[current.fi + dir[u].fi][current.se + dir[u].se] + c[current.fi + dir[u].fi][current.se + dir[u].se][3 - u];
                if(cost < mini){
                    mini = cost;
                    argmini = u;
                }
            }
            current.fi += dir[argmini].fi; current.se += dir[argmini].se;
            last = argmini;
        }
        return 3 - last;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Universe universe;
    universe.initialize();
    universe.compute_shortest_path();

    int i = 0;  ////////////////////////////
    while(1){
        // scan universe
        universe.get_input();

        // compute shortest path
        universe.compute_shortest_path();

        // make some moves
        int argmini = universe.get_move();

        // move v_start 
        v_start.fi += dir[argmini].fi, v_start.se += dir[argmini].se;
        universe.move[0] = argmini;
        universe.print_moves();
        i++;
    }
}