
//////////////////////////////////////////////////
// BAEKJOON: 9372_상근이의 여행
//////////////////////////////////////////////////

#include <iostream>

using namespace std;

int N, M, test_case;

void input() {
	cin >> test_case;

	for (int tc = 0; tc < test_case; tc++) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
		}

		cout << N - 1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	return 0;
}