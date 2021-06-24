#include <iostream>
using namespace std;

void findBunhaehab(const int num) {
	int result = 0;
	for (int i = 0; i < num; i++) {
		int j = i;
		int sum = 0;
		while (j > 0) {
			sum += j % 10;
			j /= 10;
		}
		if (num == i + sum) {
			result = i;
			break;
		}
	}
	cout << result;
}

int main() {
	int n;
	cin >> n;

	findBunhaehab(n);
}