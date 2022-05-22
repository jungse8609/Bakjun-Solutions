#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;

    int M = 5; // 더 큰 봉지
    int m = 3;

    // 5A + 3B = 18

    int minCnt = 5001;
    
    for (int i = 0; i <= N / M; i++) {
        if ((N - M * i) % m == 0) {
            int cnt = i + (N - M * i) / m;
            
            if (minCnt > cnt)
                minCnt = cnt;
        }            
    }

    if (minCnt == 5001)
        cout << -1;
    else
        cout << minCnt;
}