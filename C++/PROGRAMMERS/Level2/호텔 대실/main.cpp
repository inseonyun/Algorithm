#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMinOfTime(string time) {
    int res;
    
    string hour = time.substr(0, time.find(":"));
    string min = time.substr(time.find(":") + 1, time.length());
    res = stoi(hour) * 60 + stoi(min);
    
    return res;
} 

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int n = book_time.size();
    
    vector<pair<int, int>> times;
    vector<int> rooms;
    
    for (int i = 0; i < n; i++) {
        int start_time = getMinOfTime(book_time[i][0]);
        int end_time = getMinOfTime(book_time[i][1]);
        
        times.push_back({start_time, end_time});
    }
    
    sort(times.begin(), times.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            answer += 1;
            rooms.push_back(times[i].second);
            continue;
        }
        
        int now_start_time = times[i].first;
        int now_end_time = times[i].second;
        bool isBook = false;
        for (int j = 0; j < rooms.size(); j++) {
            if (now_start_time >= rooms[j] + 10) {
                isBook = true;
                rooms[j] = now_end_time;
                break;
            }
        }
        if (!isBook) {
            answer += 1;
            rooms.push_back(now_end_time);
        }
    }
    
    return answer;
}
