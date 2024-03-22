#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	long long arr[2000];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int count = 0;

	for (int i = 0; i < N; i++) {
		long long target = arr[i];
		int start_index = 0;
		int end_index = N - 1;

		while (start_index < end_index) {
			long long sum = arr[start_index] + arr[end_index];

			if (sum > target) {
				end_index--;
			}
			else if (sum < target) {
				start_index++;
			}
			else {
				if (start_index != i && end_index != i) {
					count++;
					break;
				}
				else if (start_index == i) {
					start_index++;
				}
				else if (end_index == i) {
					end_index--;
				}
			}
		}
	}

	cout << count << "\n";
	return 0;
}
