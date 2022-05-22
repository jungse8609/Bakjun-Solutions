#include <iostream>
using namespace std;

int A, B, V;

int main() {
    cin >> A >> B >> V;

    int d = (V - A) / (A - B);
    int h = d * (A - B);

    while (true) {
        d += 1;
        
        h += A;
        if (h >= V)
            break;

        h -= B;
        if (h < 0)
            h = 0;
    }

    cout << d;
}