#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> nums;    
    
    int mean, median, mode, range;

    double sum = 0.0; // 이거를 float -> double 바꾸니 바로 해결....!!!
    
    int negArr[4001] = { 0, };
    int pogArr[4001] = { 0, };
    vector<int> maxValueVec;
    int max = -1;
    
    for (int i=0; i<N; i++) {
        int n;
        cin >> n;

        // values 합 저장
        sum += n;

        // 최빈값 저장
        // 가장 많은 value의 수와 비교해 같으면 max Value Vector에 추가
        // 비교해 더 크다면 vector 초기화 후 추가
        int index = abs(n);
        if (n >= 0) {
            pogArr[index]++;
            if (pogArr[index] > max) {
                max = pogArr[index];
                maxValueVec.clear();
                maxValueVec.push_back(n);
            }
            else if (pogArr[index] == max) {
                maxValueVec.push_back(n);
            }
        }
        else {
            negArr[index]++;
            if (negArr[index] > max) {
                max = negArr[index];
                maxValueVec.clear();
                maxValueVec.push_back(n);
            }
            else if (negArr[index] == max) {
                maxValueVec.push_back(n);
            }
        }
        
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end(), less<int>());
    sort(maxValueVec.begin(), maxValueVec.end(), less<int>());

    cout << "nums vector\n";
    for (auto e : nums)
        cout << e << " ";
    cout << '\n';
    
    cout << "max value vector\n";
    for (auto e : maxValueVec)
        cout << e << " ";
    cout << '\n';

    cout << "result\n";

    mean = round(sum / N);
    median = nums[N / 2];
    
    if (maxValueVec.size() == 1)
        mode = maxValueVec[0];
    else
        mode = maxValueVec[1];
    range = nums[N - 1] - nums[0];

    cout << mean << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';
}