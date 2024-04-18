#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int max_health = health;
    int time = bandage[0];
    int hp_per_sec = bandage[1];
    int benefit_hp = bandage[2];
    
    int last_attack_time = attacks[attacks.size() - 1][0];
    
    int attack_idx = 0;
    int consecutively = 0;
    for (int i = 0; i <= last_attack_time; i++) {
        if (i == attacks[attack_idx][0]) {
            health -= attacks[attack_idx][1];
            attack_idx++;
            consecutively = 0;
            
            if (health <= 0)
                return -1;
        } else {
            consecutively++;
            if (max_health > health) {
                health = min(max_health, health + hp_per_sec);
                
                if (consecutively == time) {
                    health = min(max_health, health + benefit_hp);
                    consecutively = 0;
                }
            }
        }
    }
    
    if (health <= 0) 
        health = -1;
    
    return health;
}
