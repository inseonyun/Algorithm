#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    int gn = gifts.size();
    
    map<string, int> f_idx;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<int> g(n, 0);
    
    // init
    for (int i = 0; i < n; i++) {
        f_idx[friends[i]] = i;
    }
    
    for (int i = 0; i < gn; i++) {
        int space_idx = gifts[i].find(' ');
        string a = gifts[i].substr(0, space_idx);
        string b = gifts[i].substr(space_idx + 1, gifts[i].length());
        
        v[f_idx[a]][f_idx[b]]++;
        g[f_idx[a]]++;
        g[f_idx[b]]--;
    }
    
    for(int i = 0; i < n; i++){
        int ret = 0;
        for(int j = 0; j < n; j++){
            if(i==j) continue;
            if(v[i][j] > v[j][i])
                ret++;
            if(v[i][j] == v[j][i]){
                if(g[i] > g[j])
                    ret++;
            }
        }
        answer = max(answer, ret);
    }
    
    return answer;
}
