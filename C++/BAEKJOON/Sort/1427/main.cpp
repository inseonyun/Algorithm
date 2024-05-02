#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        int tmp = str[i] - '0';
        int idx = -1;
        for (int j = i + 1; j < str.length(); j++) {
            if (tmp < str[j] - '0') {
                tmp = str[j] - '0';
                idx = j;
            }
        }
        if (idx == -1) continue;
        swap(str[i], str[idx]);
    }
    cout << str << "\n";
    
    return 0;
}
