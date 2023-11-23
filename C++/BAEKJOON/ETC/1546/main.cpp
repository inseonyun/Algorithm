/*
  https://www.acmicpc.net/problem/1546
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    int max_score = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        max_score = max(max_score, num);
        sum += num;
    }
    
    double res = sum * 100.0 / max_score / N;
    cout << res << "\n";
    
    return 0;
}
