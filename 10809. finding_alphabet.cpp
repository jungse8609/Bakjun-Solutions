#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 97; i < 123; i++) {
		cout << (int)str.find(i) << ' ';
	}

	string a = "Hello world !!";
	// find: 존재하면 index 반환, npos: 존재x
	if (a.find("world") != string::npos) {
		cout << "true"; // world는 존재하니 true 반환
	}

	//char word[102];
	//char rword[102];
	//int alphabet[26]; // Save alphabets
	//for (int i = 0; i < 26; i++) {
	//	alphabet[i] = -1;
	//}
	//cin >> word;
	//// reverse word
	//for (int i = 0; i < strlen(word); i++) {
	//	rword[i] = word[strlen(word) - i - 1];
	//}
	//rword[strlen(word)] = '\0';
	//// save
	//for (int i = 0; i < strlen(rword); i++) {
	//	int n;
	//	n = rword[i] - 97;
	//	alphabet[n] = strlen(rword) - i - 1;
	//}
	//// output
	//for (int i = 0; i < 26; i++) {
	//	cout << alphabet[i] << ' ';
	//}
}