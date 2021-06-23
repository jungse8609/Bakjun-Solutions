#include <iostream>
using namespace std;

bool ascend(char *melody) {
	for (int i = 0; i < 7; i++)
		if (melody[i + 1] != melody[i] + 1)
			return false;
	return true;
}

bool descend(char *melody) {
	for (int i = 0; i < 7; i++)
		if (melody[i] != melody[i + 1] + 1)
			return false;
	return true;
}

int main() {
	char melody[8];
	for (int i = 0; i < 8; i++)
		cin >> melody[i];
	if (ascend(melody)) cout << "ascending";
	else if (descend(melody)) cout << "descending";
	else cout << "mixed";
}