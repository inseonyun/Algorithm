
//////////////////////////////////////////////////
// SWEA_1926. 간단한 369게임 D2
//////////////////////////////////////////////////

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	int cheon, baek, sip, il;
	for (test_case = 1; test_case <= T; ++test_case) {
		int count = 0;

		baek = test_case / 100;
		sip = (test_case - baek * 100) / 10;
		il = (test_case - baek * 100 - sip * 10);

		if ((baek != 0 && baek % 3 == 0) || (sip != 0 && sip % 3 == 0) || (il != 0 && il % 3 == 0)) {
			if (baek != 0 && baek % 3 == 0)
				count++;
			if (sip != 0 && sip % 3 == 0)
				count++;
			if (il != 0 && il % 3 == 0)
				count++;
			if (count != 0) {
				for (int i = 0; i < count; i++) {
					cout << "-";
				}
				cout << " ";
			}

		}
		else
			cout << test_case << " ";
	}
	return 0;
}