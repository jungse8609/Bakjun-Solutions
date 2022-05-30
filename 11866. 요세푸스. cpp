#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

void prosetting();
void input();
void solve();

int N, K;
queue<int> q;


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
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        q.push(i);
    }
}

void solve() {
    // list - remove 이용해서 interator 를 직접 이동시켜보자..
    queue<int> result;

    while (!q.empty()) {
        for (int i=0; i<K-1; i++) {
            q.push(q.front());
            q.pop();
        }

        result.push(q.front());
        q.pop();
    }

    cout << '<';
    while (!result.empty()) {
        cout << result.front();
        if (result.size() > 1)
            cout << ", ";
        result.pop();
    }
    cout << '>';
}