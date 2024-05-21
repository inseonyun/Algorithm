#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long N, K;
    cin >> N >> K;
    
    long long start = 1, end = K;
    long long res = 0;
    
    while (start <= end) {
        long long middle = (start + end) / 2;
        long long cnt = 0;

        // 중앙값보다 작은 수 카운팅
        for (int i = 1; i <= N; i++) {
            cnt += min(middle / i, N); // 중앙 인덱스를 i로 나눈 값과 N 중 작은 값 더해 나감
        }
        
        if (cnt < K) {
            // 중앙값보다 작은 수의 개수가 K보다 적으므로 시작 인덱스 조정
            start = middle + 1;
        } else {
            // 같을 경우를 대비해 res에 middle 저장, 클 경우에 대비해 end에 중앙값 -1 인덱스 조정
            res = middle;
            end = middle - 1;
        }
    }
    cout << res << "\n";
    
    return 0;
}
