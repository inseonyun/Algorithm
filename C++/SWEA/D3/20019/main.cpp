#include<iostream>
#include<string>
 
using namespace std;
 
bool check_palindrome(string str) {
    int str_len = str.length();
 
    for (int i = 0, j = str_len - 1; i < str_len; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
 
    return true;
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;
        bool isPalindrome;
        isPalindrome = check_palindrome(str);
 
        if (isPalindrome) {
            int str_len = str.length();
            int palindrome_idx = (str_len - 1) / 2;
 
            isPalindrome = check_palindrome(str.substr(0, palindrome_idx));
            isPalindrome = check_palindrome(str.substr(str_len - palindrome_idx, str_len));
        }
 
        if (isPalindrome) {
            cout << "#" << test_case << " YES\n";
        }
        else
        {
            cout << "#" << test_case << " NO\n";
        }
    }
    return 0;
}
