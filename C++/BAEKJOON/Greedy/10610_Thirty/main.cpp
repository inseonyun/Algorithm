
//////////////////////////////////////////////////
// BAEKJOON_10610번: 30
//////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void thirty() {
	string n;
	cin >> n;

	sort(n.begin(), n.end(), greater<>());

	if (n[n.length() - 1] != '0') {
		cout << -1;
	}
	else {
		long long sum = 0;
		for (char c : n) {
			sum += c - '0';
		}
		if (sum % 3 == 0) {
			cout << n;
		}
		else {
			cout << -1;
		}
	}
}

int main() {
    thirty();
    
    return 0;
}