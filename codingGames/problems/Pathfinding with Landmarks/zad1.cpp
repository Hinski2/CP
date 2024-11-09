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
constexpr uint64_t time_limit = 999'000 * 20; // basically 20s
constexpr pair<int, int> dir[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, -1}};
constexpr bool debugmode = true;


//! data section
double required_efficency;
int max_landmarks_no, current_landmarks_no;
vector<pair<int, int>> landmarks;
enum_tile grid[mak][mak];
bool vis[mak][mak];
int n, m;

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

        landmarks.resize(max_landmarks_no, {-1, -1});
    }

    void print_ans(){
        for(auto u: landmarks){
            if(u == make_pair(-1, -1))
                cout << "error in print_ans" << endl;
            else    
                cout << u.se << ' ' << u.fi << endl;
        }
    }

    //! distance section
    pair<int, int> farthest_point_from_all_landmarks(){
        // just make simultanious bfs from all landmarks

        clean_vis();
        queue<pair<int, int>> q;
        for(int i = 0; i < current_landmarks_no; i++)
            q.push(landmarks[i]);

        if(q.empty()){ // if we don't have any landmarks yet
            int a = my_random() % n, b = my_random() % m;
            while(grid[a][b] == wall)
                a = my_random() % n, b = my_random() % m;
            q.push({a, b});
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
        landmarks[current_landmarks_no++] = {best_spot.fi, best_spot.se};
        grid[best_spot.fi][best_spot.se] = landmark;
    }

    void remove_landmark(int landmark_idx){
        grid[landmarks[landmark_idx].fi][landmarks[landmark_idx].se] = ground;
        swap(landmarks[current_landmarks_no - 1], landmarks[landmark_idx]);
        landmarks[current_landmarks_no - 1] = {-1, -1};
        current_landmarks_no--;
    }

    void place_all_landmarks(){
        while(current_landmarks_no < max_landmarks_no){
            place_landmark();

            // sometimes remove landmarks
            if(all_on_red(0.25))
                remove_landmark(my_random() % current_landmarks_no);
        }
    }
};

//! main
int main(){
    City city;

    // place all landmarks
    city.place_all_landmarks();
    
    // print ans
    city.print_ans();
}