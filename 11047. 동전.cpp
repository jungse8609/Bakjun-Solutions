#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    stack<int> valueStack;

    while (n-- > 0) {
        int value;
        cin >> value;
        valueStack.push(value);
    }

    int count = 0;
        
    while (k > 0) {
        if (k >= valueStack.top()) {
            while (k >= valueStack.top()) {
                k -= valueStack.top();
                count ++;

                // cout << k + valueStack.top() << " -> " << k << '\n';
                // cout << "count : " << count << '\n';
            }
        }
        else {
            //cout << valueStack.top() << " Out!\n";
            valueStack.pop();
        }
    }
    
    //cout << '\n';
    cout << count;
}