#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    queue<int> result;

    while (K-- > 0) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> num; // id, value
        vector<pair<int, int>> sortedNum;
        queue<int> maxValueQ;
        for (int i=0; i<N; i++) {
            int n;
            cin >> n;
            num.push(make_pair(i, n));
            sortedNum.push_back(make_pair(i, n));
        }

        // value 내림차순으로 maxValueQueue에 push
        sort(sortedNum.begin(), sortedNum.end(), comp);
        for (auto& pair : sortedNum) {
            maxValueQ.push(pair.second);
        }

        int count = 1;
        while (!num.empty()) {
            // 우선 순위 숫자일 때 - max value와 비교 !!
            if (num.front().second == maxValueQ.front()) {
                // 원하는 차례일 때
                if (num.front().first == M) {
                    result.push(count);
                    break;
                }
                // 차례가 아닐 때
                else {
                    num.pop();
                    maxValueQ.pop();
                    count ++;
                }
            }
            // 우선 순위가 아니면 뒤로 보내
            else {
                num.push(num.front());
                num.pop();
            }
        }
    }

    // 결과 출력
    while (!result.empty()) {
        cout << result.front() << '\n';
        result.pop();
    }
}