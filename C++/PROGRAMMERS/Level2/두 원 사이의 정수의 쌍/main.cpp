#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for (int i = 1; i <= r2; i++) {
		int minY = ceil(sqrt(pow(r1, 2) - pow(i, 2)));
		int maxY = floor(sqrt(pow(r2, 2) - pow(i, 2)));

		if (r1 < i)
			minY = 0;

		answer += (maxY - minY + 1);
	}
    
    return answer * 4;
}
