#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

void prosetting();
void input();
void solve();

int N;

int main() {
    prosetting();
    input();
    solve();
}

void prosetting() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
}

void input() {
    cin >> N;
}

void solve() {
    int count = 0;
    int result = 0;

    for (int i=1; i<987654321; i++) {
        int x = i;
        int r;
        int sixCnt = 0;
        while (x > 0) {
            r = x % 10;
            if (r == 6) sixCnt += 1;
            else sixCnt = 0;

            if (sixCnt >= 3) {
                count += 1;
                break;
            }
            
            x /= 10;
        }


        if (count == N) {
            result = i;
            break;
        }            
    }

    cout << result;
}