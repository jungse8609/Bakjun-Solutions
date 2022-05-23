#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

bool comp(string a, string b) {
    if (a.size() == b.size())
        return a < b;
    
    return a.size() < b.size();
}

int main() {
    cin >> N;

    vector<string> words;
    vector<string> visited;
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        // 처음 들어오는 경우에 ...
        if (find(visited.begin(), visited.end(), word) == visited.end()) {
            visited.push_back(word);
            words.push_back(word);
        }
    }

    sort(words.begin(), words.end(), comp);

    for (auto w : words)
        cout << w << "\n";
}