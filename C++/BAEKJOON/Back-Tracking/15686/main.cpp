#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

struct coor {
    int x;
    int y;
};

int N, M, res = INT_MAX;
int map[51][51];
bool selected[13];
vector<coor> chicken, home, v;

void init() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                home.push_back({i, j});
            } else if (map[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }
}

int calc_dist() {
    int sum = 0;
    
    for (int i = 0; i < home.size(); i++) {
        int h_x = home[i].x;
        int h_y = home[i].y;
        int d = INT_MAX;
        
        for (int j = 0; j < v.size(); j++) {
            int v_x = v[j].x;
            int v_y = v[j].y;
            int dist = abs(h_x - v_x) + abs(h_y - v_y);
            
            d = min(d, dist);
        }
        sum += d;
    }
    return sum;
}

void close_chicken(int idx, int cnt) {
    if (cnt == M) {
        res = min(res, calc_dist());
        return;
    }
    
    for (int i = idx; i < chicken.size(); i++) {
        if (selected[i]) continue;
        selected[i] = true;
        v.push_back(chicken[i]);
        close_chicken(i, cnt + 1);
        selected[i] = false;
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    close_chicken(0, 0);
    cout << res << "\n";
    
    return 0;
}
