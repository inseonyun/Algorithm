
//////////////////////////////////////////////////
// SWEA_1986. 지그재그 숫자 D2
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
		int n;
        int sum = 0;
        cin >> n;
        for(int i =1; i <= n; i++) {
            if(i % 2 == 0 ) {
            	sum -= i;
            }
            else {
                	sum += i;
            }
        }
        cout << "#" << test_case << " " << sum << endl;
	}
	return 0;
}