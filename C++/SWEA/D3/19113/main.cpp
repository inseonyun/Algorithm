#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int N;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
 
        vector<int> pi(2 * N, 0);
        vector<int> res;
        for (int i = 0; i < 2 * N; i++) {
            cin >> pi[i];
        }
 
        for (int i = 0; i < 2 * N; i++) {
            // x * 0.75 = 할인가
            // x = 할인가 / 0.75
            if (i >= pi.size()) break;
            int target = pi[i] / 0.75;
             
            auto ad_target = find(pi.begin(), pi.end(), target);
            if (ad_target != pi.end()) {
                // 존재함, 이미 오름차순으로 되있어서 정렬 필요 없음
                res.push_back(pi[i]);
 
                pi.erase(ad_target);
            }
        }
 
        cout << "#" << test_case << " ";
 
        for (int price : res) {
            cout << price << " ";
        }
        cout << "\n";
    }
    return 0;
}
