
//////////////////////////////////////////////////
// BAEKJOON_1931번: 회의실 배정
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void assignCR() {
	int N;
	cin >> N;

	vector<pair<int, int>> vec;

	for (int i = 0; i < N; i++) {
		int startTime, endTime;
		cin >> startTime >> endTime;
		
		vec.push_back(make_pair(endTime, startTime));
	}

	sort(vec.begin(), vec.end());

	int ans = 1;
	int lastFinishedTime = vec[0].first;

	for (int i = 1; i < vec.size(); i++) {
		int startTime = vec[i].second;
		
		if (lastFinishedTime > startTime)
			continue;

		lastFinishedTime = vec[i].first;
		ans++;
	}
	cout << ans;
}

int main() {
    assignCR();
    
    return 0;
}