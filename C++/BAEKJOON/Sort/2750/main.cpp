/*
https://www.acmicpc.net/problem/2750
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    vector<int> v;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());

    for (int num : v) {
        cout << num << "\n";
    }
    
    return 0;
}
