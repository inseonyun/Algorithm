
//////////////////////////////////////////////////
// SWEA : 10912 외로운 문자
//////////////////////////////////////////////////

#include<iostream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string s;
		cin >> s;

		int inAp[27] = { 0, };
		string result = "";

		for (int i = 0; i < s.size(); i++) {
			inAp[s[i] - 'a']++;
		}

		for (int i = 0; i < sizeof(inAp)/sizeof(int); i++) {
			if (inAp[i] %2 != 0) {
				result += (i + 'a');
			}
		}

		if (result.empty()) {
			result = "Good";
		}
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}