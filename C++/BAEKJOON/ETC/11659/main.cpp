#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int data_count, test_case;
    cin >> data_count >> test_case;
    
    int arr[100001] = {0,};
    int sum[100001] = {0, };
    for ( int i = 1; i <= data_count; i++) {
        cin >> arr[i];
        
        sum[i] = sum[i - 1] + arr[i];
    }
    
    for (int tc = 1; tc <= test_case; tc++) {
        int start, end;
        cin >> start >> end;
        
        if (start == end)
            cout << arr[start] << "\n";
        else
            cout << sum[end] - sum[start - 1] << "\n";
    }
    
    return 0;
}
