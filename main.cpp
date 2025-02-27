#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>

#include "Utils.cpp"

using namespace std::chrono_literals;

std::mutex game_mutex;

void printer(Game& g){
    std::chrono::milliseconds time4sleep;//todo calculate
    bool prinnted = false;
    while(!g.game_over){
        prinnted = false;
        game_mutex.lock();
        print_field(g.field);
        prinnted = true;
        game_mutex.unlock();
        if(prinnted){
            std::this_thread::sleep_for(time4sleep);  
        }
    }
}
void key_listner(Game& g){
//getkeystate
    while(!g.game_over){
        if(strelka_vpravo()){
            game_mutex.lock();
            g.field.poe.v_x = g.field.poe.max_speed;
            game_mutex.unlock();
        }else if(strelka_vlevo){
            game_mutex.lock();
            g.field.poe.v_x = -g.field.poe.max_speed;
            game_mutex.unlock();
        }else{
            game_mutex.lock();
            g.field.poe.v_x = 0;
            game_mutex.unlock();
        }
    }
}
void updater(Game& g){
    std::chrono::milliseconds time4sleep;//todo calculate
    bool updated = false;
    while(!g.game_over){
        updated = false;
        game_mutex.lock();
        update_field(g);
        updated = true;
        game_mutex.unlock();
        if(updated){
            std::this_thread::sleep_for(time4sleep);  
        }
    }
}
int main(){

    return 0;
}