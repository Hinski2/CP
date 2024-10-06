#include <bits/stdc++.h>
using namespace std;

struct connection{
    int b1;         // bulding 1 
    int b2;         // bulding 2
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
    int sum_of_astronaut_type[20];  // if building is landing pad
};

class City{
public:
    int resorces;   
    int num_of_routs;               // number of routes (tubes or teleports) currently present in the city 
    vector<connection> routs;   
    int num_of_pods;                // number of pods currently present in the city 
    vector<pod> pods;   
    int num_of_buildings;           // number of buildings that have just been constructed
    vector<building> buildings;

    City(int resorces, int num_of_routs, vector<connection> routs, int num_of_pods, vector<pod> pods, int num_of_buildings, vector<building>buildings)
        : resorces(resorces), num_of_routs(num_of_routs), routs(routs), num_of_pods(num_of_pods), pods(pods), num_of_buildings(num_of_buildings), buildings(buildings) {}
    ~City(){}

    void get_input(){
        cin >> resorces;
        cin >> num_of_routs;
        routs.resize(num_of_routs);
        for(int i = 0, b1, b2, capacity; i < num_of_routs; i++){
            cin >> b1 >> b2 >> capacity;
            routs[i].b1 = b1;
            routs[i].b2 = b2;
            routs[i].capaicty = capacity;
        }
        cin >> num_of_pods;
        pods.resize(num_of_pods);
        for(int i = 0, id, num_of_stops; i < num_of_pods; i++){
            cin >> id >> num_of_pods;
            pods[i].id = id;
            pods[i].num_of_stops = num_of_stops;
            pods[i].stops.resize(num_of_stops);
            for(int j = 0; j < num_of_stops; j++){
                cin >> pods[i].stops[j];
            }
        }

        int num_of_new_buildings; cin >> num_of_new_buildings;
        buildings.resize(num_of_buildings + num_of_new_buildings);
        for(int i = num_of_buildings, btype, bx, by, bid; i < num_of_buildings + num_of_new_buildings; i++){
            cin >> btype >> bid >> bx >> by;
            buildings[i].type = btype;
            buildings[i].id = bid;
            buildings[i].coord.x = bx;
            buildings[i].coord.y = by;

            if(btype == 0){ //if building is a landing pad
                int sum; cin >> sum;
                buildings[i].num_of_astronauts = sum;
                for(int j = 0, x; j < sum; j++){
                    cin >> x;
                    buildings[i].sum_of_astronaut_type[x]++;
                }
            }
        }
        num_of_buildings += num_of_new_buildings;
    }

    // TODO
        // heuristic evaluation fucntion
        // decision tree 
        // getting output
};

int main(){
    City selenia(0, 0, vector<connection>(), 0, vector<pod>(), 0, vector<building>());
    while(true){
       selenia.get_input(); 
    }
}