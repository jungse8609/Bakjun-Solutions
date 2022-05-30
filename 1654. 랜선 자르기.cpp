#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

void prosetting();
void input();
void solve();

int K, N;
vector<int> Lans;

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
    cin >> K >> N;
    for (int i=0; i<K; i++) {
        int n;
        cin >> n;
        Lans.push_back(n);
    }

    sort(Lans.begin(), Lans.end(), less<int>());
}

void solve() {
    long long start = Lans[0];
    long long end = Lans[K - 1];

    for (int i=0; i<K; i++) {
        int count = 0;
        for (int& e : Lans) {
            count += e / Lans[i];
        }
        if (count < N) {
            if (i == 0) {
                start = 1;
                end = Lans[i];
            }
            else {
                start = Lans[i - 1];
                end = Lans[i];
            }
            break;
        }
    }

    
    long long mid = (start + end) / 2;
    while (start <= end) {
        long long count = 0;
        for (int& len : Lans) {
            count += len / mid; // 0으로 나누면 안되지..
        }

        if (count >= N)
            start = mid + 1;
        else
            end = mid - 1;

        mid = (start + end) / 2;

        //cout << "start = " << start << ", end = " << end << '\n';
    }

    cout << mid;
    
    // int i;
    
    // for (i=start; i<=end; i++) {
    //     int count = 0;
        
    //     if (count < N) break;
    // }

    // cout << --i;
}