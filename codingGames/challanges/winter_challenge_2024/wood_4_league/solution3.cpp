#include<bits/stdc++.h>

//! const section
constexpr bool debug = false;
constexpr int INF = 1e9 + 7;
constexpr int PROTEIN_NO = 4; // in this league 1
constexpr int MAX_MAP_SIZE = 25;
constexpr int MAX_VECTOR_SIZE = MAX_MAP_SIZE * MAX_MAP_SIZE;

//! define sections
#define fi first 
#define se second
typedef std::pair<int, int> pii;
constexpr pii DIR[] = { // S, W, E, N
    {0, 1}, {-1, 0}, {1, 0}, {0, -1}
};

//! enum section
enum enum_entity_type {
    A_PROTEIN,
    B_PROTEIN,
    C_PROTEIN,
    D_PROTEIN,
    WALL, 
    ROOT, 
    BASIC, 
    TENTACLE,
    HARVESTER,
    SPORER,
    NOTHING
};

enum enum_owner {
    MY_ORGAN, 
    FOE_ORGAN,
    NOT_ORGAN
};

enum enum_dir { 
    S_DIR,
    W_DIR, 
    E_DIR, 
    N_DIR,
    X_DIR
};

//! global var section
int n, m;
int required_action_count; // 1 in this league
int dist[MAX_MAP_SIZE][MAX_MAP_SIZE], to_enemy_dist[MAX_MAP_SIZE][MAX_MAP_SIZE];
bool occupied[MAX_MAP_SIZE][MAX_MAP_SIZE];
int tactic_step = 0;
bool was_used[MAX_VECTOR_SIZE];

//! structures
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

const std::unordered_map<std::string, enum_entity_type> map_string_to_entity = {
    {"A", A_PROTEIN},
    {"B", B_PROTEIN},
    {"C", C_PROTEIN},
    {"D", D_PROTEIN},
    {"WALL", WALL},
    {"ROOT", ROOT},
    {"BASIC", BASIC},
    {"TENTACLE", TENTACLE},
    {"HARVESTER", HARVESTER},
    {"SPORER", SPORER}
};

constexpr const char* string_of_entity[] = {"A", "B", "C", "D", "WALL", "ROOT", "BASIC", "TENTACLE", "HARVESTER", "SPORER"};
constexpr char string_of_dir[] = {'S', 'W', 'E', 'N'};

struct struct_entity{ 
    // position
    int x, y;

    // types: (here only) WALL, ROOT, BASIC, A_PROTEIN
    enum_entity_type type;

    // types: MY_ORGAN, ENEMY_ORGAN, NOONE
    int owner;

    // types: organ ? id : 0
    int organ_id;

    // types: (not used in this league) S_DIR, W_DIR, E_DIR, N_DIR
    enum_dir organ_dir;

    // for ROOT 0, if organ dir : 0
    int organ_parent_id;

    // organ ? id : 0
    int organ_root_id;

    enum_entity_type entity_type_of_string(std::string s){
        return map_string_to_entity.find(s) -> second;
    }

    int organ_owner_of_int(int x){
        if(x == 1) return MY_ORGAN;
        else if(x == 0) return FOE_ORGAN;
        return NOT_ORGAN;
    }

    enum_dir organ_dir_of_string(std::string s){
        if(s == "S") return S_DIR;
        if(s == "W") return W_DIR;
        if(s == "E") return E_DIR;
        if(s == "N") return N_DIR;
        return X_DIR;
    }
} entity_matrix[MAX_MAP_SIZE][MAX_MAP_SIZE];


struct vector_struct_entity{
    int size = 0;
    struct_entity arr[MAX_VECTOR_SIZE];

    inline void push_back(struct_entity x){
        arr[size++] = x;
    }

    inline void pop_back(){
        size--;
    }
    struct_entity get_object_with_id(int id){
        for(int i = 0; i < size; i++){
            if(arr[i].organ_id == id) return arr[i];
        }
        return arr[0];
    }

    inline void remove_with_id(int id){
        for(int i = 0; i < size; i++){
            if(arr[i].organ_id == id){
                std::swap(arr[i], arr[size - 1]);
                pop_back();
            }
        }
    }
};

struct struct_protein_well{
    int x;
    int y;
    int organ_parent_id;
};

struct vector_struct_protein_well{
    int size = 0;
    struct_protein_well arr[MAX_VECTOR_SIZE];

    inline void push_back(struct_protein_well x){
        arr[size++] = x;
    }

    inline void pop_back(){
        size--;
    }
};

struct struct_player{
    int proteins[PROTEIN_NO];
    vector_struct_entity entities;
    vector_struct_protein_well protein_wells;
} me, foe;

struct struct_chosen_body_part{
    std::string output_type;
    int x;
    int y; 
    int organ_parent_id; 
    int type;
    int dist;
    int dir;
} chosen_body_part;

namespace game{
    int entity_no;
    vector_struct_entity entities;
    std::string str; int x;
    
    bool ok_position(pii x);
    void get_input();
    void clean_distances();
    void compute_distances();
    void choose_body_part();
    void print_ans();
    void set_up_and_preprocess();
}

//! main
int main(){
    game::set_up_and_preprocess();
    while(true){
        game::get_input();

        while(required_action_count--){
            game::clean_distances();
            game::compute_distances();
            game::choose_body_part();

            if(chosen_body_part.type == HARVESTER){  // set tail -> occupied
                pii position = {chosen_body_part.x + DIR[chosen_body_part.dir].fi, chosen_body_part.y + DIR[chosen_body_part.dir].se};
                me.protein_wells.push_back({position.fi, position.se, chosen_body_part.organ_parent_id});
                occupied[position.fi][position.se] = true;
            }

            game::print_ans();
        }
    }
}

namespace game{
    inline void set_up_and_preprocess(){
        std::cin >> n >> m; //? remember 
        if(debug) std::cerr << n << ' ' << m << std::endl;
        if(m >= MAX_MAP_SIZE or n >= MAX_MAP_SIZE) std::cout << 42;

    }

    // inline bool is_next_to_enemys_tentacle(pii x){
    //     for(int i = 0; i < 4; i++){
    //         auto d = DIR[i];
    //         d.fi += x.fi, d.se += x.se;
    //         if(entity_matrix[d.fi][d.se].type == TENTACLE and entity_matrix[d.fi][d.se].owner == FOE_ORGAN and 3 - i == entity_matrix[d.fi][d.se].organ_dir) 
    //             return 1;
    //     }
    //     return 0;
    // }

    inline bool is_enemy_nerby(pii x, int deep){
        return to_enemy_dist[x.fi][x.se] <= deep;
    }

    inline int dir_to_enemy_nerby(pii x, int deep){
        int min_dist = INF, argmini = 0;

        for(int i = 0; i < 4; i++){
            auto d = DIR[i];
            d.fi += x.fi, d.se += x.se;

            if(to_enemy_dist[d.fi][d.se] < min_dist){
                min_dist = to_enemy_dist[d.fi][d.se];
                argmini = i;
            }
        }
        return argmini;
    }


    inline bool ok_position(pii x){
        return 0 <= x.fi and x.fi < n and 0 <= x.se and x.se < m;
    }

    inline void clean_distances(){
        for(int i = 0; i < MAX_MAP_SIZE; i++)
            for(int j = 0; j < MAX_MAP_SIZE; j++){
                dist[i][j] = INF;
                to_enemy_dist[i][j] = INF;
            }
    }

    inline void print_ans(){
        if(chosen_body_part.output_type == "GROW"){
            std::cout << "GROW " << chosen_body_part.organ_parent_id << ' ' << chosen_body_part.x << ' ' << chosen_body_part.y << ' ' << string_of_entity[chosen_body_part.type] << ' ';
            if(chosen_body_part.type != BASIC) std::cout << string_of_dir[chosen_body_part.dir];
            std::cout << std::endl;

            occupied[chosen_body_part.x][chosen_body_part.y] = true;
            auto parent = me.entities.get_object_with_id(chosen_body_part.organ_parent_id);
            was_used[parent.organ_root_id] = true;

            if(chosen_body_part.type == BASIC){
                me.proteins[A_PROTEIN]--;
            }
            else if(chosen_body_part.type == HARVESTER){
                me.proteins[C_PROTEIN]--;
                me.proteins[D_PROTEIN]--;
            }
            else if(chosen_body_part.type == TENTACLE){
                me.proteins[B_PROTEIN]--;
                me.proteins[C_PROTEIN]--;
            }
            else if(chosen_body_part.type == SPORER){
                me.proteins[B_PROTEIN]--;
                me.proteins[D_PROTEIN]--;
            }
        }
        else if(chosen_body_part.output_type == "SPORE") {
            std::cout << "SPORE " << chosen_body_part.organ_parent_id << ' ' << chosen_body_part.x << ' ' << chosen_body_part.y << std::endl;

            occupied[chosen_body_part.x][chosen_body_part.y] = true;
            auto parent = me.entities.get_object_with_id(chosen_body_part.organ_parent_id);
            was_used[parent.organ_root_id] = true;

            me.proteins[A_PROTEIN]--;
            me.proteins[B_PROTEIN]--;
            me.proteins[C_PROTEIN]--;
            me.proteins[D_PROTEIN]--;
        }
        else{
            std::cout << "WAIT" << std::endl;
        }
    }

    inline void choose_body_part(){
        // check if our protein wells are in danger
        if(me.proteins[B_PROTEIN] and me.proteins[C_PROTEIN]){
            for(int i = 0; i < me.protein_wells.size; i++){
                auto protein_well = me.protein_wells.arr[i];
                auto parent = me.entities.get_object_with_id(protein_well.organ_parent_id);
                if(was_used[parent.organ_root_id]) continue;

                if(is_enemy_nerby({protein_well.x, protein_well.y}, 2)){
                    chosen_body_part = {"GROW", protein_well.x, protein_well.y, protein_well.organ_parent_id, TENTACLE, dir_to_enemy_nerby({protein_well.x, protein_well.y}, 2)};
                    return;
                }
            }
        }

        // if it's begginign
        if(tactic_step == 0){
            auto e = me.entities.arr[0]; 
            chosen_body_part.dist = 0;

            for(auto d: DIR){
                for(int i = 0; i < 4; i++){
                    auto dd = DIR[i];
                    pii pos = {e.x + d.fi, e.y + d.se};
                    int dist_from_start = 1;

                    while(ok_position(pos) and !occupied[pos.fi][pos.se]){
                        if(dist_from_start > chosen_body_part.dist)
                            chosen_body_part = {"GROW", e.x + d.fi, e.y + d.se, e.organ_id, SPORER, dist_from_start, i};
                            
                        pos.fi += dd.fi, pos.se += dd.se;
                        dist_from_start++;
                    }
                }
            }

            tactic_step++;
            return;
        }

        else if(tactic_step == 1){
            auto e = me.entities.arr[0];
            if(e.type != SPORER) e = me.entities.arr[1];

            chosen_body_part.dist = INF;
            pii dir = DIR[e.organ_dir];
            pii pos = {e.x + dir.fi, e.y + dir.se};

            while(ok_position(pos) and !occupied[pos.fi][pos.se]){ // i don't want to schoot directly 
                if(dist[pos.fi][pos.se] > 1){
                    chosen_body_part = {"SPORE", pos.fi, pos.se, e.organ_id};
                    chosen_body_part.dist = dist[pos.fi][pos.se];
                }

                pos.fi += dir.fi, pos.se += dir.se;
            }

            if(chosen_body_part.dist != INF){
                tactic_step++;
                return;
            } 

            dir = DIR[e.organ_dir];
            pos = {e.x + dir.fi, e.y + dir.se};

            while(ok_position(pos) and !occupied[pos.fi][pos.se]){ // i don't want to schoot directly 
                if(dist[pos.fi][pos.se]){
                    chosen_body_part = {"SPORE", pos.fi, pos.se, e.organ_id};
                    chosen_body_part.dist = dist[pos.fi][pos.se];
                }

                pos.fi += dir.fi, pos.se += dir.se;
            }

            tactic_step++;
            return;
        }

        // our protein wells are fine 
        chosen_body_part.dist = INF;
        chosen_body_part.output_type = "WAIT";
        for(int i = 0; i < me.entities.size; i++){
            auto e = me.entities.arr[i];
            if(was_used[e.organ_root_id]) continue;

            for(int idx = 0; idx < 4; idx++){
                auto d = DIR[idx];
                d.fi += e.x, d.se += e.y;
                if(!ok_position(d) or occupied[d.fi][d.se]) continue;

                if(is_enemy_nerby(d, 1) and me.proteins[B_PROTEIN] and me.proteins[C_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, e.organ_id, TENTACLE, 0, dir_to_enemy_nerby(d, 1)};
                    return;
                }

                if(is_enemy_nerby(d, 2) and me.proteins[B_PROTEIN] and me.proteins[C_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, e.organ_id, TENTACLE, 0, dir_to_enemy_nerby(d, 2)};
                    return;
                }

                if(dist[d.fi][d.se] == 1 and me.proteins[C_PROTEIN] and me.proteins[D_PROTEIN]){
                    for(int j = 0; j < 4; j++){
                        auto dd = DIR[j];
                        dd.fi += d.fi, dd.se += d.se;
                        if(ok_position(dd) and !occupied[dd.fi][dd.se] and entity_matrix[dd.fi][dd.se].type < 4){
                            chosen_body_part = {"GROW", d.fi, d.se, e.organ_id, HARVESTER, 0, j};
                        }
                    }

                    return;
                } 

                // if I cant use antyhing else
                if(me.proteins[A_PROTEIN] and dist[d.fi][d.se] <= chosen_body_part.dist){ 
                    chosen_body_part = {"GROW", d.fi, d.se, e.organ_id, BASIC, dist[d.fi][d.se]};
                }
                if(dist[d.fi][d.se] <= chosen_body_part.dist and me.proteins[B_PROTEIN] and me.proteins[C_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, e.organ_id, TENTACLE, dist[d.fi][d.se], dir_to_enemy_nerby(d, 1)};
                }
                if(dist[d.fi][d.se] <= chosen_body_part.dist and me.proteins[C_PROTEIN] and me.proteins[D_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, e.organ_id, HARVESTER, dist[d.fi][d.se], idx};
                }
                if(dist[d.fi][d.se] <= chosen_body_part.dist and me.proteins[B_PROTEIN] and me.proteins[D_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, e.organ_id, SPORER, dist[d.fi][d.se], idx};
                }
            }
        }

        // we have to sacrifice well to move on
        if(chosen_body_part.output_type == "WAIT"){
            for(int i = 0; i < me.protein_wells.size; i++){
                auto well = me.protein_wells.arr[i];
                pii d = {well.x, well.y};
                if(!ok_position(d)) continue;

                if(me.proteins[A_PROTEIN] and dist[d.fi][d.se] <= chosen_body_part.dist){ 
                    chosen_body_part = {"GROW", d.fi, d.se, well.organ_parent_id, BASIC, dist[d.fi][d.se]};
                }
                if(dist[d.fi][d.se] <= chosen_body_part.dist and me.proteins[B_PROTEIN] and me.proteins[C_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, well.organ_parent_id, TENTACLE, dist[d.fi][d.se], dir_to_enemy_nerby(d, 1)};
                }
                if(dist[d.fi][d.se] <= chosen_body_part.dist and  me.proteins[C_PROTEIN] and me.proteins[D_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, well.organ_parent_id, HARVESTER, dist[d.fi][d.se], 0};
                }
                if(dist[d.fi][d.se] <= chosen_body_part.dist and me.proteins[B_PROTEIN] and me.proteins[D_PROTEIN]){
                    chosen_body_part = {"GROW", d.fi, d.se, well.organ_parent_id, SPORER, dist[d.fi][d.se], 0};
                }

            }
        }
    }

    inline void compute_distances(){
        struct queue_dist{
            int x;
            int y;
            int d;
        };

        // compute global distances
        std::queue<queue_dist> q;
        for(int i = 0; i < entity_no; i++){
            auto e = entities.arr[i];
            if(e.type < 4 and !occupied[e.x][e.y])
                q.push({e.x, e.y, 0});
        }

        // if there isn't any protein on the map
        if(q.empty()){
            for(int i = 0; i < me.entities.size; i++){
                auto e = me.entities.arr[i];
                q.push({e.x, e.y, 0});
            }
        }

        while(!q.empty()){
            auto e = q.front(); q.pop();
            if(dist[e.x][e.y] != INF) continue;
            dist[e.x][e.y] = e.d;
            for(auto d: DIR){
                d.fi += e.x, d.se += e.y;
                if(occupied[d.fi][d.se]) continue; 
                if(dist[d.fi][d.se] == INF)
                    q.push({d.fi, d.se, e.d + 1});
            }
        }

        // compute distances to enemies
        for(int i = 0; i < foe.entities.size; i++){
            auto e = foe.entities.arr[i];
            q.push({e.x, e.y, 0});
        }

        while(!q.empty()){
            auto e = q.front(); q.pop();
            if(to_enemy_dist[e.x][e.y] != INF) continue;
            to_enemy_dist[e.x][e.y] = e.d;
            for(auto d: DIR){
                d.fi += e.x, d.se += e.y;
                if(occupied[d.fi][d.se]) continue; 
                if(to_enemy_dist[d.fi][d.se] == INF)
                    q.push({d.fi, d.se, e.d + 1});
            }
        }
    }

    inline void get_input(){
        using namespace std;

        // prepare data
        for(int i = 0; i < MAX_MAP_SIZE; i++)
            for(int j = 0; j < MAX_MAP_SIZE; j++){
                entity_matrix[i][j].type = NOTHING;
                occupied[i][j] = false;
            }

        for(int i = 0; i < MAX_VECTOR_SIZE; i++)
            was_used[i] = false;

        me.protein_wells.size = 0;
        entities.size = 0, me.entities.size = 0, foe.entities.size = 0;

        // get input
        cin >> entity_no; 
        if(debug) cerr << entity_no << endl; 
        struct_entity e;
        for(int i = 0; i < entity_no; i++){
            
            cin >> e.x >> e.y;                                      if(debug) cerr << e.x << ' ' << e.y << endl;
            cin >> str; e.type = e.entity_type_of_string(str);      if(debug) cerr << str << endl;
            cin >> x; e.owner = e.organ_owner_of_int(x);            if(debug) cerr << x << endl;
            cin >> e.organ_id;                                      if(debug) cerr << e.organ_id << endl;
            cin >> str; e.organ_dir = e.organ_dir_of_string(str);   if(debug) cerr << str << endl;
            cin >> e.organ_parent_id;                               if(debug) cerr << e.organ_parent_id << endl;
            cin >> e.organ_root_id;                                 if(debug) cerr << e. organ_root_id << endl;


            if(e.type >= 4){ 
                occupied[e.x][e.y] = true;
            }

            entity_matrix[e.x][e.y] = e;
            entities.push_back(e);
            if(e.owner == MY_ORGAN) me.entities.push_back(e);
            else if(e.owner == FOE_ORGAN) foe.entities.push_back(e);
        }

        cin >> me.proteins[A_PROTEIN] >> me.proteins[B_PROTEIN] >> me.proteins[C_PROTEIN] >> me.proteins[D_PROTEIN];
        if(debug) cerr <<  me.proteins[A_PROTEIN] << ' ' <<  me.proteins[B_PROTEIN] << ' ' << me.proteins[C_PROTEIN] << ' ' <<  me.proteins[D_PROTEIN] << endl;
        cin >> foe.proteins[A_PROTEIN] >> foe.proteins[B_PROTEIN] >> foe.proteins[C_PROTEIN] >> foe.proteins[D_PROTEIN];
        if(debug) cerr <<  foe.proteins[A_PROTEIN] << ' ' <<  foe.proteins[B_PROTEIN] << ' ' << foe.proteins[C_PROTEIN] << ' ' <<  foe.proteins[D_PROTEIN] << endl;
        cin >> required_action_count;
        if(debug) cerr << required_action_count << endl;

        // find protein wells
        for(int i = 0; i < me.entities.size; i++){
            auto e = me.entities.arr[i];
            if(e.type == HARVESTER){
                pii pos = {e.x + DIR[e.organ_dir].fi, e.y + DIR[e.organ_dir].se};
                if(entity_matrix[pos.fi][pos.se].type < 4){
                    me.protein_wells.push_back({pos.fi, pos.se, e.organ_id});
                    occupied[pos.fi][pos.se] = true;
                }
            }
        }
    }
}
