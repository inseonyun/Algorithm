
//////////////////////////////////////////////////
// BAEKJOON_4949번: 균형잡힌 세상
//////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	while (true) {
		vector <char> openChar;
		string str;

		getline(cin, str);

		if (str[0] == '.')
			break;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				openChar.push_back(str[i]);
			}
			if (str[i] == ')') {
				if (!openChar.empty() && openChar.back() == '(') {
					openChar.pop_back();
				}
				else {
					cout << "no\n";
					break;
				}
			}
			if (str[i] == ']') {
				if (!openChar.empty() && openChar.back() == '[') {
					openChar.pop_back();
				}
				else {
					cout << "no\n";
					break;
				}
			}
			if (openChar.empty() && i == str.length() - 2)
				cout << "yes\n";
			else if (!openChar.empty() && i == str.length() - 2)
				cout << "no\n";
		}
	}

	return 0;
}