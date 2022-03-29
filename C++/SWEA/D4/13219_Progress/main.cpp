
//////////////////////////////////////////////////
// SWEA_13219. 진행률_D4
//////////////////////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979;
int main() {
	int TC;
	cin >> TC;

	int result[1000] = { 0, };

	for (int test_case = 0; test_case < TC; test_case++) {
		int P, X, Y;
		cin >> P >> X >> Y;

		if (50 < sqrt(pow(X - 50, 2) + pow(Y - 50, 2))) {
			continue;
		}

		int cenX = 50, cenY = 50;

		double theta = (P * 0.01) * 360;
		double tmp = atan2(X - cenX, Y - cenY) * 180 / pi;

		if (tmp < 0) {
			tmp = abs(tmp);

			double tmp2 = atan2(cenX - X, cenY - Y) * 180 / pi;
			tmp = tmp + tmp2 * 2;
		}

		if (tmp < theta) {
			result[test_case] = 1;
		}
	}

	for (int i = 0; i < TC; i++) {
		cout << "#" << i + 1 << " " << result[i] << "\n";
	}

	return 0;
}