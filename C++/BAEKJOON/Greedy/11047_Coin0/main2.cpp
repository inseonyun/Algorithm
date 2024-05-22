#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    int dong[N];
    for (int i = 0; i < N; i++) {
        cin >> dong[i];
    }
    
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break;
        if (K / dong[i] == 0) continue;
        cnt += K / dong[i];
        K = K % dong[i];
    }
    cout << cnt << "\n";
    
    return 0;
}
