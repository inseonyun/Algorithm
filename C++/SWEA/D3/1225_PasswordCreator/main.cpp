
//////////////////////////////////////////////////
// SWEA_1225. [S/W 문제해결 기본] 7일차 - 암호생성기 D3
//////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
	for (test_case = 1; test_case <= 10; ++test_case) {
		int t;
        cin >> t;
        
        int num[8];
		queue<int> q;
		for (int i = 0; i < 8; i++) {
			cin >> num[i];
			q.push(num[i]);
		}
		int i = 1;
		while (true) {
			if (i <= 5) {
				int tmp = q.front() - i;	// 맨앞 원소 임시 변수에 저장
				q.pop();	// 맨앞 원소 삭제

				//원소 - i 값 맨 뒤에 저장
				if (tmp <= 0) {
					q.push(0);
					break;
				}
				else {
					q.push(tmp);
				}
				i++;
			}
			else {
				i = 1;
			}
		}
		cout << "#" << test_case << " ";
		
		int size = q.size();

		for (int i = 0; i < size; i++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
	}
	return 0;
}