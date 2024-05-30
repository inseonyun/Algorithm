#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 10^14 범위로 long 타입
    long left, right;
    cin >> left >> right;

    // 제곱근 10^7 사이즈 선언
    long v[10000001];
    for (int i = 2; i <= 10000000; i++) {
        v[i] = i;
    }
    
    for (int i = 2; i <= sqrt(10000001); i++) {
        if (v[i] == 0) continue;
        for (int j = i * 2; j <= 10000000; j += i) {
            v[j] = 0;
        }
    }
    
    int ans = 0;
    for (int i = 2; i <= 10000000; i++) {
        if (v[i] != 0) {
            long tmp = v[i];
            
            while ((double) v[i] <= (double) right / (double) tmp) {
                if ((double) v[i] >= (double) left / (double) tmp) ans += 1;
                tmp *= v[i];
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
