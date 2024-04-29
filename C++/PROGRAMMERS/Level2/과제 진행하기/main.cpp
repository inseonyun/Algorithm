#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, int>> stop;

int getTimeOfMin(string str) {
    int idx_colon = str.find(":");
    string hour = str.substr(0, idx_colon);
    string min = str.substr(idx_colon + 1, str.length());
    
    return stoi(hour) * 60 + stoi(min);
}

bool cmp(vector<string> a, vector<string> b) {
    return getTimeOfMin(a[1]) < getTimeOfMin(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), cmp);
    int now = 0;
    
    for(vector<string> plan : plans){
        int time = getTimeOfMin(plan[1]);
        
        while(now < time) {
            if(!stop.empty()){
                stop.back().second--;
                if(stop.back().second == 0){
                    answer.push_back(stop.back().first);
                    stop.pop_back();
                }
            }
            now++;
        }  
        
        stop.push_back({plan[0], stoi(plan[2])});
    }
    
    while(!stop.empty()){
        answer.push_back(stop.back().first);
        stop.pop_back();
    }
    
    return answer;
}
