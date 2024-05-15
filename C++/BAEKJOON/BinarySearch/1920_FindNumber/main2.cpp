#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int N;
int search(int target) {
    int start = 0, end = N - 1;
    
    while (start <= end) {
        int middle_idx = (start + end) / 2;
        int middle_value = arr[middle_idx];
        
        if (middle_value == target)
            return 1;
        else if (middle_value > target) {
            end = middle_idx - 1;
        } else {
            start = middle_idx + 1;
        }
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        
        cout << search(num) << "\n";
    }
    
    return 0;
}
