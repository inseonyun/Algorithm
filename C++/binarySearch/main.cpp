#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int bs(vector<int> v, int target) {
	int low = 0;
	int high = v.size() - 1;
	int mid;

	while (low <= high) {
		mid = low + (high - low) / 2;

		if (v[mid] == target) 
			return mid;
		else if (v[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, tmp;
	
	cin >> N;

	vector<int> v;
	vector<int> v2;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < M; i++) {
		if (bs(v, v2[i]) == -1)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}

	
	return 0;
}