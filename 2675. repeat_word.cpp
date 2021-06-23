#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int testnum;
	cin >> testnum;

	vector<string> str;
	int *repeatnum = new int[testnum];

	for (int i = 0; i < testnum; i++) {
		string cstr;
		cin >> repeatnum[i] >> cstr;
		str.push_back(cstr);
	}

	for (int i = 0; i < testnum; i++) {
		for (int j = 0; j < str[i].size(); j++) {
			for (int k = 0; k < repeatnum[i]; k++) {
				cout << str[i].at(j);
			}
		}
		cout << endl;
	}

	delete[] repeatnum;

}