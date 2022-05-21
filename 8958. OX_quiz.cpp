#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	cin >> num;

	string str;
	int count;
	int score;

	while (num--) {
		score = 0;
		count = 0;

		cin >> str;
		for (const char ch : str) {
			if (ch == 'O') {
				count++;
				score += count;
			}				
			else if (ch == 'X') {
				count = 0;
			}
		}
		cout << score << endl;
	}
}