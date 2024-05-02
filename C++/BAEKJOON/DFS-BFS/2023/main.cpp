#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    
    return true;
}

void dfs(int num, int jarisu) {
    if (jarisu == N) {
        if (isPrime(num))
            cout << num << "\n";
        return;
    }
    
    for (int i = 1; i <= 9; i++) {
        if (i % 2 == 0)
            continue;
        if (isPrime(num * 10 + i))
            dfs(num * 10 + i, jarisu + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    // 소수 dfs 돌림
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
    
    return 0;
}
