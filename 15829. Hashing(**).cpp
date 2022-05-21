#include <iostream>
#include <cmath>

using namespace std;

unsigned long get_hash(string);

// const int r = 31; -> 이걸 SHIFT로 구현하네 !
const int TABLE_SIZE = 1234567891;

int main() {
    int L;
    string str;
    cin >> L;
    cin >> str;

    unsigned long hash = get_hash(str);

    cout << hash;
}

unsigned long get_hash(string str) {
    unsigned long hash = 0;
    int c;
    for (int i = (int)str.size() - 1; i >= 0; i--) {
        c = str[i] - 'a' + 1;
        hash = (((hash << 5) - hash) + c) % TABLE_SIZE;
        continue;
    }
    return hash % TABLE_SIZE;
}