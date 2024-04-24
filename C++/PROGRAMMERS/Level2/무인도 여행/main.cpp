#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool checked[100][100] = {false,};
struct coor {
    int x;
    int y;
};
int bfs(vector<string> maps, coor c) {
    queue<coor> q;
    q.push(c);
    checked[c.x][c.y] = true;
    
    int res = 0;
    while(!q.empty()) {
        int xx = q.front().x;
        int yy = q.front().y;
        
        q.pop();
        
        res += maps[xx][yy] - '0';
        
        for (int i = 0; i < 4; i ++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (checked[nx][ny] == false && maps[nx][ny] != 'X') {
                    q.push({nx, ny});
                    checked[nx][ny] = true;
                }
            }
        }
    }
    
    return res;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    n = maps.size();
    m = maps[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] != 'X' && checked[i][j] == false) {
                int val = bfs(maps, {i, j});
                answer.push_back(val);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.empty() == true) 
        answer.push_back(-1);
    
    return answer;
}
