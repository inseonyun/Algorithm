#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    int start = -1, end = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        start = max(start, arr[i]);
        end += arr[i];
    }
    
    while (start <= end) {
        int middle = (start + end) / 2;
        int sum = 0;
        int count = 0;
        
        for (int i = 0; i < N; i++) {
            if (sum + arr[i] > middle) {
                count++;
                sum = 0;
            }
            sum += arr[i];
        }
        if (sum != 0) count++;
        if (count > M) start = middle + 1;
        else end = middle - 1;
    } 
    cout << start << "\n";
    
    return 0;
}
