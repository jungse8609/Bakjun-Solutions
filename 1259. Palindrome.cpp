#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string);

int main() {
    while (true) {
        string n;
        cin >> n;
        if (n == "0") break;

        if (isPalindrome(n))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

bool isPalindrome(string str) {
    string reverse_n = str;
    reverse(reverse_n.begin(), reverse_n.end());

    if (str == reverse_n)
        return true;
    return false;
}