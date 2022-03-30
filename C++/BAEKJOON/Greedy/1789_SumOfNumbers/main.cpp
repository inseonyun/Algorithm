
//////////////////////////////////////////////////
// BAEKJOON_1789번: 수들의 합
//////////////////////////////////////////////////

#include <iostream>

using namespace std;

void sumOfNumbers() {
	long long S;
	cin >> S;

	long long n = 1;
	long long sum = 0;
	long long cnt = 0;
	while (true) {
		if (sum >= S)
			break;
		n += 1;
		sum += n;
		cnt += 1;
	}
	cout << cnt;
}

int main() {
    sumOfNumbers();
    
    return 0;
}