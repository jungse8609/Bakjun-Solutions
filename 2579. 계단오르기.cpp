#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int stair[301], dp[301];

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        stair[i] = num;
    }

    // 경우의 수
    // 1 0 1 1 : dp[i-3]+stair[i-1]+stair[i] 
    // 1 0 1   : dp[i-2]+stair[i]
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i=3; i<n; i++) {
        dp[i] = max(dp[i-3]+stair[i-1]+stair[i], dp[i-2]+stair[i]);
    }

    cout << dp[n - 1];
}