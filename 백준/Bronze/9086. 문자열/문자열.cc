#include<iostream>
#include<string>

using namespace std;

int main() {

	int T;


	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;


		cout << str[0] << str[str.size() - 1] << endl;

	}

	return 0;
}