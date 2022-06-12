#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void BFS(vector<int>& visited, int root);

vector<int> nodes[101];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    
    for (int i=1; i<=n; i++) {
        nodes[i].push_back(i);
    }

   for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    // for (int i=1; i<=n; i++) {
    //     for (auto& e : nodes[i]) {
    //         cout << e << " -> ";
    //     }
    //     cout << "\n============\n";
    // }

    vector<int> visited;
    BFS(visited, 1);
    
    // cout << "visited : ";
    // for (auto& e : visited) {
    //     cout << e << " ";
    // }
    //cout << '\n';
    cout << visited.size() - 1;
}

void BFS(vector<int>& visited, int root) {
    for (auto& e : nodes[root]) {
        for (auto& num : nodes[e]) {
            if (find(visited.begin(), visited.end(), num) == visited.end()) {
                visited.push_back(num);
                BFS(visited, num);
            }
        }
    }
}