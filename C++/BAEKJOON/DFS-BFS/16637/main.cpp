#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N, max_res = INT_MIN;
string s;

int calc(int a, int b, char op) {
	int result = a;
	switch (op) 
	{
	case '+':
		result += b;
		break;
	case '*':
		result *= b;
		break;
	case '-':
		result -= b;
		break;
	}
	return result;
}

void dfs(int idx, int curr) {
	// 종료 조건
	if (idx >= N) {
		max_res = max(max_res, curr);
		return;
	}

	// 현재 값과 다음 값의 Operator
	char op = (idx == 0) ? '+' : s[idx - 1];

	// 괄호 묶음: 현재 값 + 괄호 계산
	if (idx + 2 < N) {
		int a = s[idx] - '0';
		int b = s[idx + 2] - '0';
		int op_ab = s[idx + 1];

		int parentheses_res = calc(a, b, op_ab);

		int next_idx = idx + 4;
		int next_curr = calc(curr, parentheses_res, op);

		dfs(next_idx, next_curr);
	}

	// 괄호 안 묶음: 현재 값 + 다음 값
	int next_idx = idx + 2;
	int next_curr = calc(curr, s[idx] - '0', op);
	dfs(next_idx, next_curr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> s;
	
	dfs(0, 0);
	
	cout << max_res;
  
  return 0;
}
