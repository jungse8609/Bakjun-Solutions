#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void prosetting();
void input();
void solve();

int N;

queue<int> cards;

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
    for (int i = 1; i <= N; i++) {
        cards.push(i);
    }
}

void solve() {
    while (cards.size() > 1) {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();
}