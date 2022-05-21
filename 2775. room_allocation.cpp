#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		int bottom[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
		int top[14] = {0, };

		for (int i = 0; i < k; i++) {
			// update top
			for (int a = 1; a <= n; a++) {
				int sum = 0;

				for (int b = 0; b < a; b++) {
					sum += bottom[b];					
				}
				top[a-1] = sum;
			}
			// update bottom
			for (int a = 0; a < n; a++) {
				bottom[a] = top[a];
			}
		}
		cout << top[n - 1] << endl;
	}
}