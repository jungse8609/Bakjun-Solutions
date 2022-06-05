#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    set<string> unListen;
    set<string> unListenSeen;

    while (n-- > 0) {
        string name;
        cin >> name;
        unListen.insert(name);
    }
    while (m-- > 0) {
        string name;
        cin >> name;

        if (unListen.find(name) != unListen.end())
            unListenSeen.insert(name);
    }

    cout << unListenSeen.size() << '\n';
    for (auto& e : unListenSeen) {
        cout << e << '\n';
    }
}