#include <iostream>
using namespace std;

int N, K;

int combination(int, int);
int factorial(int);

int main() {
    cin >> N >> K;

    cout << combination(N, K);
}

int combination(int a, int b) {
    int result = 1;

    if (b <= a - b) {
        for (int i = 0; i < b; i++) {
            result *= a - i;
        }
        
        return result / factorial(b);
    }
    else {
        for (int i = 0; i < a - b; i++) {
            result *= a - i;
        }
        
        return result / factorial(a - b);
    }
}

int factorial(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n * factorial(n - 1);
}