
//////////////////////////////////////////////////
// SWEA_9658. 유효숫자 표기_D3
//////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

vector<int> v, v2;
string str, result;
int numSize;

void inputData() {
	cin >> str;

	for (char c : str) {
		int tmp = c - '0';
		v.push_back(tmp);
	}
	v2.push_back(v[0]);
	v2.push_back(v[1]);
	v2.push_back(v[2]);
}

void process() {
	numSize = v.size() - 1;

	if (v[2] >= 5) {
		if (v[1] < 9) {
			v[1]++;
			v[2] = 0;
		}
		else {
			if (v[0] < 9) {
				v[0]++;
				v[1] = 0;
				v[2] = 0;
			}
			else {
				v[0] = 1;
				v[1] = 0;
				v[2] = 0;
				numSize++;
			}
		}
	}
	cout << v[0] << "." << v[1] << "*10^" << numSize << "\n";
	v.clear();
	v2.clear();
}

int main() {
	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		inputData();
		cout << "#" << test_case << " ";
		process();
	}

	return 0;
}