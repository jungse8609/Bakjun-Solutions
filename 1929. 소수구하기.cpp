#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    
	int M, N;
	int rt;
    int arr[1000001] { 0, };
	cin >> M >> N;

    // for (int i = 2; i <= N; i++) {
    //     arr[i] = i;
    // }

    // for (int i = 2; i * i < N; i++) {
    //     // 이미 소수가 아님이 판명됨
    //     if (arr[i] == 0) {
    //         continue;
    //     }
    //     // 2, 3은 소수니까 제외하고
    //     // i를 인수의 곱으로 나타내면 제곱근까지만 검사하면 됨. 앞는 동일하기 때문
    //     for (int j = i * i; j <= N; j += i) {
    //         arr[j] = 0;
    //     }
    // }

    // for (int i = M; i <= N; i++) {
    //     if (arr[i] != 0)
    //         cout << arr[i] << '\n';
    // }

	for (int i = M; i <= N; i++) {
        // i를 인수의 곱으로 나타내면 제곱근까지만 검사하면 됨. 뒤는 동일하기 때문
		rt = sqrt(i);
		if (rt == 1 && i != 1) {	//2,3인 경우
			cout << i << '\n';
			continue;
		}
		if (i % 2 == 1) {	//홀수일 경우
			for (int j = 2; j <= rt; j++) {
				if (i % j == 0)
					break;
				if (j == rt) {
					cout << i << '\n';
				}
			}
		}
	}
}