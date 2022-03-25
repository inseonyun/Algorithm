
//////////////////////////////////////////////////
// PROGRAMMERS : 최대공약수 최소공배수
//////////////////////////////////////////////////

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int tmp;
    int nNum = n;
    int mNum = m;
    while(mNum != 0) {
        tmp = nNum % mNum;
        nNum = mNum;
        mNum = tmp;
    }
    answer.push_back(nNum);
    answer.push_back(n * m / nNum);

    return answer;
}
