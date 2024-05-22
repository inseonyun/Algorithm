#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, less<>> positive_pq;
    priority_queue<int, vector<int>, greater<>> negative_pq;
    int one = 0;
    bool hasZero = false;
    
    for (int i = 0; i < N; i ++) {
        int num;
        cin >> num;
        if (num > 1) {
            positive_pq.push(num);
        } else if (num == 1) {
            one += 1;
        } else if (num < 0) {
            negative_pq.push(num);
        } else {
            hasZero = true;
        }
    }
    
    int res = 0;
    
    while(positive_pq.size() > 1) {
        int a = positive_pq.top();
        positive_pq.pop();
        int b = positive_pq.top();
        positive_pq.pop();
        res += a * b;
    }
    if (!positive_pq.empty()) {
        res += positive_pq.top();
    }
    
    while(negative_pq.size() > 1) {
        int a = negative_pq.top();
        negative_pq.pop();
        int b = negative_pq.top();
        negative_pq.pop();
        res += a * b;
    }
    if (!negative_pq.empty()) {
        if (!hasZero) {
            res += negative_pq.top();
        }
    }

    res += one;
    
    cout << res << "\n";
    
    return 0;
}
