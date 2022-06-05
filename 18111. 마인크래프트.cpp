#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, b;
    cin >> n >> m >> b;

    int map[501][501];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int n;
            cin >> n;
            map[i][j] = n;
        }
    }

    const int TIME_BUILD = 1;
    const int TIME_REMOVE = 2;

    int leastTime = 987654321;
    int maxHeight = -1;
    
    for (int h = 0; h <= 256; h++) {
        int surplus = 0;
        int empty = 0;

        // update current build, remove block count
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (map[i][j] > h) surplus += map[i][j] - h;
                else if (map[i][j] < h) empty += h - map[i][j];
            }
        }

        // continue, when not enough blocks to build
        if (empty > surplus + b) continue;

        int time = empty * TIME_BUILD + surplus * TIME_REMOVE;
        int height = h;
        if (leastTime >= time) {
            leastTime = time;
            maxHeight = height;
        }
    }

    cout << leastTime << " " << maxHeight;

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// #define TIME_REM    2
// #define TIME_INS    1

// pair<int, int> minecraft(vector<vector<int>>, int, int);
// vector<vector<int>> cutFloor(vector<vector<int>>, int);
// int getEmptyBlock(vector<vector<int>>&);
// int getFloorBlock(vector<vector<int>>&);
// void printVecVec(vector<vector<int>>&);
// bool compVec(vector<int> a, vector<int> b) {
//     if (a[0] > b[0]) return true;
//     return false;
// }

// int main() {
//     cin.tie(NULL); cout.tie(NULL);
//     ios::sync_with_stdio(false);

//     int N, M;
//     long long B;
//     cin >> N >> M >> B;

//     vector<vector<int>> blocks;
//     for (int i=0; i<N; i++) {
//         vector<int> floor;
//         for (int j=0; j<M; j++) {
//             int n;
//             cin >> n;
//             floor.push_back(n);
//         }
//         sort(floor.begin(), floor.end(), greater<int>());
//         blocks.push_back(floor);
//     }
//     sort(blocks.begin(), blocks.end(), compVec);

//     pair<int, int> timeHeight = minecraft(blocks, B, 0);

//     cout << timeHeight.first << " " << timeHeight.second;

//     //cout << "time : " << timeHeight.first << ", height : " << timeHeight.second << '\n';
// }

// // @param : sorted vector
// // return : pair of 'price' and 'height'
// pair<int, int> minecraft(vector<vector<int>> blocks, int B, int price) {
//     // 채우기 vs 한칸 내려가기(max height > min height)
//     // 1) 채우기
//     // 보유 중인 블럭이 빈 칸보다 많아야함
//     // 2) 한칸 내려가기, max height == min height 면 끝 !
//     // 최상층을 한칸 깎고, 보유 블럭 추가 후 재귀
    
//     int row = blocks[0].size();
//     int col = blocks.size();
//     int maxHeight = blocks[0][0];
//     int minHeight = blocks[col - 1][row - 1];

//     // 평평함
//     if (maxHeight == minHeight) return make_pair(price, maxHeight);

//     int empty = getEmptyBlock(blocks);
//     int floor = getFloorBlock(blocks);    

//     int fillPrice, cutPrice;

//     // 인벤토리 충분
//     if (B >= empty) {
//         fillPrice = empty * TIME_INS;
//         cutPrice = floor * TIME_REM;

//         // 층 깎아서 재귀
//         vector<vector<int>> cutBlocks = blocks;
//         for (int i=0; i<col; i++) {
//             for (int j=0; j<row; j++) {
//                 if (cutBlocks[i][j] == maxHeight)
//                     cutBlocks[i][j]--;
//                 else
//                     break;
//             }
//         }
//         if (fillPrice < minecraft(cutBlocks, B + floor, price + cutPrice).first) {
//             return make_pair(price + fillPrice, maxHeight);
//         }
//         else if (fillPrice > minecraft(cutBlocks, B + floor, price + cutPrice).first) {
//             return minecraft(cutBlocks, B + floor, price + cutPrice);
//         }
//         else {
//             if (maxHeight >= minecraft(cutBlocks, B + floor, price + cutPrice).second)
//                 return make_pair(price + fillPrice, maxHeight);
//             else
//                 return minecraft(cutBlocks, B + floor, price + cutPrice);
//         }
//     }
//     // 인벤토리 불충분
//     else {
//         cutPrice = floor * TIME_REM;

//         // 층 깎아서 재귀
//         vector<vector<int>> cutBlocks = blocks;
//         for (int i=0; i<col; i++) {
//             for (int j=0; j<row; j++) {
//                 if (cutBlocks[i][j] == maxHeight)
//                     cutBlocks[i][j]--;
//                 else
//                     break;
//             }
//         }
//         return minecraft(cutBlocks, B + floor, price + cutPrice);
//     }
// }

// int getEmptyBlock(vector<vector<int>>& blocks) {
//     int empty = 0;
//     int maxHeight = blocks[0][0];
//     for (vector<int>& floor : blocks) {
//         for (int& e : floor) {
//             empty += maxHeight - e;
//         }
//     }
//     //cout << "There is " << empty << " empty blocks\n";

//     return empty;
// }

// int getFloorBlock(vector<vector<int>>& blocks) {
//     int floor = 0;
//     int maxHeight = blocks[0][0];
//     for (vector<int>& f : blocks) {
//         for (int& e : f) {
//             if (maxHeight == e)
//                 floor += 1;
//             else
//                 break;
//         }
//     }
//     //cout << "There is " << floor << " blocks on this floor\n";

//     return floor;
// }

// void printVecVec(vector<vector<int>>& vv) {
//     cout << "====================\n";
//     for (auto& v : vv) {
//         for (auto& e : v)
//             cout << e << " ";
//         cout << '\n';
//     }
//     cout << "====================\n";
// }