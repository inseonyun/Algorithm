#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    stringstream ss;
    ss.str(s);
    
    string n;
    int ans = 0;
    int idx = 0;
    while (getline(ss, n, '-')) {
        stringstream tmps;
        tmps.str(n);
        string tmp;
        if (idx >= 1) {
            while (getline(tmps, tmp, '+')) {
                ans -= stoi(tmp);
            }
        } else {
            while (getline(tmps, tmp, '+')) {
                ans += stoi(tmp);
            }
        }
        idx += 1;
    }
    
    cout << ans << "\n";
    
    return 0;
}
