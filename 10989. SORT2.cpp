#include <iostream>
using namespace std;

void prosetting();
void input();

int N;
int NumArr[10001] = { 0, };

int main() {
    prosetting();
    input();

    for (int i=0; i<sizeof(NumArr)/sizeof(NumArr[0]); i++) {
        if (NumArr[i] > 0) {
            for (int j=0; j<NumArr[i]; j++) {
                cout << i << '\n';
            }
        }
    }    
}

void prosetting() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
}

void input() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int n;
        cin >> n;

        NumArr[n] ++;
    }
}