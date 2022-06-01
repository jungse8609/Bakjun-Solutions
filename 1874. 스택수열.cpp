// === 생각의 과정 ===

// 안되는 경우
// 1) 4 2 3 -> 중간값 뛰어넘기

// 구현
// 1. 문제 순서대로 진행?

// 1) 첫번째 수만큼 스택 넣어.
// 2) 두번째 수를 넣어, 이때 1~n 의 순서는 변함이 없음
// 	이미 4까지 왔다면 그 다음은 5가 와야지
// 3) 모순이 있다면 false, 없다면 true


// ex) 8 4 3 6 8 7 5 2 1
// 1) 1 2 3 4 ++++
// 2) 1 2 3    -
// 3) 1 2	  - -
// 4) 1 2 5 6 + +
// 5) 1 2 5    -
// 6) 1 2 5 7 8 + +
// 7) 1 2 5 7 -
// 8) 1 2 5 -
// 9) 1 2 -
// 10) 1 -
// 11) -

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> intStack;
    vector<int> arrVec;
    vector<int> result; // 0: push, 1: pop
    bool isValid = false;
    
    for (int i=0; i<n; i++) {
        int e;
        cin >> e;
        arrVec.push_back(e);
    }

    int j = 0;
    for (int i = 1; j < n; ) {
        // if (!intStack.empty())
        //     cout << intStack.top() << " ";
        
        // 아무것도 없을 때
        if (intStack.empty()) {
            if (i > arrVec[j])
                break;
            intStack.push(i++);
            result.push_back(0);
        }
        else {
            // stack top이 해당 수보다 클 때
            if (intStack.top() < arrVec[j]) {
                if (i > arrVec[j]) 
                    break;
                intStack.push(i++);
                result.push_back(0);
            }
            // stack top이 해당 수보다 작을 때
            else if (intStack.top() > arrVec[j]) {
                intStack.pop();
                result.push_back(1);
            }
            // 원하는 수에 도달
            else if (intStack.top() == arrVec[j]) {
                intStack.pop();
                result.push_back(1);
                j++;

                if (j >= n) {
                    isValid = true;
                    break;
                }
            }
        }        
    }


    // answer
    if (isValid){
        for (int e : result) {
            if (e == 0) cout << "+\n";
            if (e == 1) cout << "-\n";
        }
    }
    else {
        cout << "NO";
    }    
}