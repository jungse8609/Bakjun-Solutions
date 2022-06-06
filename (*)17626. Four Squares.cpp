#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

/*
가장 큰 제곱수를 뺀다고 정답이 아니다.
따라서 탐색의 과정이 필요
>>  제곱수(x * x)를 하나씩 빼며 dp[n - x * x] 들 중 최솟값을 정해!
    거기에 +1 을 한게 최소 숫자가 되는거지

>>  1~n 까지의 dp를 정하고 골라 담아서 출력
*/

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    // d[0] = 0
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int minn = 987654321;
        for (int j=1; j*j <= i; j++) {
            minn = min(minn, dp[i - j * j]);
        }
        dp[i] = minn + 1;
    }

    cout << dp[n];
}