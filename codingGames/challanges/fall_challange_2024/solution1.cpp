/*
    solution #1
    use only teleports
    score: 2221352
*/
#include <bits/stdc++.h>
using namespace std;

static const int max_buildings = 150;
static const int cost_of_teleport = 5000;

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
    //TODO add functions for tubes intersections and point segment intersection
};

struct building{
    int type;                       // 0 if landing pad, moduleType (positive int) if module
    int id;                         // unique id of building
    point coord;    
    int num_of_astronauts;          // if building is landing pad
    int sum_of_astronaut_type[21];  // if building is landing pad
    bool has_teleport;
};

class City{
public:
    int resorces;   
    int num_of_routs;               // number of routes (tubes and teleports) currently present in the city 
    vector<vector<connection>> G;   
    int num_of_pods;                // number of pods 
    vector<pod> pods;   
    int num_of_buildings;           // number of buildings 
    vector<building> buildings;

    City(int resorces, int num_of_routs, vector<vector<connection>> G, int num_of_pods, vector<pod> pods, int num_of_buildings, vector<building>buildings)
        : resorces(resorces), num_of_routs(num_of_routs), G(G), num_of_pods(num_of_pods), pods(pods), num_of_buildings(num_of_buildings), buildings(buildings) {}
    ~City(){}

    void get_input(){
        cin >> resorces; 
        cerr << resorces << endl; //!

        //things that ignore
        cin >> num_of_routs; 
        cerr << num_of_routs << endl; //!
        for(int i = 0, b1, b2, capacity; i < num_of_routs; i++){
            cin >> b1 >> b2 >> capacity;
            cerr << b1 << ' ' << b2 << ' ' << capacity << endl; //!
        }
        cin >> num_of_pods;
        cerr << num_of_pods << endl; //!
        for(int i = 0, id, num_of_stops; i < num_of_pods; i++){
            cin >> id >> num_of_stops;
            cerr << id << num_of_stops << endl; //!
            for(int j = 0, x; j < num_of_stops; j++){
                cin >> x;
                cerr << x << ' '; //!
            }
            cerr << endl; //!
        }

        // thiings that we don't ignore
        int num_of_new_buildings; cin >> num_of_new_buildings;
        cerr << num_of_new_buildings << endl; //!
        buildings.resize(num_of_buildings + num_of_new_buildings);
        for(int i = num_of_buildings, btype, bx, by, bid; i < num_of_buildings + num_of_new_buildings; i++){
            cin >> btype >> bid >> bx >> by;
            cerr << btype << ' ' << bid << ' ' << bx << ' ' << by << ' '; //!
            buildings[i].type = btype;
            buildings[i].id = bid;
            buildings[i].coord.x = bx;
            buildings[i].coord.y = by;
            buildings[i].has_teleport = false;

            if(btype == 0){ //if building is a landing pad
                int sum; cin >> sum;
                cerr << sum << ' '; //!
                buildings[i].num_of_astronauts = sum;
                for(int j = 0, x; j < sum; j++){
                    cin >> x;
                    cerr << x << ' '; //!
                    buildings[i].sum_of_astronaut_type[x]++;
                }
            }
            cerr << endl; //!
        }
        num_of_buildings += num_of_new_buildings;
    }

    struct poss_type{
        int pts;
        int b1;
        int b2;
    };

    static bool cmp(poss_type a, poss_type b){
        //does a should be before b 
        return a.pts > b.pts;
    };

    void upgrade_city(){
        // get landing pads without teleport
        vector<int> landing_pads_id;
        for(int i = 0; i < num_of_buildings; i++)
            if(!buildings[i].has_teleport && buildings[i].type == 0) landing_pads_id.push_back(i);

        // get lunar modules wthout teleport
        vector<int> lunar_modules_id;
        for(int i = 0; i < num_of_buildings; i++)
            if(!buildings[i].has_teleport && buildings[i].type) lunar_modules_id.push_back(i);


        // make vector with all possible pairs landing pad -> lunar module
        vector<poss_type> posibilities;
        for(auto u: landing_pads_id)
            for(auto w: lunar_modules_id){
                posibilities.push_back({buildings[u].sum_of_astronaut_type[buildings[w].type], u, w});
            }
        // sort the vector 
        sort(posibilities.begin(), posibilities.end(), cmp);
        
        // build greedely teleports
        if(posibilities.empty() || resorces < cost_of_teleport){
            //do nothing
            cout << "WAIT";
        }
        for(int i = 0; resorces >= cost_of_teleport && i < posibilities.size(); i++){
            if(buildings[posibilities[i].b1].has_teleport || buildings[posibilities[i].b2].has_teleport) continue;

            //add road
            cout << "TELEPORT " << posibilities.front().b1 << ' ' << posibilities.front().b2;
            resorces -= cost_of_teleport;
            buildings[posibilities[i].b1].has_teleport = true;
            buildings[posibilities[i].b2].has_teleport = true;
            num_of_routs++;
            G[posibilities[i].b1].push_back({posibilities[i].b2, 0});

            cout << ";";
        }
        cout << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    City selenia(0, 0, vector<vector<connection>>(max_buildings, vector<connection>()), 0, vector<pod>(), 0, vector<building>());
    while(true){
        // get input
       selenia.get_input(); 

       // upgrade city ifrst use only teleports
       selenia.upgrade_city();
    }
}