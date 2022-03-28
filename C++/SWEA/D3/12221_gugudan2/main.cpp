
//////////////////////////////////////////////////
// SWEA_12221. 구구단2_D3
//////////////////////////////////////////////////

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int A, B, result;
        cin >> A >> B;
        
        if(A >=10 || B >= 10) {
            result = -1;
        } else {
            result = A * B;
        }
        cout << "#" << test_case << " " << result << "\n";

	}
	return 0;
}