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
    int dist[max_gift_no][max_gift_no];
    struct_gift gift[max_gift_no];

    inline void add(int id, int value, int x, int y, int speed);
    inline void pop_back();
    inline void remove(int idx);
    inline void compute_distance_between_gifts();
}

// player
namespace player{
    int score[2];
    struct_bot bot[2][1];
    int dist_to_gift[2][1][max_gift_no];            // [me / foe][bot_idx][gift_idx]

    void compute_distance_to_gifts();
}

namespace gameplay{
    int time_of_dist[2137];
    inline int time(int bot_id, enum_player player, int gift_id){
        int t1 = gift::gift[gift_id].y / 60;
        int t2 = time_of_dist[player::dist_to_gift[player][bot_id][gift_id]]; 
        if(t1 < t2) return never;
        return t2;
    }

    void constructor(){
        std::cin >> no_bot_per_player;
        if(debug) std::cerr << no_bot_per_player << std::endl;

        gift::gift[max_gift_no - 1] = {max_gift_no - 1, 0, 960, 550, 0};

        int t = 0;
        for(int i = 0; i <= 30; i++) time_of_dist[i] = t;
        for(int i = 0; i < 14; i++, t++)
            for(int j = 1; j <= 150; j++)
                time_of_dist[i * 150 + j + 30] = t;
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

    int choose_best_gift(){
        int mini = inf, argmini = max_gift_no - 1;
        for(int i = 0; i < gift::end; i++){
            if(time(0, me, i) != never and time(0, me, i) < mini and time(0, me, i) <= time(0, foe, i))
                mini = time(0, me, i), argmini = i;
        }
        return argmini;
    }

    // void find_path(int best_gift){
    //     double dist = std::min(150, player::dist_to_gift[me][0][best_gift]);
    //     double theta = std::atan2(gift::gift[best_gift].x - player::bot[me][0].x, gift::gift[best_gift].y - gift::gift[best_gift].speed - player::bot[me][0].y);

    //     player::bot[me][0].x += (int) (dist * std::cos(theta));
    //     player::bot[me][0].y += (int) (dist * std::sin(theta));
    // }

    void find_path(int best_gift){
        double d_x = gift::gift[best_gift].x - player::bot[me][0].x;
        double d_y = gift::gift[best_gift].y - time(0, me, best_gift) * 60 - player::bot[me][0].y;
        double dist = std::min(150, (int) std::sqrt(d_x*d_x + d_y*d_y));
        double theta = std::atan2(d_y, d_x);

        player::bot[me][0].x += (int) (dist * std::cos(theta));
        player::bot[me][0].y += (int) (dist * std::sin(theta));
    }

    void make_move(){
        // compute distance between gifts
        gift::compute_distance_between_gifts();

        // compute distance between bot and gifts
        player::compute_distance_to_gifts();

        // choose best gift
        int best_gift = choose_best_gift();

        // find path
        find_path(best_gift);
        
        // print resultat
        std::cout << "FLY " << player::bot[me][0].x << ' ' << player::bot[me][0].y << std::endl;
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

    inline void compute_distance_between_gifts(){
        for(int i = 0; i < end; i++){
            for(int j = 0; j < end; j++){
                double d_x = gift[i].x - gift[j].x;
                double d_y = gift[i].y - gift[j].y;
                int d = std::ceil(std::sqrt(d_x*d_x + d_y*d_y));
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }
    }
}

namespace player{
    void compute_distance_to_gifts(){
        for(int i = 0; i < gift::end; i++){
            double d_x = gift::gift[i].x - bot[me][0].x;
            double d_y = gift::gift[i].y - bot[me][0].y - gift::gift[i].speed;
            dist_to_gift[me][0][i] = std::ceil(std::sqrt(d_x*d_x + d_y*d_y));

            d_x = gift::gift[i].x - bot[foe][0].x;
            d_y = gift::gift[i].y - bot[foe][0].y - gift::gift[i].speed;
            dist_to_gift[foe][0][i] = std::ceil(std::sqrt(d_x*d_x + d_y*d_y));
        }
    }
}