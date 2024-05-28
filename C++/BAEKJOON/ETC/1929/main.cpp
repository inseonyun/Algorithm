#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M, N;
    cin >> M >> N;
    vector<int> v(N + 1);
    for (int i = 2; i <= N; i++) {
        v[i] = i;
    }
    
    // 에라토스테네스의 체 이용
    for (int i = 2; i <= sqrt(N); i++) {
        if (v[i] == 0) continue; // 지워진 수는 넘어감
        
        // 배수 지움
        for (int j = i * 2; j <= N; j += i) {
            v[j] = 0;
        }
    }
    
    for (int i = M; i <= N; i++) {
        if (v[i] != 0)
            cout << v[i] << "\n";
    }
    
    return 0;
}
