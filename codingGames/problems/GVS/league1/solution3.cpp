#include<bits/stdc++.h>

// TODO jeśli nie ma giftów na mapie to leć na środek 

//! const section 
constexpr bool debug = true;
constexpr int max_gift_no = 205;
constexpr int inf = 1e9 + 7;
constexpr int never = 1000;

//! define sections
#define fi first 
#define se second
typedef std::pair<int, int> pii;

//! utils section
namespace utils{
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

//! enum section
enum enum_player{
    me, 
    foe 
};

//! struct section
struct struct_bot{
    int x;
    int y; 
    int cooldown;
};

struct struct_gift{
    int id;
    int value;
    int x;
    int y;
    int speed;
};

//! data section
int no_bot_per_player, missed_present_to_end;
int p1 = me, p2 = foe;

// gift
namespace gift{
    int number, end = 0;
    struct_gift gift[max_gift_no];
    bool used[max_gift_no];

    int compute_time_to_gift(pii pos, int gift_idx, int time);

    inline void add(int id, int value, int x, int y, int speed);
    inline void pop_back();
    inline void remove(int idx);
}

// player
namespace player{
    int score[2];
    struct_bot bot[2][1];

    int compute_time_to_gift(enum_player player, int bot_idx, int gift_idx);
}

namespace gameplay{
    void constructor(){
        std::cin >> no_bot_per_player;
        if(debug) std::cerr << no_bot_per_player << std::endl;

        gift::gift[max_gift_no - 1] = {max_gift_no - 1, 0, 960, 550, 0};
    }

    void get_input(){
        std::cin >> missed_present_to_end; if(debug) std::cerr << missed_present_to_end << std::endl;

        std::cin >> player::score[me]; if(debug) std::cerr << player::score[me] << std::endl;
        for(int i = 0; i < no_bot_per_player; i++){
            std::cin >> player::bot[me][i].x >> player::bot[me][i].y >> player::bot[me][i].cooldown;
            if(debug) std::cerr << player::bot[me][i].x << ' ' << player::bot[me][i].y << ' ' << player::bot[me][i].cooldown << std::endl;
        }

        std::cin >> player::score[foe]; if(debug) std::cerr << player::score[foe] << std::endl;
        for(int i = 0; i < no_bot_per_player; i++){
            std::cin >> player::bot[foe][i].x >> player::bot[foe][i].y >> player::bot[foe][i].cooldown;
            if(debug) std::cerr << player::bot[foe][i].x << ' ' << player::bot[foe][i].y << ' ' << player::bot[foe][i].cooldown << std::endl;
        }

        gift::end = 0;
        std::cin >> gift::number; if(debug) std::cerr << gift::number << std::endl;
        for(int i = 0, id, value, x, y, speed; i < gift::number; i++){
            std::cin >> id >> value >> x >> y >> speed;
            if(debug) std::cerr << id << ' ' << value << ' ' << x << ' ' << y << ' ' << speed << std::endl;
            gift::add(id, value, x, y, speed);
        }
    }

    int dfs(int v, int energy, int current_time){
        int mini = never;
        gift::used[v] = 1;

        if(energy == 0){
            gift::used[v] = 0;
            return current_time;
        }

        for(int i = 0; i < gift::end; i++){
            int time = gift::compute_time_to_gift(std::make_pair(gift::gift[v].x, gift::gift[v].y), i, current_time);
            if(!gift::used[i] and time != never) mini = std::min(mini, dfs(i, energy - 1, time));
        }

        gift::used[v] = 0;
        return mini;
    }

    int choose_best_gift(){
        int mini = never, argmini = max_gift_no - 1;

        // energy 3
        // for(int i = 0; i < gift::end; i++){
        //     int time = player::compute_time_to_gift(me, 0, i);
        //     if(time == never) continue;

        //     int cost = dfs(i, 3, time);
        //     if(cost < mini)
        //         mini = cost, argmini = i;
        // }
        // if(mini != never) return argmini;

        // energy 2
        // for(int i = 0; i < gift::end; i++){
        //     int time = player::compute_time_to_gift(me, 0, i);
        //     if(time == never) continue;

        //     int cost = dfs(i, 2, time);
        //     if(cost < mini)
        //         mini = cost, argmini = i;
        // }
        // if(mini != never) return argmini;

        // energy 1
        for(int i = 0; i < gift::end; i++){
            int time = player::compute_time_to_gift(me, 0, i);
            if(time == never) continue;

            int cost = dfs(i, 1, time);
            if(cost < mini and time <= player::compute_time_to_gift(foe, 0, i))
                mini = cost, argmini = i;
        }
        if(mini != never) return argmini;

        // energy 0
        for(int i = 0; i < gift::end; i++){
            int cost = player::compute_time_to_gift(me, 0, i);
            if(cost < mini and cost <= player::compute_time_to_gift(foe, 0, i))
                mini = cost, argmini = i;
        }

        return argmini;
    }

    void find_path(int best_gift){
        double d_x = gift::gift[best_gift].x - player::bot[me][0].x;
        double d_y = gift::gift[best_gift].y - player::compute_time_to_gift(me, 0, best_gift) * 60 - player::bot[me][0].y;
        double dist = std::min(150, (int) std::ceil(std::sqrt(d_x*d_x + d_y*d_y)));
        double theta = std::atan2(d_y, d_x);

        player::bot[me][0].x += (int) (dist * std::cos(theta));
        player::bot[me][0].y += (int) (dist * std::sin(theta));
    }

    void make_move(){
        // choose best gift
        int best_gift = choose_best_gift();

        // find path
        find_path(best_gift);
        
        // print resultat
        static int d = 0;
        std::cout << "FLY " << player::bot[me][0].x << ' ' << player::bot[me][0].y << ' ' << d++ << std::endl;
    }
}

int main(){
    gameplay::constructor();
    while(1){
        gameplay::get_input();
        gameplay::make_move();
    }
}


// gift
namespace gift{
    inline void add(int id, int value, int x, int y, int speed){
        gift[end++] = {id, value, x, y, speed};
    }

    inline void pop_back(){
        end--;
    }

    inline void remove(int idx){
        std::swap(gift[idx], gift[end - 1]);
        pop_back();
    }

    int compute_time_to_gift(pii pos, int gift_idx, int time){
        for(int t = time; t < 14; t++){
            if(gift[gift_idx].y - gift[gift_idx].speed * t < 0) return never;
            if(gift[gift_idx].y - gift[gift_idx].speed * t > 750) continue;

            double d_x = gift[gift_idx].x - pos.first;
            double d_y = gift[gift_idx].y - gift[gift_idx].speed * t - pos.second;
            int dist = std::ceil(std::sqrt(d_x*d_x + d_y*d_y));
            if(dist - 30 <= 150 * t) return t;

        }
        return never;
    }
}

namespace player{
    int compute_time_to_gift(enum_player player, int bot_idx, int gift_idx){
        for(int t = 0; t < 14; t++){
            if(gift::gift[gift_idx].y - gift::gift[gift_idx].speed * t < 0) return never;
            if(gift::gift[gift_idx].y - gift::gift[gift_idx].speed * t > 750) continue;

            double d_x = gift::gift[gift_idx].x - bot[player][bot_idx].x;
            double d_y = gift::gift[gift_idx].y - gift::gift[gift_idx].speed * t - bot[player][bot_idx].y;
            int dist = std::ceil(std::sqrt(d_x*d_x + d_y*d_y));
            if(dist - 30 <= 150 * t) return t;
        }
        return never;
    }
}