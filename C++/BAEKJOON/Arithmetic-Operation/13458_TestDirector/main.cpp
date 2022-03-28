
//////////////////////////////////////////////////
// BAEKJOON_13458번: 시험 감독
//////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 각 시험장의 응시자 수 A(i)명
	// 총감독관이 감시할 수 있는 응시자 수 B
	// 부감독관이 감시할 수 있는 응시자 수 C
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<long long> test;	// 각 시험장 응시자 수 담은 변수
	long long N;				// 시험장 개수
	long long mainDirector;	// 총감독관이 감시할 수 있는 응시자 수 B
	long long subDirector;	// 부감독관이 감시할 수 있는 응시자 수 C
	long long directorCount = 0;
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		long long test_count;
		cin >> test_count;

		test.push_back(test_count);
	}
	cin >> mainDirector;
	cin >> subDirector;
	
	for (int i = 0; i < N; i++) {
		long long needDirectorCount = 0;
		if (test[i] - mainDirector <= 0) {
			directorCount += 1;
			continue;
		}
		else {
			directorCount += 1;
			needDirectorCount = test[i] - mainDirector;
			while (needDirectorCount > 0) {
				if (needDirectorCount / subDirector == 0 && needDirectorCount - subDirector <= 0) {
					directorCount += 1;
					break;
				}
				else {
					long long tmp = needDirectorCount / subDirector;
					needDirectorCount = needDirectorCount - (subDirector * tmp);
					directorCount += tmp;
				}
			}
		}
	}
	cout << directorCount;

	return 0;
}