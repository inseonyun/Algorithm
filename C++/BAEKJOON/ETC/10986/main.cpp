
/*
  https://www.acmicpc.net/problem/10986
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<long> sum(N, 0);
    vector<long> combi(M, 0);
    
    cin >> sum[0];
    
    for (int i = 1 ; i < N; i++) {
        long num;
        cin >> num;
        
        sum[i] = sum[i - 1] + num;
    }
    
    long res = 0;
    for (int i = 0; i < N; i++) {
        long remainder = sum[i] % M;
        
        if (remainder == 0) {
            res++;
        }
        combi[remainder]++;
    }
    
    for (int i = 0; i < M; i++) {
        if (combi[i] > 1) {
            res = res + (combi[i] * (combi[i] - 1) / 2);
        }
    }
    
    cout << res << "\n";
    
    return 0;
}
