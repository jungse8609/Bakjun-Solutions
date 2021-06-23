#include <iostream>
#include <string>
using namespace std;

void toUpper(string &word) {
	for (int i = 0; i < word.size(); i++) {
		if ('a' <= word[i] && word[i] <= 'z') {
			word[i] -= 'a' - 'A';
		}			
	}
}

int main() {
	string word;
	cin >> word;

	toUpper(word);

	int count[26] = { 0, };
	char alphabet[26];
	for (const char a : word) {
		count[a - 'A']++;
		alphabet[a - 'A'] = a;
	}

	int index = 0; // max index
	int max = 0;
	bool isOverrap = false;

	for (int i = 0; i < 26; i++) {
		if (max == count[i])
			isOverrap = true;

		if (count[i] > max) {
			index = i;
			max = count[i];
			isOverrap = false;
		}
	}
	if (isOverrap) cout << '?';
	else cout << alphabet[index];
}