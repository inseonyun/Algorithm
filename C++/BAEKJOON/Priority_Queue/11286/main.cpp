#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, cmp> pq;
    queue<int> res;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                res.push(0);
            } else {
                res.push(pq.top());
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
    
    while(!res.empty()) {
        cout << res.front() << "\n";
        res.pop();
    }
    
    return 0;
}
