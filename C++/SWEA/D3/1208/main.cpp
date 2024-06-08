#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int limit;
        vector<int> v(100);
        
        cin >> limit;
        for (int i = 0; i < 100; i++) {
        	cin >> v[i];
        }
		
        while (limit-- > 0) {
        	int max_idx = max_element(v.begin(), v.end()) - v.begin();
            int min_idx = min_element(v.begin(), v.end()) - v.begin();
            
            v[max_idx]--;
            v[min_idx]++;
        }
        
        int res = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
        cout << "#" << test_case << " " << res << "\n";
	}
	return 0;
}
