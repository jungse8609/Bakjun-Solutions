#include <iostream>
using namespace std;

int assign(const int h, const int w, const int n) {
	int room;
	int floor = 0, number = 1;

	for (int i = 0; i < n; i++) {
		if (floor < h) floor++;
		else {
			floor = 1;
			number++;
		}			
	}

	room = floor * 100 + number;
	return room;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;
		int room = assign(h, w, n);
		cout << room << endl;
	}
}