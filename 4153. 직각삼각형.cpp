#include <iostream>
#include <cmath>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	while ( true ) {
		int side[3];
		int max = 0;
		for (int i = 0; i < 3; i++) {
			cin >> side[i];
			if (side[i] == 0) exit(0);
		}
		for (int i = 0; i < 2; i++) {
			if (side[2] < side[i])
				swap(side[2], side[i]);
		}

		if (pow(side[2], 2) == pow(side[0], 2) + pow(side[1], 2))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}	
}