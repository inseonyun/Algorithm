
//////////////////////////////////////////////////
// SWEA : 4522 세상의 모든 팰린드롬
//////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swExpertAcademy_3_5() {
	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		string s;
		cin >> s;

		int flag = 0;
		int n = s.length();
		for (int i = 0; i < n/2; i++) {
			if (s[i] == '?' || s[n - 1 - i] == '?')
				continue;
			if (s[i] != s[n - 1 - i]) {
				flag = 1;
				break;
			}
		}

		if (flag) {
			cout << "#" << test_case << " " << "Not exist\n";
		}
		else {
			cout << "#" << test_case << " " << "Exist\n";
		}
	}

}
int main() {
	swExpertAcademy_3_5();
	return 0;
}