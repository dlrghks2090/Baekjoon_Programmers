#include<iostream>
#include<string>

using namespace std;

int main() {

	string str;
	string sol = "";

	cin >> str;

	sol.push_back(str[0]);
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '-') {
			sol.push_back(str[i + 1]);
		}
	}

	cout << sol;


	return 0;
}