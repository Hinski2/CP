/*
    solution #2
    1. use tunels to make connection between dwo landing pads or between landing pad and lunar module 
    2. upgrade tunels (only between two landing pads)
    3. make teleports between landing pad and lunar module 
*/

#include <bits/stdc++.h>
using namespace std;

//! const values
static const int max_buildings = 151;
static const int cost_of_teleport = 5000;   // per one teleport
static const int cost_of_tube = 1;          // per 0.1km of tube rounded down 
static const int cost_of_pod = 1000;        // per one pod
static const double epsilon = 0.0000001;

//! structs
struct connection{
    int to;
    int capaicty;   // 0 if connection is teleport 
};

struct pod{
    int id;             // unique id of landing pad
    int num_of_stops;   
    vector<int> stops;  // identifiers of each builing on itinerary
};

struct point{
    int x;
    int y;
};

struct building{
    int type;                       // 0 if landing pad, moduleType (positive int) if module
    int id;                         // unique id of building
    point coord;    
    int num_of_astronauts;          // if building is landing pad
    int sum_of_astronaut_type[21];  // if building is landing pad
    bool has_teleport;
};

struct color_stats{
    int sajz;
    int sum_of_modules_type[21];
    int sum_of_astronaut_type[21];
};

//! utils
// normal distance 
inline double distance(const point &a, const point &b){
    int x = a.x - b.x; x *= x;
    int y = a.y - b.y; y *= y;
    return sqrt(x + y);
}

inline int cost_of_tube_connection(const point &a, const point &b){
    double d = distance(a, b);
    d *= 10;
    return (int) d;
}

// distance without sqrt
inline int distance_int(const point &a, const point &b){
    int x = a.x - b.x; x *= x;
    int y = a.y - b.y; y *= y;
    return x + y;
}

// does a lie on b-c segment
inline bool point_on_segment(const point &a, const point &b, const point &c){
    double x = distance(b, a) + distance(a, c) - distance(b, c);
    return -epsilon < x &&  x < epsilon;
}

inline int sign(const int &x){
    if(x == 0) return 0;
    if(x > 0) return 1;
    return -1;
}

inline int orientation(const point &a, const point &b, const point &c){
    int prod = (c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x);
    return sign(prod);
}

// does segmetn a-b intersect with segment c-d
inline bool segments_intersection(const point &a, const point &b, const point &c, const point &d){
    return orientation(a, b, c) * orientation(a, b, d) < 0 && orientation(c, d, a) * orientation(c, d, b) < 0;
}

//! main data structures
class City{
public:
    int resorces;   
    int num_of_routs;               // number of routes (tubes and teleports) currently present in the city 
    vector<vector<connection>> G;   
    int num_of_pods;                // number of pods 
    vector<pod> pods;   
    int num_of_buildings;           // number of buildings 
    vector<building> buildings;
    bool change;

    // dsu stuctures
    vector<int> p;                  // parrent 
    vector<color_stats> color;      // just color 

    City(int resorces, int num_of_routs, vector<vector<connection>> G, int num_of_pods, vector<pod> pods, int num_of_buildings, vector<building>buildings, vector<int> p, vector<color_stats> color)
        : resorces(resorces), num_of_routs(num_of_routs), G(G), num_of_pods(num_of_pods), pods(pods), num_of_buildings(num_of_buildings), buildings(buildings), p(p), color(color) {}
    ~City(){}

    void get_input(){
        cin >> resorces; 

        //things that ignore
        cin >> num_of_routs; 
        for(int i = 0, b1, b2, capacity; i < num_of_routs; i++){
            cin >> b1 >> b2 >> capacity;
        }
        cin >> num_of_pods;
        for(int i = 0, id, num_of_stops; i < num_of_pods; i++){
            cin >> id >> num_of_stops;
            for(int j = 0, x; j < num_of_stops; j++){
                cin >> x;
            }
        }

        // thiings that we don't ignore
        int num_of_new_buildings; cin >> num_of_new_buildings;
        buildings.resize(num_of_buildings + num_of_new_buildings);
        for(int i = num_of_buildings, btype, bx, by, bid; i < num_of_buildings + num_of_new_buildings; i++){
            cin >> btype >> bid >> bx >> by;
            buildings[i].type = btype;
            buildings[i].id = bid;
            buildings[i].coord.x = bx;
            buildings[i].coord.y = by;
            buildings[i].has_teleport = false;

            color[i].sajz = 1;
            p[i] = i;
            if(btype) color[i].sum_of_modules_type[btype]++;

            if(btype == 0){ //if building is a landing pad
                int sum; cin >> sum;
                buildings[i].num_of_astronauts = sum;
                for(int j = 0, x; j < sum; j++){
                    cin >> x;
                    buildings[i].sum_of_astronaut_type[x]++;
                    color[i].sum_of_astronaut_type[x]++;
                }
            }
        }
        num_of_buildings += num_of_new_buildings;
    }

    //! utils 
    struct connection_cost{
        int cost;
        int b1;
        int b2;
    };

    struct connection_pts{
        int pts;
        int b1;
        int b2;
    };

    static bool cmp_for_connection_pts(const connection_pts &a, const connection_pts &b){
        //does a should be before b
        return a.pts > b.pts;
    }

    static bool cmp_for_connection_cost(const connection_cost &a, const connection_cost &b){
        //does a should be before b
        return a.cost < b.cost;
    }

    bool ok_connection(const int id_a, const int id_b){
        for(auto u: G[id_a])
            if(u.to == id_b) return 0; // connection already exists

        if(G[id_a].size() >= 5 - buildings[id_a].has_teleport) return 0;
        if(G[id_b].size() >= 5 - buildings[id_b].has_teleport) return 0;

        for(int i = 0; i < num_of_buildings; i++){
            if(i == id_a || i == id_b) continue;
            if(point_on_segment(buildings[i].coord, buildings[id_a].coord, buildings[id_b].coord)) return 0;
        }

        for(int i = 0; i < num_of_buildings; i++)
            for(int j = 0; j < G[i].size(); j++){
                if(G[i][j].capaicty == 0) continue; // it is a teleport
                if(segments_intersection(buildings[id_a].coord, buildings[id_b].coord, buildings[i].coord, buildings[G[i][j].to].coord)) return 0;
            }

        return 1;
    }

    //! heura
    int evaluate_connection(const int id_a, const int id_b){
        int ans = 0;
        // opt 1: a - landing pad, b - lunar module
        if(buildings[id_a].type == 0 && buildings[id_b].type){
            ans = buildings[id_a].sum_of_astronaut_type[buildings[id_b].type];
            for(auto u: G[id_a])
                ans += buildings[u.to].sum_of_astronaut_type[buildings[id_b].type] * 2;
            if(ans == 0) ans--; 
        }

        //opt 2: a and b - landing pad
        else if(buildings[id_a].type == 0 && buildings[id_b].type == 0){
            if(find(id_a) == find(id_b)){
                ans--;
            }
            else{
                for(int i = 0; i < 21; i++)
                ans += min(color[find(id_a)].sum_of_astronaut_type[i], color[find(id_b)].sum_of_astronaut_type[i]);
            }
            ans /= 2;
        }

        //opt 3: a and b - lunar module
        else{
            if(find(id_a) != find(id_b)){
                ans += color[find(id_a)].sum_of_astronaut_type[buildings[id_b].type];
                ans += color[find(id_b)].sum_of_astronaut_type[buildings[id_a].type];
            }
            if(ans == 0) ans--;
        }

        return ans;
    }

    //! dsu
    int find(int id_v){
        if(id_v == p[id_v]) return id_v;
        return p[id_v] = find(p[id_v]);
    }

    void onion(int id_a, int id_b){
        id_a = find(id_a);
        id_b = find(id_b);

        if(id_a == id_b) return;
        if(color[id_a].sajz < color[id_b].sajz) swap(id_a, id_b); //a is bigger

        color[id_a].sajz += color[id_b].sajz;
        for(int i = 0; i < 21; i++){
            color[id_a].sum_of_astronaut_type[i] += color[id_b].sum_of_astronaut_type[i];
            color[id_a].sum_of_modules_type[i] += color[id_b].sum_of_modules_type[i];
        }

        p[id_b] = id_a;
    }

    //! implementation of 3 plan stages 
    // 1. use tunels to make connection between dwo landing pads or between landing pad and lunar module 
    void stage1(){
        // separate landing pads and lunar modules
        vector<int> landin_pads_id;
        vector<int> lunar_modules_id;
        for(int i = 0; i < num_of_buildings; i++){
            if(G[i].size() >= 5 - buildings[i].has_teleport) continue;  // building can have maxiamally 5 tube conectinos
            if(buildings[i].type == 0) landin_pads_id.push_back(i);
            else lunar_modules_id.push_back(i);
        }

        vector<connection_pts> possible_connections;
        // connections landin_pad <-> lunar module
        for(auto u: landin_pads_id)
            for(auto w: lunar_modules_id)
                if(ok_connection(u, w)) possible_connections.push_back({evaluate_connection(u, w), u, w});
        
        // connections landin_pad <-> landing pad
        for(auto u: landin_pads_id){
            for(auto w: landin_pads_id){
                if(u == w) continue;
                if(ok_connection(u, w)) possible_connections.push_back({evaluate_connection(u, w), u, w});
            }
        }

        sort(possible_connections.begin(), possible_connections.end(), cmp_for_connection_pts);

        for(int i = 0, j = 0; i < possible_connections.size() && j < 1; i++){
            int &a = possible_connections[i].b1;
            int &b = possible_connections[i].b2;
            if(possible_connections[i].pts == -1) continue;
            if(cost_of_tube_connection(buildings[a].coord, buildings[b].coord) + cost_of_pod > resorces) continue;
            if(!ok_connection(a, b)) continue;

            change = true;
            j++;
            resorces -= cost_of_tube_connection(buildings[a].coord, buildings[b].coord) + cost_of_pod;
            num_of_routs++;
            G[a].push_back({b, 1});
            G[b].push_back({a, 1});
            onion(a, b);
            cout << "TUBE " << a << ' ' << b << ';';

            num_of_pods++;
            cout << "POD " << num_of_pods << ' ' << a << ' ' << b << ' ' << a << ';';
        }
    }

    // 2. upgrade tunels (only between two landing pads)
    void stage2(){
        // separate landing pads and lunar modules
        vector<int> landin_pads_id;
        vector<int> lunar_modules_id;
        for(int i = 0; i < num_of_buildings; i++){
            if(G[i].size() >= 5 - buildings[i].has_teleport) continue;  // building can have maxiamally 5 tube conectinos
            if(buildings[i].type == 0) landin_pads_id.push_back(i);
            else lunar_modules_id.push_back(i);
        }

        vector<connection_pts> possible_connections;
        // connections landin_pad <-> lunar module
        for(auto u: landin_pads_id)
            for(auto w: lunar_modules_id)
                if(ok_connection(u, w)) possible_connections.push_back({evaluate_connection(u, w), u, w});
        
        // connections landin_pad <-> landing pad
        for(auto u: landin_pads_id){
            for(auto w: landin_pads_id){
                if(u == w) continue;
                if(ok_connection(u, w)) possible_connections.push_back({evaluate_connection(u, w), u, w});
            }
        }

        sort(possible_connections.begin(), possible_connections.end(), cmp_for_connection_pts);

        for(int i = 0; i < possible_connections.size(); i++){
            int &a = possible_connections[i].b1;
            int &b = possible_connections[i].b2;
            if(possible_connections[i].pts == -1) continue;
            if(cost_of_tube_connection(buildings[a].coord, buildings[b].coord) + cost_of_pod > resorces) continue;
            if(!ok_connection(a, b)) continue;

            change = true;
            resorces -= cost_of_tube_connection(buildings[a].coord, buildings[b].coord) + cost_of_pod;
            num_of_routs++;
            G[a].push_back({b, 1});
            G[b].push_back({a, 1});
            onion(a, b);
            cout << "TUBE " << a << ' ' << b << ';';

            num_of_pods++;
            cout << "POD " << num_of_pods << ' ' << a << ' ' << b << ' ' << a << ';';
        }
    }

    //  3. make teleports between landing pad and lunar module 
    void stage3(){
        // get landing pads without teleport
        vector<int> landing_pads_id;
        for(int i = 0; i < num_of_buildings; i++)
            if(!buildings[i].has_teleport && buildings[i].type == 0) landing_pads_id.push_back(i);

        // get lunar modules wthout teleport
        vector<int> lunar_modules_id;
        for(int i = 0; i < num_of_buildings; i++)
            if(!buildings[i].has_teleport && buildings[i].type) lunar_modules_id.push_back(i);


        // make vector with all possible pairs landing pad -> lunar module
        vector<connection_pts> posibilities;
        for(auto u: landing_pads_id)
            for(auto w: lunar_modules_id){
                posibilities.push_back({buildings[u].sum_of_astronaut_type[buildings[w].type], u, w});
            }

        // sort the vector 
        sort(posibilities.begin(), posibilities.end(), cmp_for_connection_pts);

        //build greedy teleports
        for(int i = 0; i < posibilities.size() && resorces >= cost_of_teleport; i++){
            int &a = posibilities[i].b1;
            int &b = posibilities[i].b2;
            if(buildings[a].has_teleport || buildings[b].has_teleport) continue;

            change = true;
            resorces -= cost_of_teleport;
            num_of_routs++;
            buildings[a].has_teleport = true;
            buildings[b].has_teleport = true;

            G[a].push_back({b, 0});
            G[b].push_back({a, 0});
            onion(a, b);
            cout << "TELEPORT " << a << ' ' << b << ';';
        }
    }

    // 4. make tube connection between lunar modules
    void stage4(){
        vector<int> lunar_moduls_id;
        for(int i = 0; i < num_of_buildings; i++)
            if(buildings[i].type) lunar_moduls_id.push_back(i);

        vector<connection_pts> poss;
        for(auto u: lunar_moduls_id){
            for(auto w: lunar_moduls_id){
                if(u == w) continue;
                if(ok_connection(u, w)) poss.push_back({evaluate_connection(u, w), u, w});
            }
        }

        sort(poss.begin(), poss.end(), cmp_for_connection_pts);
        for(int i = 0; i < poss.size(); i++){
            int &a = poss[i].b1;
            int &b = poss[i].b2;

            if(poss[i].pts == -1) continue;
            if(cost_of_tube_connection(buildings[a].coord, buildings[b].coord) + cost_of_pod > resorces) continue;
            if(!ok_connection(a, b)) continue;

            change = true;
            resorces -= cost_of_tube_connection(buildings[a].coord, buildings[b].coord) + cost_of_pod;
            num_of_routs++;
            G[a].push_back({b, 1});
            G[b].push_back({a, 1});
            onion(a, b);
            cout << "TUBE " << a << ' ' << b << ';';

            num_of_pods++;
            cout << "POD " << num_of_pods << ' ' << a << ' ' << b << ' ' << a << ';';
        }

    }

    void upgrade_city(){
        change = false;
        if(num_of_pods + 1 < 500)
            stage1();
        if(num_of_pods + 1 < 500)
            stage1();
        if(num_of_pods + 1 < 500)
            stage1();

        if(num_of_pods + 1 < 500)
            stage2();

        stage3(); // make teleports 
        if(num_of_pods + 1 < 500)
            stage4();

        if(change == false)
            cout << "WAIT";
        cout << endl;
    }
};

//! main
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    City selenia(0, 0, vector<vector<connection>>(max_buildings, vector<connection>()), 0, vector<pod>(),
        0, vector<building>(), vector<int>(max_buildings), vector<color_stats>(max_buildings));

    while(true){
        // get input
       selenia.get_input(); 

       // upgrade city use greedy teleports and tubes
       selenia.upgrade_city();
    }
}