#include<bits/stdc++.h>

//! const section 
constexpr bool debug = true;
constexpr int max_gift_no = 207;
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
}

// player
namespace player{
    int score[2];
    struct_bot bot[2][3];
    int gift_intercetpion_time[2][3][max_gift_no]; // [me / foe][bot_idx][gift_idx]
    pii interval[3];

    void compute_time_to_gifts(int bot_idx);
    bool fireball(int bot_idx);
}

namespace gameplay{
    void constructor(){
        std::cin >> no_bot_per_player;
        if(debug) std::cerr << no_bot_per_player << std::endl;
        
        gift::gift[max_gift_no - 1] = {max_gift_no - 1, 0, 320, 620, 0};
        gift::gift[max_gift_no - 2] = {max_gift_no - 2, 0, 960, 620, 0};
        gift::gift[max_gift_no - 3] = {max_gift_no - 2, 0, 1600, 620, 0};

        player::interval[0] = {0, 640};
        player::interval[1] = {640, 1280};
        player::interval[2] = {640, 1920};
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

    int choose_best_gift(int bot_idx){
        int mini = inf, argmini = max_gift_no - (bot_idx + 1), val = -1;
        for(int i = 0; i < gift::end; i++){
            if(gift::gift[i].x < player::interval[bot_idx].first or player::interval[bot_idx].second < gift::gift[i].x) continue;
            int opp_min = std::min(player::gift_intercetpion_time[foe][0][i], std::min(player::gift_intercetpion_time[foe][1][i], player::gift_intercetpion_time[foe][2][i]));

            if(player::bot[me][bot_idx].cooldown <= 2){
                if(player::gift_intercetpion_time[me][bot_idx][i] != never && player::gift_intercetpion_time[me][bot_idx][i] <= mini && player::gift_intercetpion_time[me][0][i] - 2 <= opp_min and gift::gift[i].value > val)
                    mini = player::gift_intercetpion_time[me][bot_idx][i], argmini = i, val = gift::gift[i].value;
            }
            else{
                if(player::gift_intercetpion_time[me][bot_idx][i] != never && player::gift_intercetpion_time[me][bot_idx][i] <= mini && player::gift_intercetpion_time[me][bot_idx][i] <= opp_min and gift::gift[i].value > val)
                    mini = player::gift_intercetpion_time[me][bot_idx][i], argmini = i, val = gift::gift[i].value;
            }
        }

        return argmini;
    }

    void find_path(int best_gift, int bot_idx){
        double d_x = gift::gift[best_gift].x - player::bot[me][bot_idx].x, d_y = gift::gift[best_gift].y - player::gift_intercetpion_time[me][bot_idx][best_gift] * gift::gift[best_gift].speed - player::bot[me][bot_idx].y;
        double dist = std::min(150, (int) std::sqrt(d_x*d_x + d_y*d_y));
        double theta = std::atan2(d_y, d_x);

        player::bot[me][bot_idx].x += (int) (dist * std::cos(theta));
        player::bot[me][bot_idx].y += (int) (dist * std::sin(theta));
    }

    void make_move(){
        // compute time to intercept each gift
        for(int bot = 0; bot < 3; bot++)
            player::compute_time_to_gifts(bot);

        for(int bot = 0; bot < 3; bot++){
            // fireball!!!!
            if(player::fireball(bot)) continue;

            // choose best gift
            int best_gift = choose_best_gift(bot);

            // find path
            find_path(best_gift, bot);
            
            // print resultat
            std::cout << "FLY " << player::bot[me][bot].x << ' ' << player::bot[me][bot].y << std::endl;
        }
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
    void compute_time_to_gifts(int bot_idx){
        for(int i = 0; i < gift::end; i++){

            gift_intercetpion_time[me][bot_idx][i] = never;
            gift_intercetpion_time[foe][bot_idx][i] = never;
            for(int t = 0; t < 14; t++){
                if(gift::gift[i].y - gift::gift[i].speed * t < 0) break;
                if(gift::gift[i].y - gift::gift[i].speed * t > 750) continue;

                int d_x = gift::gift[i].x - bot[me][bot_idx].x;
                int d_y = gift::gift[i].y - gift::gift[i].speed * t  - bot[me][bot_idx].y;
                int dist = std::ceil(std::sqrt(d_x * d_x + d_y * d_y));

                if(dist - 30 <= 150 * t){
                    gift_intercetpion_time[me][bot_idx][i] = t;
                    break;
                }
            }

            for(int t = 0; t < 14; t++){
                if(gift::gift[i].y - gift::gift[i].speed * t < 0) break;
                if(gift::gift[i].y - gift::gift[i].speed * t > 750) continue;

                int d_x = gift::gift[i].x - bot[foe][bot_idx].x;
                int d_y = gift::gift[i].y - gift::gift[i].speed * t  - bot[foe][bot_idx].y;
                int dist = std::ceil(std::sqrt(d_x * d_x + d_y * d_y));

                if(dist - 30 <= 150 * t){
                    gift_intercetpion_time[foe][bot_idx][i] = t;
                    break;
                }
            }
        }
    }

    bool fireball(int bot_idx){
        // if in this round my opponent reaches gift that I can't reach 
        if(player::bot[me][bot_idx].cooldown) return 0;

        int best_id = -1, best_val = -1;
        for(int i = 0; i < gift::end; i++){
            double d_x = gift::gift[i].x - bot[me][bot_idx].x;
            double d_y = gift::gift[i].y - bot[me][bot_idx].y;
            int dist = std::ceil(std::sqrt(d_x*d_x + d_y*d_y)); 

            if(player::gift_intercetpion_time[foe][0][i] == 1 and player::gift_intercetpion_time[me][bot_idx][i] and dist <= 300 and gift::gift[i].value > best_val){ // fireball it
                best_id = gift::gift[i].id;
                best_val = gift::gift[i].value;
            }
            if(player::gift_intercetpion_time[foe][1][i] == 1 and player::gift_intercetpion_time[me][bot_idx][i] and dist <= 300 and gift::gift[i].value > best_val){ // fireball it
                best_id = gift::gift[i].id;
                best_val = gift::gift[i].value;
            }
            if(player::gift_intercetpion_time[foe][2][i] == 1 and player::gift_intercetpion_time[me][bot_idx][i] and dist <= 300 and gift::gift[i].value > best_val){ // fireball it
                best_id = gift::gift[i].id;
                best_val = gift::gift[i].value;
            }
        }

        if(best_val != -1){ 
            std::cout << "FIREBALL " << best_id << std::endl;
            return 1;
        }

        return 0;
    }
}