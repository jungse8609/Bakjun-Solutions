// === 생각의 과정 ===
// 결국 어떤 길이 x 의 배수로 나와야지

// 802 / 4 = 200 (integer)

// 802 / 3 = 267

// 그럼 최대 길이를 순서대로 나누면서 가능한 경우 찾기?
// 이때 잘린 길이는 최소 길이보다 짧아야함 
// -> 그럼 시작을 
// 최대 / 최소
// ex) 802 / 539 = 1.xx -> 올림 : 2
// 이걸로 해야지

// 오류 -> 꼭 모든 랜선을 사용할 필요는 없다..!
// -> leastDivision을 1부터 출발시킴
// -> 근데 안됨.. 다른 반례를 찾읍시다

// 1. 꼭 최대 길이에서 시작해야 하는가

// 최대길이에서 가장 많은 조각이 나올테니 당연한거 아닌가..?

// 2. ***자르는 길이가 반드시  Max / leastDivision 으로 구해지는가*** -> 이거네

// 꼭 그렇진 않을거 같은데..
// 만약 자르는 길이가 다른 길이와 +1 차이라면.. 1만 빼주면 구해질 수도 있잖으

// 3. 수학 수식으로 풀까?

// 자른 길이 x 라 하면,
// x / a + x / b + x / c >= N

// 4. 무식하게 풀기
// 1~최댓값 까지 가며 모든 경우의 수 계산

// (1) 아니면 최솟값부터 시작해서 자르는 수로 넣어봐.
// 만약 4번째로 작은건 넉넉했고 5번째로 작은게 부족했으면 , 4 ~ 5 중에 답이 있는거지
// (2) 


#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

void prosetting();
void input();
void solve();

int K, N;
vector<int> Lans;

int main() {
    prosetting();
    input();
    solve();
}

void prosetting() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
}

void input() {
    cin >> K >> N;
    for (int i=0; i<K; i++) {
        int n;
        cin >> n;
        Lans.push_back(n);
    }

    sort(Lans.begin(), Lans.end(), less<int>());
}

void solve() {
    long long start = Lans[0];
    long long end = Lans[K - 1];

    for (int i=0; i<K; i++) {
        int count = 0;
        for (int& e : Lans) {
            count += e / Lans[i];
        }
        if (count < N) {
            if (i == 0) {
                start = 1;
                end = Lans[i];
            }
            else {
                start = Lans[i - 1];
                end = Lans[i];
            }
            break;
        }
    }

    
    long long mid = (start + end) / 2;
    while (start <= end) {
        long long count = 0;
        for (int& len : Lans) {
            count += len / mid; // 0으로 나누면 안되지..
        }

        if (count >= N)
            start = mid + 1;
        else
            end = mid - 1;

        mid = (start + end) / 2;

        //cout << "start = " << start << ", end = " << end << '\n';
    }

    cout << mid;
    
    // int i;
    
    // for (i=start; i<=end; i++) {
    //     int count = 0;
        
    //     if (count < N) break;
    // }

    // cout << --i;
}