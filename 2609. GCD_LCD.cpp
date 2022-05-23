#include <iostream>
using namespace std;

int A, B;

int get_gcd(int a, int b);
int get_lcd(int a, int b);

int main() {
    cin >> A >> B;

    if (A < B) {
        int temp = B;
        B = A;
        A = temp;
    }
    cout << get_gcd(A, B) << endl;
    cout << get_lcd(A, B) << endl;
}

int get_gcd(int a, int b) {
    int r = a % b;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int get_lcd(int a, int b) {
    return (a * b) / get_gcd(a, b);
}