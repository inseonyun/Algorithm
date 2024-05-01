#include<iostream>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    queue<int> q;
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    while(q.size() != 1) {
        q.pop(); // 카드 버림
        
        int num = q.front(); // 그 다음 카드 뽑아서 맨 뒤로 넣음
        q.pop();
        q.push(num);
    }
    
    cout << q.front() << "\n";
    
    
    return 0;
}
