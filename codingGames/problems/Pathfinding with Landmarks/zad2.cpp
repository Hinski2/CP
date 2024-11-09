// #pragma GCC optimize("Ofast,inline,tracer")
// #pragma GCC optimize("unroll-loops,vpt,split-loops,unswitch-loops") 
#include <bits/stdc++.h>
using namespace std;

//! define sections
#define fi first 
#define se second

//! enum section
enum enum_tile{
    wall,
    ground, 
    landmark
};

//! const section
constexpr int mak = 242;
constexpr int max_test_no = 100;
constexpr uint64_t time_limit = 990'000 * 5; // basically 20s
constexpr pair<int, int> dir[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, -1}};
constexpr bool debugmode = true;


//! data section
double required_efficency;
int max_landmarks_no, current_landmarks_no;
enum_tile grid[mak][mak];
bool vis[mak][mak];
int n, m;
int dist[mak][mak];

struct struct_test{
    int a;
    int b;
    int c;
    int d;
    int dist_to_p1[mak][mak];
    int dist_to_p2[mak][mak];
};

//! color section
int no_colors;
int color[mak][mak];
vector<int> sajz_of_color;
vector<vector<pair<int,int>>> pts_with_color;
vector<int> landmark_color;
queue<int> landmark_idx_to_add;
struct_test tests[max_test_no];

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

//* other utils
void clean_vis(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            vis[i][j] = 0;
}

bool all_on_red(double prob){
    return (double) my_random() / UINT32_MAX < prob;
}

//! struct for solution
struct struct_solution{
    int score;
    vector<pair<int, int>> landmarks;

    void assign_color_to_landmarks(){
        random_device rd;
        vector<double> biases(no_colors + 1);
        biases[0] = 0;
        int sum = 0;
        for(auto u: sajz_of_color)
            sum += u;

        for(int i = 1; i <= no_colors; i++)
            biases[i] = (double) sajz_of_color[i] / sum;

        for(int i = 0; i < max_landmarks_no; i++){
            mt19937 gen(rd());
            discrete_distribution<> dist(biases.begin(), biases.end());
            landmark_color[i] = dist(gen);
        }
    }

    void test(){
        score = 0;
        for(auto t: tests){
            int subscore = 0;
            for(auto l: landmarks)
                subscore = max(subscore, abs(t.dist_to_p1[l.fi][l.se] - t.dist_to_p2[l.fi][l.se]));
            score += subscore;
        }
    }
};

struct_solution solution, best_solution;

//! class city
class City{
public:
    //!constructor and destructor
    City(){
        // get input
        get_input();

        // start time
        T0 = get_time();
    }

    //! utils section
    void get_input(){
        cin >> max_landmarks_no >> required_efficency;
        if(debugmode) cerr << max_landmarks_no << ' ' << required_efficency << endl;
        cin >> m >> n; //first is width then is height
        if(debugmode) cerr << m << ' ' << n << endl;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c; cin >> c;
                grid[i][j] = (c == '.' ? ground : wall);
                if(debugmode) cerr << c;
            }
            if(debugmode) cerr << endl;
        }

        solution.landmarks.resize(max_landmarks_no, {-1, -1});
        landmark_color.resize(max_landmarks_no);
    }

    void print_ans(){
        for(auto u: best_solution.landmarks){
            if(u == make_pair(-1, -1))
                cout << "error in print_ans" << endl;
            else    
                cout << u.se << ' ' << u.fi << endl;
        }
    }

    //! colourful section
    void color_dfs(int x, int y){
        color[x][y] = no_colors;
        sajz_of_color[no_colors]++;
        pts_with_color[no_colors].push_back({x, y});

        for(auto u: dir){
            u.fi += x, u.se += y;
            if(grid[u.fi][u.se] != wall and !color[u.fi][u.se]) color_dfs(u.fi, u.se);
        }
    }

    void color_city(){
        sajz_of_color.push_back(0);
        pts_with_color.resize(1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!color[i][j] and grid[i][j] != wall){
                    sajz_of_color.push_back(0);
                    no_colors++;
                    pts_with_color.push_back(vector<pair<int, int>>());
                    color_dfs(i, j);
                }
            }
        }
    }


    //! distance section
    pair<int, int> farthest_point_from_all_landmarks(){
        //we place landmark in color c
        clean_vis();
        int c = landmark_color[landmark_idx_to_add.front()];
        queue<pair<int, int>> q;
        for(int i = 0; i < max_landmarks_no; i++)
            if(landmark_color[i] == c and solution.landmarks[i] != make_pair(-1, -1)) q.push(solution.landmarks[i]);

        if(q.empty()){ // if we don't have any landmarks yet
            q.push(pts_with_color[c][0]);
        }

        pair<int, int> ans;
        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();

            if(vis[a][b]) continue;
            vis[a][b] = 1;
            ans = {a, b};

            for(auto step: dir){
                step.fi += a, step.se += b;
                if(vis[step.fi][step.se] || grid[step.fi][step.se] == wall)  continue;
                q.push(step);
            }
        }

        return ans;
    }

    //! landmarks section
    void place_landmark(){
        pair<int, int> best_spot = farthest_point_from_all_landmarks();
        solution.landmarks[landmark_idx_to_add.front()] = {best_spot.fi, best_spot.se};
        grid[best_spot.fi][best_spot.se] = landmark;
        landmark_idx_to_add.pop();
    }

    void remove_landmark(int landmark_idx){
        grid[solution.landmarks[landmark_idx].fi][solution.landmarks[landmark_idx].se] = ground;
        solution.landmarks[landmark_idx] = {-1, -1};
        current_landmarks_no--;
        landmark_idx_to_add.push(landmark_idx);
    }

    void place_all_landmarks(){
        for(auto &u: solution.landmarks)
            u = {-1, -1};
        for(int i = 0; i < max_landmarks_no; i++)
            landmark_idx_to_add.push(i);

        current_landmarks_no = 0;
        while(!landmark_idx_to_add.empty()){
            place_landmark();

            // sometimes remove landmarks
            if(all_on_red(0.3)){
                int idx = my_random() % max_landmarks_no;
                while(solution.landmarks[idx] == make_pair(-1, -1)) idx = my_random() % max_landmarks_no;
                remove_landmark(idx);
            }
        }
    }

    void make_solution(){
        solution.assign_color_to_landmarks();
        place_all_landmarks();
        solution.test();
        if(solution.score > best_solution.score)
            best_solution = solution;
    }

    void make_distance_to_test(int idx){
        struct_test &test = tests[idx];

        queue<tuple<int, int, int>> q; //x, y, dist
        q.push({test.a, test.b, 1});
        while(!q.empty()){
            auto t = q.front(); q.pop();
            if(test.dist_to_p1[get<0>(t)][get<1>(t)]) continue;
            test.dist_to_p1[get<0>(t)][get<1>(t)] = get<2>(t);
            for(auto u: dir){
                u.fi += get<0>(t), u.se += get<1>(t);
                if(grid[u.fi][u.se] == wall) continue;
                if(test.dist_to_p1[u.fi][u.se] == 0) q.push({u.fi, u.se, get<2>(t)+1});
            }
        }

        q.push({test.c, test.d, 1});
        while(!q.empty()){
            auto t = q.front(); q.pop();
            if(test.dist_to_p2[get<0>(t)][get<1>(t)]) continue;
            test.dist_to_p2[get<0>(t)][get<1>(t)] = get<2>(t);
            for(auto u: dir){
                u.fi += get<0>(t), u.se += get<1>(t);
                if(grid[u.fi][u.se] == wall) continue;
                if(test.dist_to_p2[u.fi][u.se] == 0) q.push({u.fi, u.se, get<2>(t)+1});
            }
        }
    }

    void prepare_tests(){
        for(int i = 0; i < max_test_no; i++){
            do{
                tests[i].a = my_random() % n;
                tests[i].b = my_random() % m;
            }while(grid[tests[i].a][tests[i].b] == wall);

            int c = color[tests[i].a][tests[i].b];
            pair<int, int> x = pts_with_color[c][my_random() % pts_with_color[c].size()];
            tests[i].c = x.fi;
            tests[i].d = x.se;

            make_distance_to_test(i);
        }
    }
};

//! main
int main(){
    City city;

    // color graph
    city.color_city();

    // prepare tests
    city.prepare_tests();

    while(elapsed_time() < time_limit){ 
        city.make_solution();
    } 
    
    // print ans
    city.print_ans();
}