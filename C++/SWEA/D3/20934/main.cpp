#include <iostream>
#include <cstring>

using namespace std;

void swap_bell(string &s) {
    int bell_idx = s.find('o');
    
    switch(bell_idx) {
        case 0:
            s[1] = 'o';
            s[0] = '.';
            break;
        case 1:
            s[0] = 'o';
            s[1] = '.';
            break;
        case 2:
            s[1] = 'o';
            s[0] = '.';
            break;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        int k;
        cin >> s >> k;
        for (int i = 0; i < k; i++) {
            int idx = s.find('o');
            
            swap_bell(s);
        }
        int res = s.find('o');
        cout << "#" << test_case << " " << res << "\n";
    }
    return 0;
}
