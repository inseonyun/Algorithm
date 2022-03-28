
//////////////////////////////////////////////////
// BAEKJOON_5585번: 거스름 돈
//////////////////////////////////////////////////

#include <iostream>

using namespace std;

void change() {
	int money, result = 0;
	cin >> money;
	money = 1000 - money;
	
	/*
	if (money / 500 != 0) {
		result += money / 500;
		money = money % 500;
	}
	if (money / 100 != 0) {
		result += money / 100;
		money = money % 100;
	}
	if (money / 50 != 0) {
		result += money / 50;
		money = money % 50;
	}
	if (money / 10 != 0) {
		result += money / 10;
		money = money % 10;
	}
	if (money / 5 != 0) {
		result += money / 5;
		money = money % 5;
	}
	if (money / 1 != 0) {
		result += money / 1;
	}
	*/

	int chMoney[] = { 500, 100, 50, 10, 5, 1 };

	for (int i : chMoney) {
		result += money / i;
		money = money % i;
	}

	cout << result;

}

int main() {
    change();
    
    return 0;
}