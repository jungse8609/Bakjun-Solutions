#include <iostream>
#include <vector>
using namespace std;

void prosetting();
void input();
void printInfo();
void solve();

int N;
vector<pair<int, int>> Info;

int main() {
    prosetting();
    input();
    //printInfo();
    solve();
}

void solve() {
    vector<int> order (N, 1);
    
    for (int i = 0; i < N - 1; i++) {
        int count = 0;
        for (int j = i + 1; j < N; j++) {
            if (Info[i].first < Info[j].first) {
                if (Info[i].second < Info[j].second) {
                    order[i]++;
                }
            }

            if (Info[i].first > Info[j].first) {
                if (Info[i].second > Info[j].second) {
                    order[j]++;
                }
            }
        }
    }

    for (int n : order)
        cout << n << " ";
}

void prosetting() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
}

void input() {
    cin >> N;

    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        Info.push_back(make_pair(x, y));
    }
}

void printInfo() {
    for (auto pair : Info) {
        cout << pair.first << ", " << pair.second << '\n';
    }
}