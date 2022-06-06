#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string first, second;
    cin >> first;
    cin >> second;

    int lcs[41][41];
    
    for (int i = 0; i < first.size() + 1; i++) {
        for (int j = 0; j < second.size() + 1; j++) {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (first[i - 1] == second[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    // for (int i = 0; i < first.size() + 1; i++) {
    //     for (int j = 0; j < second.size() + 1; j++) {
    //         cout << lcs[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    vector<char> reverse_result;

    // 좌로 이동하는 경우
    int i = first.size();
    int j = second.size();
    while (lcs[i][j] != 0) {
        if (lcs[i][j] == lcs[i][j - 1]) 
            j--;
        else if (lcs[i][j] == lcs[i - 1][j]) 
            i--;
        else {
            reverse_result.push_back(first[i - 1]);
            i--; j--;
        }
    }
    // 위로 이동하는 경우
    // int i = first.size();
    // int j = second.size();
    // while (lcs[i][j] != 0) {
    //     if (lcs[i][j] == lcs[i - 1][j]) 
    //         i--;
    //     else if (lcs[i][j] == lcs[i][j - 1]) 
    //         j--;
    //     else {
    //         reverse_result.push_back(first[i - 1]);
    //         i--; j--;
    //     }
    // }

    reverse(reverse_result.begin(), reverse_result.end());
    for (char& e : reverse_result) {
        cout << e;
    }
}