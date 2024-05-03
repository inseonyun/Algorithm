#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> v(1001);
bool checked[10001] = {false, };

void dfs(int start) {
    checked[start] = true;
    cout << start << " ";
    
    for (int i : v[start]) {
        if (!checked[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    checked[start] = true;
    
    while(!q.empty()) {
        int e = q.front();
        q.pop();
        
        cout << e << " ";
        
        for (int i : v[e]) {
            if(!checked[i]) {
                checked[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    dfs(V);
    cout << "\n";
    memset(checked, false, sizeof(checked));
    bfs(V);
    cout << "\n";
   
    
    return 0;
}
