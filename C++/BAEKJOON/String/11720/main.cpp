/*
https://www.acmicpc.net/problem/11720
*/

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int sum = 0;
    string number;
    cin >> number;
    
    for (char ch : number) {
        sum += ch - '0';
    }
    
    cout << sum;
    
    return 0;
}
