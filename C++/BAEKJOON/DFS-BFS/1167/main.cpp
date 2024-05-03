#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
    int e;
    int d;
};

int V;
vector<vector<edge>> tree(100001);
vector<bool> checked(100001, false);
vector<int> dp(100001);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    checked[start] = true;
    while(!q.empty()) {
        int e = q.front();
        
        q.pop();
        
        for (edge i : tree[e]) {
            if (!checked[i.e]) {
                dp[i.e] = dp[e] + i.d;
                
                checked[i.e] = true;
                q.push(i.e);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> V;
    tree.resize(V + 1);
    dp.resize(V + 1);
    checked.resize(V + 1);
    
    
    for (int i = 0; i < V; i++) {
        int e;
        cin >> e;
        while(true) {
            int e2, d;
            cin >> e2;
            if (e2 == -1) break;
            cin >> d;
            tree[e].push_back({e2, d});
        }
    }
    bfs(1);
    int MAX = 1;
    for (int i = 2; i <= V; i++) {
        if (dp[MAX] < dp[i]) {
            MAX = i;
        }
    }
    
    fill(checked.begin(), checked.end(), false);
    fill(dp.begin(), dp.end(), 0);
    bfs(MAX);
    
    sort(dp.begin(), dp.end());
    
    cout << dp[V] << "\n";
    
    return 0;
}
