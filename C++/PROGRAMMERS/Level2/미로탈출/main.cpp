#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct coor {
    int x;
    int y;
};

int N, M;
bool isArrivedLever = false;
coor startPoint, endPoint, leverPoint;
vector<vector<int>> dp(100, vector<int>(100, INT_MAX));
vector<vector<bool>> checked(100, vector<bool>(100, false));
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void init(vector<string> maps) {
    N = maps.size();
    M = maps[0].length();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maps[i][j] == 'S')
                startPoint = {i, j};
            else if (maps[i][j] == 'L')
                leverPoint = {i, j};
            else if (maps[i][j] == 'E')
                endPoint = {i, j};
        }
    }
}

void bfs(vector<string> maps, coor start) {
    queue<coor> q;
    q.push(start);
    checked[start.x][start.y] = true;
    dp[start.x][start.y] = 0;
    
    while(!q.empty()) {
        int xx = q.front().x;
        int yy = q.front().y;
        int now = dp[xx][yy];
        
        q.pop();
        
        if (xx == leverPoint.x && yy == leverPoint.y) {
            q = queue<coor>();
            dp = vector<vector<int>>(100, vector<int>(100, INT_MAX));
            dp[xx][yy] = now;
            checked = vector<vector<bool>>(100, vector<bool>(100, false));
            checked[xx][yy] = true;
            isArrivedLever = true;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int nc = now + 1;
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (maps[nx][ny] != 'X' && !checked[nx][ny]) {
                    dp[nx][ny] = min(dp[nx][ny], nc);
                    checked[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    
    init(maps);
    
    bfs(maps, startPoint);
    
    answer = (dp[endPoint.x][endPoint.y] == INT_MAX) ? -1 : dp[endPoint.x][endPoint.y];
    if (!isArrivedLever) answer= -1;
    
    return answer;
}
