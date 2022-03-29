
//////////////////////////////////////////////////
// BAEKJOON_1946번: 신입 사원
//////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void newRecruit() {
	int T;
	cin >> T;
	vector <int> output;
	for (int TC = 0; TC < T; TC++) {
		int N;
		cin >> N;

		vector<pair<int, int>> score;
		for (int n = 0; n < N; n++) {
			int a, b;
			cin >> a >> b;
			score.push_back(make_pair(a, b));
		}

		sort(score.begin(), score.end());

		int max = score[0].second;
		int result = 1;
		for (int i = 1; i < N; i++) {
			if (max > score[i].second) {
				max = score[i].second;
				result++;
			}
		}

		output.push_back(result);
	}
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << "\n";
	}
}

int main() {
    newRecruit();
    
    return 0;
}