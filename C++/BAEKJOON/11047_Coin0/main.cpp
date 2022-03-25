
//////////////////////////////////////////////////
// BAEKJOON_11047번: 동전 0
//////////////////////////////////////////////////

#include <iostream>

using namespace std;

void coin0() {
	int N;
	long long K;
	cin >> N >> K;

	long long *coinArr = new long long[N];
	long long count = 0;

	for (int i = 0; i < N; i++) {
		cin >> coinArr[i];
	}
	for (int i = N - 1; i > -1; i--) {
		count += K / coinArr[i];
		K = K % coinArr[i];
	}
	cout << count;
}

int main() {
    coin0();
    
    return 0;
}