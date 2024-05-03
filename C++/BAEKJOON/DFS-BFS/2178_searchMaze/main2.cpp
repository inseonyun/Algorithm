#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> v(100, vector<int>(100));
bool checked[100][100] = {false,};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dp[100][100] = {0,};

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    checked[start.first][start.second] = true;
    dp[start.first][start.second] = 1;
    
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        int cc = dp[xx][yy];
        
        if (xx == N - 1 && yy == M - 1) break;
        
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int nc = cc + 1;
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (!checked[nx][ny] && v[nx][ny] == 1) {
                    checked[nx][ny] = true;
                    dp[nx][ny] = nc;
                    
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &v[i][j]);
        }
    }
    
    bfs({0, 0});
    cout << dp[N - 1][M - 1] << "\n";
    
    return 0;
}
