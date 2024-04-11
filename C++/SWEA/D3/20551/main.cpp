#include<iostream>
#include<math.h>
 
using namespace std;
 
void calc(int &post, int &prev, int &res) {
 
    if (prev > post) {
        int tmp = abs(post - prev) + 1;
        res += tmp;
        prev = prev - tmp;
    }
    else if (prev == post) {
        prev--;
        res++;
    }
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int A, B, C;
        cin >> A >> B >> C;
 
        bool isPossible = false;
        int res = 0;
 
        if (A < B && B < C) {
            cout << "#" << test_case << " " << res << "\n";
            continue;
        }
         
        calc(C, B, res);
        calc(B, A, res);
 
        if (A > 0 && B > 0 && C > 0)
            isPossible = true;
 
        if (isPossible) {
            cout << "#" << test_case << " " << res << "\n";
        }
        else {
            cout << "#" << test_case << " " << -1 << "\n";
        }
    }
    return 0;
}
