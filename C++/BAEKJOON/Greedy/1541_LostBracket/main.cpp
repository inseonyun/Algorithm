
//////////////////////////////////////////////////
// BAEKJOON_1541번: 잃어버린 괄호
//////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

void lostBracket() {
	string st;
	getline(cin, st, '\n');
	
	stringstream ss;
	ss.str(st);
	string n;
	
	int ans = 0;
	int idx = 0;
	while (getline(ss, n, '-')) {
		stringstream tmpss;
		tmpss.str(n);
		string tmp;
		if (idx >= 1) {
			while (getline(tmpss, tmp, '+')) {
				ans -= stoi(tmp);
			}
		}
		else {
			while (getline(tmpss, tmp, '+')) {
				ans += stoi(tmp);
			}
		}
		idx++;
	}
	cout << ans;
}

int main() {
    lostBracket();
    
    return 0;
}