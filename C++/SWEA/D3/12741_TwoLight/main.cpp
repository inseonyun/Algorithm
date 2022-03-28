
//////////////////////////////////////////////////
// SWEA : 12741 두 전구
//////////////////////////////////////////////////

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	int test_case;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int num[4];
		for(int i = 0; i < 4; i++)
			cin >> num[i];

		int sec = min(num[1], num[3]) - max(num[0], num[2]);
		if (sec <= 0)
			sec = 0;

		// 동시에 켜져있던 시간(초) 출력
		cout << "#" << test_case << " " << sec << "\n";
	}
	return 0;
}