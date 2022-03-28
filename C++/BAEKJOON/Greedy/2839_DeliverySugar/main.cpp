
//////////////////////////////////////////////////
// BAEKJOON_2839번: 설탕 배달
//////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
	int N, result = 0;
	cin >> N;

	while (N >= 0) {
		if (N % 5 == 0) {
			result += N / 5;
			cout << result << "\n";
			return 0;
		}
		N -= 3;
		result++;
	}
	cout << "-1\n";

	return 0;
}