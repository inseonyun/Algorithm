#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> times(N);
    for (int i = 0; i < N; i++) {
        cin >> times[i].first >> times[i].second;
    }
    
    sort(times.begin(), times.end(), cmp);
    
    int ans = 0;
    int endTime = -1;
    for (int i = 0; i < N; i++) {
        int startTime = times[i].first;
        
        if (startTime >= endTime) {
            endTime = times[i].second;
            ans += 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
