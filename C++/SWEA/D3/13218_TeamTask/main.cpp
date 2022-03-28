
//////////////////////////////////////////////////
// SWEA : 13218 조별과제
//////////////////////////////////////////////////

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int num;
		cin >> num;

		int max = 0;
		
		if (num >= 3) {
			int na = num % 3;		// na의 개수만큼만 4명의 팀을 구성하면 됨

			num = num - (na * 4);
			max = num / 3 + na;
		}
		cout << "#" << test_case << " " << max << "\n";
	}
	return 0;
}