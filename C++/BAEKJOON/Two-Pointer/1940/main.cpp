#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int arr[15000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    long long count = 0;
    int start_index = 0;
    int end_index = N - 1;
    while (start_index < end_index) {
        long long sum = arr[start_index] + arr[end_index];
        if (sum < M) {
            start_index++;
        }
        else if (sum > M) {
            end_index--;
        }
        else {
            count++;
            start_index++;
            end_index--;
        }
    }

    cout << count << "\n";
    return 0;
}
