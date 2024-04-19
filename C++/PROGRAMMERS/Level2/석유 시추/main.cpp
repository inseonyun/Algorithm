#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, 0, -1 };  // 하, 우, 좌, 상
int dy[4] = { 0, 1, -1, 0 };
bool checked[500][500] = {false, };
vector<vector<int>> map;

struct grouping {
    int cnt;
    set<int> y;
};
vector<grouping> v;

grouping bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    checked[start.first][start.second] = true;
    
    set<int> y;
    y.insert(start.second);
    
    int row_size = map.size(), col_size = map[0].size();
    int res = 1;
    
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < row_size && ny < col_size) {
                if (checked[nx][ny] == false && map[nx][ny] == 1) {
                    y.insert(ny);
                    res++;
                    checked[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
    
    return {res, y};
}

int solution(vector<vector<int>> land) {
    map = land;
    int answer[501] = {0};
    int maxNum = 0;
    int row_size = land.size();
    int col_size = land[0].size();
    
    for (int col = 0; col < col_size; col++) {
        for (int row = 0; row < row_size; row++) {
            if (checked[row][col] == false && map[row][col] == 1) {
                v.push_back(bfs({ row, col }));
            }
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        for(auto it : v[i].y) {
            answer[it] += v[i].cnt;
            maxNum = max(maxNum, answer[it]);
        }
    }
    
    return maxNum;
}
