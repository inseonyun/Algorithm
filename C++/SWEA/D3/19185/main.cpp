#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
int N, M, Q;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M;
 
        vector<string> s;
        vector<string> t;
        vector<string> res;
 
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            s.push_back(str);
        }
        for (int i = 0; i < M; i++) {
            string str;
            cin >> str;
            t.push_back(str);
        }
 
        cin >> Q;
 
        for (int i = 0; i < Q; i++) {
            int Y;
            cin >> Y;
 
            int s_idx = (Y % N - 1 < 0) ? N - 1 : Y % N - 1;
            int t_idx = (Y % M - 1 < 0) ? M - 1 : Y % M - 1;
 
            res.push_back(s[s_idx] + t[t_idx]);
        }
 
 
        cout << "#" << test_case << " ";
 
        for (string s : res) {
            cout << s << " ";
        }
        cout << "\n";
 
    }
    return 0;
}
