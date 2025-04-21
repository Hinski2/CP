/*
  plan na zaimplementowanieie tego i dostanie pracy w nasa: 
    * najpierw wyrównujemy lot 
    * potem lecimy nad miejsce docelowe poruszając się tylko po x i pozostając na tym samym y (o ile się nie rozpijemy o skały)
    * obnirzamy lot
*/
#include<bits/stdc++.h>
using namespace std;

// const 
constexpr bool debug = true;
constexpr int MAX_LEN = 7'000;
constexpr double GRAVITY = -3.711;
constexpr double kp = 1, ki = 1, kd = 1;

struct coord{
    int x;
    int y;
};

// vars
int tajm = 0, n;
int x_rocket, y_rocket, h_speed_rocket, v_speed_rocket, fuel_rocket, angle_rocket, power_rocket;
coord mars[MAX_LEN], landing_spot;
double prevError = 0.0;

namespace simulate{
    pair<double, double> pid_vertical(int angle, int power); 
}

namespace game{
    // input
    void init();
    void get_input();

    // utils
    int compute_save_altitude();
    coord find_landing_spot();

    // making move
    void make_move();
    // void land();
    // void fly();
    void pull_up(int y_target);
}

int main(){
    game::init();

    while(1){
        game::get_input();
        game::make_move();
    }
}

namespace simulate{
    pair<double, double> pid_vertical(int angle, int power, int y_target){
        // compute delta
        double delta_x = power * sin(angle);
        double delta_y = power * cos(angle) + GRAVITY;

        // adjust rocket coords
        double x = x_rocket + delta_x;        
        double y = y_rocket + delta_y;

        // compute error
        double error = y_target - y;
        double derivative = (error - prevError);

        return {kp * error + kd * derivative, error};
    }
}

namespace game{
    void pull_up(int y_target){
        int best_angle, best_power;
        double smallest_u = 1e9 + 7, smallest_error = 1e9 + 7;

        for(int angle = max(-90, angle_rocket - 15); angle < min(90, angle_rocket + 15); angle++){
            for(int power = max(0, power_rocket - 1); power < min(4, power_rocket + 1); power++){
                auto [u, error] = simulate::pid_vertical(angle, power, y_target);

                if(u < smallest_u){
                    smallest_error = error;
                    smallest_u = u;
                    best_angle = angle;
                    best_power = power;
                }
            }
        }

        prevError == smallest_error;
        cout << best_angle << ' ' << best_power << endl;
    }

    void make_move(){
        int save_altitude = compute_save_altitude();
        if(h_speed_rocket == 0 and x_rocket == landing_spot.x){ // we can descent
            pull_up(save_altitude);
        } else {
            
            if(y_rocket + 50 < save_altitude){ // pull up! pull up! pull up!
                pull_up(save_altitude);
            } else{
                pull_up(save_altitude);
            }
        }
    }

    void init(){
        cin >> n;
        for(int i = 0; i < n; i++){ 
            cin >> mars[i].x >> mars[i].y;
            if(debug) cerr << mars[i].x << ' ' << mars[i].y << endl;
        }

        landing_spot = find_landing_spot();
    }

    void get_input(){
        cin >> x_rocket >> y_rocket >> h_speed_rocket >> v_speed_rocket >> fuel_rocket >> angle_rocket >> power_rocket;
        if(debug) cerr << x_rocket << ' ' << y_rocket << h_speed_rocket << v_speed_rocket << fuel_rocket << angle_rocket << power_rocket;
        tajm++;
    }

    int compute_save_altitude(){
        int alt = landing_spot.y + 100;
        for(int i = x_rocket; i <= landing_spot.x; i += (x_rocket < landing_spot.x ? 1 : -1)){
            alt = max(alt, mars[i].y + 100); 
        }

        return alt;
    }

    coord find_landing_spot(){
        int l = -1, r = -1;
        for(int i = 3; i + 3 < n; i++){
            if(mars[i].y == mars[i + 1].y and mars[i + 1].y == mars[i + 2].y){ // it's landing zone
                if(l == -1) l = i;
                r = i;
            }
        }

        int idx = (r + l) / 2;
        return {mars[idx].x, mars[idx].y};
    } 
}
