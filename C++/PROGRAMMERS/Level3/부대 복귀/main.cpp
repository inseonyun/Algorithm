#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// 함수에서 배열을 넘길 때 값이 바뀌는걸 원하지 않는 경우를 제외하곤
// 주소 참조 &를 꼭 쓰자.. 시간 초과가 날 수 있다.
int bfs(vector<vector<int>> &v, int start, int destination) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    
    bool checked[100001] = {false, };
    checked[start] = true;
    
    int res = INT_MAX;
    
    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
 
        q.pop();
        
        if (now == destination) {
            res = min(res, cnt);
        }
        
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            
            if (!checked[next]) {
                checked[next] = true;
                q.push({ next, cnt + 1 });
            }
        }
    }
    return res == INT_MAX ? -1 : res;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> v(n + 1);
    
    for (int i = 0; i < roads.size(); i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 0; i < sources.size(); i++) {
        int res = bfs(v, sources[i], destination);
        answer.push_back(res);
    }
    
    return answer;
}
