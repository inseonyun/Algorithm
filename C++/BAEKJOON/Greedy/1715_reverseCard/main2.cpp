#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<>> pq;
    long long res = 0;
    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;
        pq.push(card);
    }
    
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        res += (a + b);
    }
    
    cout << res << "\n";
    
    return 0;
}
