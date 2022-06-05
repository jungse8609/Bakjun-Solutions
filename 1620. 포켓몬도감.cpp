#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    unordered_map<int, string> id_name;
    unordered_map<string, int> name_id;

    for (int id=1; id<=n; id++) {
        string name;
        cin >> name;

        id_name.insert(make_pair(id, name));
        name_id.insert(make_pair(name, id));
    }

    while (m-- > 0) {
        string input;
        cin >> input;

        // 입력이 숫자
        try {
            cout << id_name[stoi(input)] << '\n';
        }
        catch (exception& e) {
            cout << name_id[input] << '\n';
        }
    }
}