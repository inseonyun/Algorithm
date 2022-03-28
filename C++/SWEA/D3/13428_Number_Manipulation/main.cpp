
//////////////////////////////////////////////////
// SWEA : 13428 숫자 조작
//////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void process() {

	int T, test_case;
	cin >> T;

	string s_num, new_num;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> s_num;

		long long max_num = stol(s_num);
		long long min_num = stol(s_num);
		long long result_num;
		int tmp_num;


		for (int i = 0; i < s_num.size(); i++) {
			for (int j = 0; j < s_num.size(); j++) {
				string s = s_num;
				if (i != j) {
					tmp_num = s[i] - '0';
					string tmp = s.replace(i, 1, to_string(s[j] - '0'));
					new_num = tmp.replace(j, 1, to_string(tmp_num));
					result_num = stol(new_num);

					if (max_num < result_num) {
						max_num = result_num;
					}
					if ((min_num > result_num) && new_num[0] != '0') {
						min_num = result_num;
					}
				}
			}
		}

		cout << "#" << test_case << " " << min_num << " " << max_num << "\n";

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	process();

	return 0;
}