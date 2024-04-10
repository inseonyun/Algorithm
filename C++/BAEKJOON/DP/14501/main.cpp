#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Boj14501 {
	struct advice {
		int time;
		int pay;
	};

	int N;
	vector<advice> v = vector<advice>(16, { 0, 0 });
	vector<int> dp = vector<int>(16, 0);

public:
	void input() {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			int time, pay;
			cin >> time >> pay;

			v[i].time = time;
			v[i].pay = pay;
		}
	}

	void solution() {
		for (int i = N; i > 0; i--) {
			int deadline_idx = v[i].time + i;

			if (deadline_idx > N + 1) {
				dp[i] = dp[i + 1];
			}
			else {
				dp[i] = max(dp[i + 1], v[i].pay + dp[deadline_idx]);
			}
		}
	}

	void output() {
		cout << dp[1] << "\n";
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Boj14501 b = Boj14501();

	b.input();
	b.solution();
	b.output();

  return 0;
}
