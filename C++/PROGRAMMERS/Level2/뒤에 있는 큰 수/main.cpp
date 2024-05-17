#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isBigger(int a, int b) {
    return a < b;
}

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, 0);
    stack<int> s;
    
    for (int i = n - 1; i >= 0; i--) {
        while (true) {
            if (s.empty()) {
                answer[i] = -1;
                break;
            } 
            if (s.top() > numbers[i]) {
                answer[i] = s.top();
                break;
            }
            s.pop();
        }
        s.push(numbers[i]);
    }
    
    return answer;
}
