#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string str;
	char temp = 0x20; // space
	int count = 0;

	//cout << "Input a string: ";
	getline(cin, str);

	for (char ch : str) {
		if (isspace(temp) && !isspace(ch)) count++;
		temp = ch;
	}
	/*for (int i = 1; str[i] != '\0'; i++) {
		if (str[i] != ' ' && str[i + 1] == '\0')
			count++;
		else if (str[i - 1] != ' ' && str[i] == ' ')
			count++;
	}*/
	cout << count;
}