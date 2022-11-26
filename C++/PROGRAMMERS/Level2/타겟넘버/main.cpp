
//////////////////////////////////////////////////
// PROGRAMMERS : 타겟 넘버
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
void dfs_prm(vector<int> numbers, int target, int sum, int count) {
	if (count == numbers.size()) {
		if (sum == target)
			answer++;
		return;
	}
	dfs_prm(numbers, target, sum + numbers[count], count + 1);
	dfs_prm(numbers, target, sum - numbers[count], count + 1);
}

int solution(vector<int> numbers, int target) {
	dfs_prm(numbers, target, 0, 0);

	return answer;
}

int main() {

	return 0;
}
