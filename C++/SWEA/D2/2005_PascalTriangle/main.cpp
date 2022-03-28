
//////////////////////////////////////////////////
// SWEA_2005. 파스칼의 삼각형 D2
//////////////////////////////////////////////////

#include<iostream>

using namespace std;

int factorial(int n) {
	if (n == 0 || n == 1)
		return 1;
	else return n * factorial(n - 1);
}
int nCr(int n, int r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}


int main(int argc, char** argv)
{
	int T;
	int test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		cout << "#" << test_case << "\n";

		// 동적할당 2차원 배열 생성
		int newN = n + 1;
		int **arr = new int*[newN];
		for (int i = 0; i < newN; i++) {
			arr[i] = new int[newN];
		}
		for (int i = 0; i < newN; i++) {
			for (int j = 0; j < newN; j++) {
				arr[i][j] = 0;
			}
		}
		arr[1][1] = 1;

		for (int i = 2; i < newN; i++) {
			for (int j = 1; j <= i; j++) {
				arr[i][j] = arr[i - 1][j-1] + arr[i-1][j];
			}
		}

		for (int i = 1; i < newN; i++) {
			for (int j = 1; j < newN; j++) {
				if(arr[i][j] > 0)
					cout << arr[i][j] << " ";
			}
			cout << "\n";
		}

		
		// 동적할당 해제
		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
		
	}
	return 0;
}