#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	int sum = 0;
	string nums;
	cin >> n;
	cin >> nums;
	for (const char num : nums) {
		sum += num - '0';
	}		
	cout << sum;
}