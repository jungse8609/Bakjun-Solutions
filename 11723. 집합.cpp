#include <iostream>
#include <set>
using namespace std;


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int M;
    cin >> M;
    
    set<int> s;
    set<int> emptySet;
    set<int> allSet;
    for (int i=1; i<=20; i++) {
        allSet.insert(i);
    }

    while (M-- > 0) {
        string op;
        cin >> op;

        if (op == "add") {
            int n;
            cin >> n;
            s.insert(n);
        }
        else if (op == "remove") {
            int n;
            cin >> n;
            if (s.count(n) != 0)
                s.erase(n);
        }
        else if (op == "check") {
            int n;
            cin >> n;
            if (s.count(n) == 0)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
        else if (op == "toggle") {
            int n;
            cin >> n;
            if (s.count(n) == 0)
                s.insert(n);
            else
                s.erase(n);
        }
        else if (op == "all") {
            s = allSet;
        }
        else if (op == "empty") {
            s = emptySet;
        }
        else {
            cout << "Invalid Operation.\n";
        }
    }
}