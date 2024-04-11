#include<iostream>
#include<vector>

using namespace std;

vector<int> score_cnt;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int num;
        cin >> num;
        score_cnt = vector<int>(101, 0);

        for (int i = 0; i < 1000; i++) {
            int score;
            cin >> score;
            
            score_cnt[score]++;
        }

        int max_val = 0;
        int tmp = 0;
        for (int i = 0; i < 101; i++) {
            if (score_cnt[i] >= tmp) {
                tmp = score_cnt[i];
                max_val = i;
            }
        }

        cout << "#" << num << " " << max_val << "\n";
    }
    return 0;
}
