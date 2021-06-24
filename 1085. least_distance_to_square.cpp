#include <iostream>
#include <string>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int least_distance = 1000;
	int x20, x2w, y20, y2h;
	x20 = x;
	x2w = w - x;
	y20 = y;
	y2h = h - y;

	int distance[4] = {x20, x2w, y20, y2h};
	for (int i = 0; i < 4; i++) {
		if (distance[i] < least_distance)
			least_distance = distance[i];
	}
	cout << least_distance;
}