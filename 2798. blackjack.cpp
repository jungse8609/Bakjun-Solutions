#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	int min = INT_MAX;
	int result = -1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = card[i] + card[j] + card[k];
				int error = m - sum;
				if (error >= 0 && error < min) {
					min = error;
					result = sum;
				}
			}
		}
	}
	cout << result;
}