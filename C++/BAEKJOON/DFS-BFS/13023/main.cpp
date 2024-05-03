#include <iostream>
#include <vector>

using namespace std;

int N, M, res = 0;
vector<vector<int>> v(2000);
bool visited[2000] = {false, };

void dfs(int e, int depth) {
    if (depth == 5 || res == 1) {
        res = 1;
        return;
    }
    
    visited[e] = true;
    for (int i : v[e]) {
        if (!visited[i]) {
            dfs(i, depth + 1);
        }
    }
    visited[e] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 0; i < N; i++) {
        dfs(i, 1);
    }
    
    cout << res << "\n";
    
    return 0;
}
