
//////////////////////////////////////////////////
// SWEA_9088. 다이아몬드_D4
//////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void diamond() {
	int TC;
	cin >> TC;

	int result[10] = { 0, };

	for (int test_case = 0; test_case < TC; test_case++) {
		int N, K;
		cin >> N >> K;

		vector<int> vec;

		for (int i = 0; i < N; i++) {
			int size;
			cin >> size;

			vec.push_back(size);
		}

		sort(vec.begin(), vec.end());
		int l = 0, r = 0, ans = 0;
		while (r < N && l <= r) {
			if (vec[r] - vec[l] > K) 
				l++;
			else 
				ans = max(r++ - l + 1, ans);
		}
		result[test_case] = ans;
	}
	for (int i = 0; i < TC; i++) {
		cout << "#" << i + 1 << " " << result[i] << "\n";
	}
}
int main() {
	diamond();
    
    return 0;
}
