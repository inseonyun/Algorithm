
//////////////////////////////////////////////////
// SWEA : 13038 교환학생
//////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void solu() {
	// 교환학생 
	// a[0] == 일요일 --> 일요일~토요일
	int test_case;
	cin >> test_case;

	vector<int> day;

	for (int TC = 0; TC < test_case; TC++) {
		int classCount;
		cin >> classCount;

		if (classCount == 1) {
			day.push_back(1);
			continue;
		}

		int arr[7];
		int days = 0;
		vector<int> dayArr;
		for (int i = 0; i < 7; i++) {
			cin >> arr[i];
			if (arr[i] == 1) {
				dayArr.push_back(i);
			}
		}
		int cycleMul = classCount / dayArr.size(); // class count가 더 큰 경우 한 주를 넘어감
		int cycleMod = classCount % dayArr.size();	// 남은 수업 
		if (cycleMod == 0) {
			cycleMul = cycleMul - 1;
			cycleMod = (int) dayArr.size();
		}
		int k= 99999999;
		for (int i = 0; i < 7; i++) {
			int check = 0;
			int idx = 0;
			while (check != cycleMod) {
				if (arr[(i + idx) % 7] == 1)
					check++;
				idx++;
			}
			k = min(k, 7 * cycleMul + idx);
		}

		day.push_back(k);
	}
	
	for (int i = 0; i < day.size(); i++) {
		cout << "#" << i + 1 << " " << day[i] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    solu();
    
    return 0;
}