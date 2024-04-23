#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct coor {
    int x;
    int y;
};

int n, m, answer = INT_MAX;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
coor start, goal;
vector<string> map;
bool checked[100][100] = {false, };

void bfs() {
    queue<pair<coor, int>> q;
    q.push({start, 0});
    checked[start.x][start.y] = true;
    
    while(!q.empty()) {
        int xx = q.front().first.x;
        int yy = q.front().first.y;
        int cur = q.front().second;
        
        q.pop();
        
        if (xx == goal.x && yy == goal.y) {
            answer = min(answer, cur);
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if ((nx < 0 || ny < 0 || nx >= n || ny >= m) || map[nx][ny] == 'D') continue;
            
            while (true) {
                nx += dx[i];
                ny += dy[i];
                
                if ((nx < 0 || n <= nx || ny < 0 || m <= ny) || map[nx][ny] == 'D') {
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }
            
            if (checked[nx][ny]) continue;
            coor next = {nx, ny};
            
            q.push({next, cur + 1});
            checked[nx][ny] = true;
        }
    }
}

int solution(vector<string> board) {
    map = board;
    n = map.size();
    m = map[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'R')
                start = {i, j};
            else if (map[i][j] == 'G')
                goal = {i, j};
        }
    }
    
    bfs();
    
    if (answer == INT_MAX) return -1;
    
    return answer;
}
