
//////////////////////////////////////////////////
// BAEKJOON_1920번: 수 찾기
//////////////////////////////////////////////////

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, tmp;
int arr[100001];

void inputData() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}
	sort(arr, arr + N);

	cin >> M;
}

void BinarySearch(int target) {
	int low = 0;
	int high = N - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] == target) {
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << 0 << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	inputData();

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		BinarySearch(tmp);
	}

	return 0;
}