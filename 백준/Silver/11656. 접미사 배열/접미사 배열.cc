#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string str;

	cin >> str;
	string* s = new string[str.size()];

	for (int i = 0; i < str.size(); i++) {
		s[i] = str.substr(i);
	}

	sort(s, s + str.size());

	for (int i = 0; i < str.size(); i++) {
		cout << s[i] << '\n';
	}
	


	delete[] s;
	return 0;
}