/* 
큰 목록에 대한 정렬을 할 때,
금지 : 버블, 퀵 등등 (최악 N ^ 2)
추천 : 병합, 힙 !!!

아래 코드는 병합 정렬(merge sort)에 대한 것임
힙 정렬(heap sort) 구현에 대해서도 공부 필요
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void printVector(const vector<T> &vec) {
    for (auto &i : vec) {
        cout << i << '\n';
    }
    cout << '\n';
}

template<typename T>
void merge(vector<T> &vec, vector<T> &v1, vector<T> &v2) {
    auto siz1 = v1.size();
    auto siz2 = v2.size();
    size_t p1 = 0;
    size_t p2 = 0;

    while (p1 < siz1 && p2 < siz2) {
        if (v1.at(p1) < v2.at(p2))
            vec.push_back(v1.at(p1++));
        else
            vec.push_back(v2.at(p2++));
    }

    while (p1 < siz1) vec.push_back(v1.at(p1++));
    while (p2 < siz2) vec.push_back(v2.at(p2++));
}

template<typename T>
void mergeSort(vector<T> &vec) {
    if (vec.size() <= 1)
        return;

    auto iter = vec.begin() + vec.size() / 2;
    vector<T> v1 (vec.begin(), iter);
    vector<T> v2 (iter, vec.end());

    mergeSort(v1); // 정렬된 v1과
    mergeSort(v2); // 정렬된 v2가 완성!!
                    // 그걸 아래서 합치면 끝!!
    vec.clear();    
    
    merge(vec, v1, v2);
}

int main() {
    int N;
    cin >> N;

    vector<int> vec1;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        vec1.push_back(num);
    }

    // printVector(vec1);
    mergeSort(vec1);
    printVector(vec1);
}