#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<char>> Board;

void input();

int main() {
    input();

    int min = 64;
    
    for (int i = 0; i <= M - 8; i++) {
        for (int j = 0; j <= N - 8; j++) {
            int cnt1 = 0;
            int cnt2 = 0;

            char first_c;

            first_c = 'W';
            for (int a = i; a < i + 8; a++) {
                for (int b = j; b < j + 8; b++) {
                    // 짝수 행 : first_c
                    if ((a - i) % 2 == 0) {
                        // 짝수 열 : first_c
                        if ((b - j) % 2 == 0) {
                            if (Board[a][b] != first_c)
                                cnt1 += 1;
                        }
                        // 홀수 열 : first_c와 다른 character
                        else {
                            if (Board[a][b] == first_c)
                                cnt1 += 1;
                        }  
                    }
                    // 홀수 행 : first_c와 다른 character
                    else {
                        // 짝수 열 : first_c
                        if ((b - j) % 2 == 0) {
                            if (Board[a][b] == first_c)
                                cnt1 += 1;
                        }
                        // 홀수 열 : first_c와 다른 character
                        else {
                            if (Board[a][b] != first_c)
                                cnt1 += 1;
                        }  
                    }                          
                }
            }
            
            first_c = 'B';
            for (int a = i; a < i + 8; a++) {
                for (int b = j; b < j + 8; b++) {
                    // 짝수 행 : first_c
                    if ((a - i) % 2 == 0) {
                        // 짝수 열 : first_c
                        if ((b - j) % 2 == 0) {
                            if (Board[a][b] != first_c)
                                cnt2 += 1;
                        }
                        // 홀수 열 : first_c와 다른 character
                        else {
                            if (Board[a][b] == first_c)
                                cnt2 += 1;
                        }  
                    }
                    // 홀수 행 : first_c와 다른 character
                    else {
                        // 짝수 열 : first_c
                        if ((b - j) % 2 == 0) {
                            if (Board[a][b] == first_c)
                                cnt2 += 1;
                        }
                        // 홀수 열 : first_c와 다른 character
                        else {
                            if (Board[a][b] != first_c)
                                cnt2 += 1;
                        }  
                    }                          
                }
            }

            //cout << cnt1 << " " << cnt2 << endl;

            if (min > cnt1) min = cnt1;
            if (min > cnt2) min = cnt2;
        }
    }

    cout << min;

    // cout << "===Check Input===\n";
    // for (auto row : Board) {
    //     for (auto c : row)
    //         cout << c;
    //     cout << endl;
    // } 
}

void input() {
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        vector<char> row;
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            row.push_back(c);
        }
        Board.push_back(row);
    }
}