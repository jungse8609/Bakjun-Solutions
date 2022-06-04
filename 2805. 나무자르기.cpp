#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> hVec;
    int hMax = -1;
    for (int i=0; i<N; i++) {
        int h;
        cin >> h;
        if (hMax < h) hMax = h;
        hVec.push_back(h);
    }
    hVec.push_back(0); // 마지막 원소를 계산하기 위함
    
    sort(hVec.begin(), hVec.end(), greater<int>());

    long long mul = 1;
    long long hCut = 0;
    long long len = 0;
    for (int i = 0; i < N; i++) {
        hCut += hVec[i] - hVec[i + 1];
        len += mul * (hVec[i] - hVec[i + 1]);
        
        // 한 번에 잘리는 나무가 증가함
        if (len < M) {
            mul++;
        }
        else if (len == M) {
            break;
        }
        else {
            double neededLength;
            hCut -= hVec[i] - hVec[i + 1];
            len -= mul * (hVec[i] - hVec[i + 1]);
            neededLength = M - len;

            // 여기가 버그가 일어난 지점
            // 사실 당연한건데 이걸 몰랐네...!
            hCut += ceil(neededLength / mul);

            break;
        }
    }
    
    cout << hMax - hCut;
}