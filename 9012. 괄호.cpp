#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void prosetting();
void input();
bool solve(string&);

int main() {
    prosetting();
    input();
}

void prosetting() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
}

void input() {
    while (true) {
        string line; 
        getline(cin, line);

        //cout << "line : " << line << '\n';
        if (line == ".") break;

        bool result = solve(line);

        if (result)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

bool solve(string& line) {
    stack<char> openChar;
    
    for (char c : line) {
        if (c == '(' || c == '[') {
            openChar.push(c);
        }
            
        if (c == ')') {
            if (openChar.empty())
                return false;
            else if (openChar.top() == '(')
                openChar.pop();
            else
                return false;
        }
        else if (c == ']') {
            if (openChar.empty())
                return false;
            else if (openChar.top() == '[')
                openChar.pop();
            else
                return false;
        }        
    }
    if (openChar.empty())
        return true;
    return false;
}