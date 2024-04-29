#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size();
    
    int start = 0, end = 0;
    long long sum = sequence[end];
    while (start <= end && end < n) {
        if (sum < k) sum += sequence[++end];
        else if (sum == k) {
            if (answer.empty()) {
                answer.push_back(start);
                answer.push_back(end);
            } else if (end - start < answer[1] - answer[0]) {
                answer[0] = start;
                answer[1] = end;
            } else if (end - start == answer[1] - answer[0] && start < answer[0]) {
                answer[0] = start;
                answer[1] = end;
            } 
            sum -= sequence[start];
            start++;
        } else {
            sum -= sequence[start++];
        }
    }
    
    return answer;
}
