#include <iostream>
using namespace std;

//int sum(const int n) {
//	int result = 3*n*(n-1);
//	return result;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	// ������ �� ������ 6 * i ��ŭ ������
//	int result = 1;
//	for (int i = 1; i <= n; i++) {
//		if (n <= sum(i)+1) {
//			result = i;
//			break;
//		}
//	}
//	cout << result;
//}

int main() {
	int n;
	cin >> n;

	int i, sum = 1;
	for (i = 1; sum < n; i++) sum += 6 * i;
	cout << i;
}