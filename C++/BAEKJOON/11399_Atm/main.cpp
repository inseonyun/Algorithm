
//////////////////////////////////////////////////
// BAEKJOON_11399번: ATM
//////////////////////////////////////////////////

#include <iostream>
#include <algorithm>

using namespace std;

void atm() {
	int size;
	long long result = 0;
	cin >> size;

	long long* arr = new long long[size];

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + size);

	long long prev = 0;

	for (int i = 0; i < size; i++) {
		prev += arr[i];
		result += prev;
	}
	cout << result;
}

int main() {
    atm();
    
    return 0;
}