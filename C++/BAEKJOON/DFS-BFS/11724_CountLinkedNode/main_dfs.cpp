#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(1001);
bool checked[1001] = {false, };

void dfs(int c) {
    if (checked[c]) return;
    checked[c] = true;
    
    for (int value : v[c]) {
        if (!checked[value])
            dfs(value);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    int res = 0;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++) {
        if (!checked[i]) {
            res++;
            dfs(i);
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
