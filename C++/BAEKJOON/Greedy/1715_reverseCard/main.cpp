
//////////////////////////////////////////////////
// BAEKJOON_1715번: 카드 뒤집기
//////////////////////////////////////////////////

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
void reverse_card() {
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long card;
		cin >> card;

		pq.push(card);
	}
	long long res = 0;
	while (!pq.empty() && N > 1) {
		long long first = pq.top();
		pq.pop();
		long long second = pq.top();
		pq.pop();

		long long tmp = first + second;
		res += tmp;
		if (pq.empty())
			break;

		pq.push(tmp);
	}

	cout << res << "\n";
}

int main() {
    reverse_card();
    
    return 0;
}