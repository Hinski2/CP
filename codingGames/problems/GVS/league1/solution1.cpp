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

    inline void add(int id, int value, int x, int y, int speed);
    inline void pop_back();
    inline void remove(int idx);
    inline int time_to_gift(int gift_idx, int bot_idx, enum_player p);
}

// player
namespace player{
    int score[2];
    struct_bot bot[2][1];
    int gift_intercetpion_time[2][1][max_gift_no]; // [me / foe][bot_idx][gift_idx]

    void compute_time_to_gifts();
}

namespace gameplay{
    void constructor(){
        std::cin >> no_bot_per_player;
        if(debug) std::cerr << no_bot_per_player << std::endl;

        gift::gift[max_gift_no - 1] = {max_gift_no - 1, 0, 960, 620, 0};
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

    pii choose_best_gift(){
        int mini = inf;
        std::vector<int> argmini;
        argmini.push_back(max_gift_no - 1);

        for(int i = 0; i < gift::end; i++)
            if(player::gift_intercetpion_time[me][0][i] != never && player::gift_intercetpion_time[me][0][i] < mini && player::gift_intercetpion_time[me][0][i] <= player::gift_intercetpion_time[foe][0][i]){
                mini = player::gift_intercetpion_time[me][0][i];
                argmini.clear();
                argmini.push_back(i);
            }
            else if(player::gift_intercetpion_time[me][0][i] != never && player::gift_intercetpion_time[me][0][i] == mini && player::gift_intercetpion_time[me][0][i] <= player::gift_intercetpion_time[foe][0][i]){
                argmini.push_back(i);
            }
        
        if(mini == inf)
            return std::make_pair(gift::gift[argmini[0]].x, gift::gift[argmini[0]].y);

        for(auto u: argmini)
            gift::gift[u].y -= gift::gift[u].speed * player::gift_intercetpion_time[me][0][u];

        for(auto u: argmini){
            for(auto w: argmini){
                if(u == w) continue;
                double d_x = gift::gift[u].x - gift::gift[w].x;
                double d_y = gift::gift[u].y - gift::gift[w].y;
                int dist = std::ceil(std::sqrt(d_x*d_x + d_y*d_y));
                if(dist > 60) continue;

                return std::make_pair((gift::gift[u].x + gift::gift[w].x) / 2, (gift::gift[u].y + gift::gift[w].y) / 2);
            }
        }


        // choose best gift 
        int best_idx = argmini.front(), best_val = inf;
        for(auto u: argmini){
            int x = abs(gift::gift[u].x - 960) + abs(gift::gift[u].y - 620);
            if(x < best_val)
                x = best_val, best_idx = u;
        }

        return std::make_pair(gift::gift[best_idx].x, gift::gift[best_idx].y);
    }

    void find_path(pii best_point){
        double d_x = best_point.first - player::bot[me][0].x;
        double d_y = best_point.second - player::bot[me][0].y;
        double dist = std::min(150, (int) std::sqrt(d_x*d_x + d_y*d_y));
        double theta = std::atan2(d_y, d_x);

        player::bot[me][0].x += (int) (dist * std::cos(theta));
        player::bot[me][0].y += (int) (dist * std::sin(theta));
    }

    void make_move(){
        // compute time to intercept each gift
        player::compute_time_to_gifts();

        // choose best gift
        pii best_point = choose_best_gift();

        // find path
        find_path(best_point);
        
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

}

namespace player{
    void compute_time_to_gifts(){
        for(int i = 0; i < gift::end; i++){

            gift_intercetpion_time[me][0][i] = never;
            gift_intercetpion_time[foe][0][i] = never;
            for(int t = 0; t < 14; t++){
                if(gift::gift[i].y - gift::gift[i].speed * t < 0) break;
                if(gift::gift[i].y - gift::gift[i].speed * t > 750) continue;

                int d_x = gift::gift[i].x - bot[me][0].x;
                int d_y = gift::gift[i].y - gift::gift[i].speed * t  - bot[me][0].y;
                int dist = std::ceil(std::sqrt(d_x * d_x + d_y * d_y));

                if(dist - 30 <= 150 * t){
                    gift_intercetpion_time[me][0][i] = t;
                    break;
                }
            }

            for(int t = 0; t < 14; t++){
                if(gift::gift[i].y - gift::gift[i].speed * t < 0) break;
                if(gift::gift[i].y - gift::gift[i].speed * t > 750) continue;

                int d_x = gift::gift[i].x - bot[foe][0].x;
                int d_y = gift::gift[i].y - gift::gift[i].speed * t  - bot[foe][0].y;
                int dist = std::ceil(std::sqrt(d_x * d_x + d_y * d_y));

                if(dist - 30 <= 150 * t){
                    gift_intercetpion_time[foe][0][i] = t;
                    break;
                }
            }
        }
    }

    // void compute_time_to_gifts(){
    //     for(int i = 0; i < gift::end; i++){
    //         int d_x = gift::gift[i].x - bot[me][0].x;
    //         int d_y = gift::gift[i].y - bot[me][0].y;
        
    //         double a = 26100;
    //         double b = -120 * d_y - 9000;
    //         double c = d_x * d_x + d_y * d_y - 900;
    //         gift_intercetpion_time[me][0][i] = std::ceil((-b + std::sqrt(b*b - 4*a*c)) / 2*a);
    //     }
    // }
}