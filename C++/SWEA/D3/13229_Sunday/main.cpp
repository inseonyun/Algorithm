
//////////////////////////////////////////////////
// SWEA : 13229 일요일
//////////////////////////////////////////////////

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	int test_case;
	cin >> T;
	
	string days[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int day;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;

		for (int i = 0; i < sizeof(days)/sizeof(string); i++) {
			if (days[i].compare(s) == 0) {
				day = i;
			}
		}
		switch (day) {
		case 0:
			cout << "#" << test_case << " " << 6 << endl;
			break;
		case 1:
			cout << "#" << test_case << " "  << 5 << endl;
			break;
		case 2:
			cout << "#" << test_case << " " << 4 << endl;
			break;
		case 3:
			cout << "#" << test_case << " " << 3 << endl;
			break;
		case 4:
			cout << "#" << test_case << " " << 2 << endl;
			break;
		case 5:
			cout << "#" << test_case << " " << 1 << endl;
			break;
		case 6:
			cout << "#" << test_case << " " << 7 << endl;
			break;
		}
	}
	return 0;
}