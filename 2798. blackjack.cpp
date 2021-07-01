#include <iostream>
#include <cstdlib>
#include <vector>

#define R 3

using namespace std;

int factorial(const int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	int count = factorial(n) / (factorial(n-R) * factorial(R));
	
	vector<int> sums;
	vector<int> errors;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = card[i] + card[j] + card[k];
				sums.push_back(sum);
				errors.push_back(abs(sum - m));
			}
		}
	}

	int min = errors[0];
	int min_index;
	for (int i = 0; i < count - 1; i++) {
		if (errors[i] < min) {
			min = errors[i];
			min_index = i;
		}
	}
	cout << sums[min_index];
}