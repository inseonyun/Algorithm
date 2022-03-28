
//////////////////////////////////////////////////
// SWEA : 13547 팔씨름
//////////////////////////////////////////////////

#include <iostream>

using namespace std;

void armWrestling() {
	int test_case;
	cin >> test_case;

	for (int TC = 0; TC < test_case; TC++) {
		string s;
		cin >> s;
		
		int countX = 0;
		for (char c : s) {
			if (c == 'x')
				countX++;
		}
		if (countX < 8) {
			cout << "#" << TC + 1 << " YES\n";
		}
		else {
			cout << "#" << TC + 1 << " NO\n";
		}

	}
}

int main() {
	armWrestling();
    
    return 0;
}