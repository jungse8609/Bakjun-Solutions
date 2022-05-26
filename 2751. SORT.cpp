/* 
큰 목록에 대한 정렬을 할 때,
금지 : 버블, 퀵 등등 (최악 N ^ 2)
추천 : 병합, 힙 !!!

아래 코드는 병합 정렬(merge sort)에 대한 것임
힙 정렬(heap sort) 구현에 대해서도 공부 필요
========================================
걍 sort -> stable_sort 하면 해결됨...
sort : 불안정 정렬 - 비교 순위 동일 시 어찌 정렬될지 모름
stable_sort : 안정 정렬 - 비교 순위 동일 시 index 순서로 정렬(그대로 유지)
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Age {
public:
    int age;
    string name;
    int id;

    Age(int age, string name, int id) {
        this->age = age;
        this->name = name;
        this->id = id;
    }
};

bool compare_age(Age a, Age b) {
    if (a.age == b.age) {
        return a.id < b.id;
    }
    else {
        return a.age < b.age;
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x;
    cin >> x;
    vector<Age> v;
    for (int i = 0; i < x; i++) {
        int a;
        string b;
        cin >> a >> b;
        Age age = Age(a, b, i);
        v.push_back(age);
    }

    stable_sort(v.begin(), v.end(), compare_age);
    
    for (int i = 0; i < x; i++) {
        cout << v[i].age << " " << v[i].name << "\n";
    }
    return 0;
}