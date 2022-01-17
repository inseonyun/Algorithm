#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, test_case, N, M, K;

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M >> K;

		vector<int> person;
		int flag = 0;

		for (int i = 0; i < N; i++) {
			int p;
			cin >> p;
			person.push_back(p);
		}

		sort(person.begin(), person.end());

		for (int i = 0; i < N; i++) {
			if (K * (person[i] / M) < i + 1) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			cout << "#" << test_case << " Possible\n";
		}
		else {
			cout << "#" << test_case << " Impossible\n";
		}
		
	}


	return 0;
}