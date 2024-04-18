#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map<string, int> m;
    
    int n = name.size();
    for(int i = 0; i < n; i++) {
        m[name[i]] = yearning[i];
    }
    
    for(vector<string> p : photo) {
        int res = 0;
        for (string s : p) {
            res += m[s];
        }
        answer.push_back(res);
    }
    
    return answer;
}
