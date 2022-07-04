#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "aeiou";
	string s;
	int sol = 0;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < str.size(); j++) {
			if (s[i] == str[j]) {
				sol++;
				break;
			}
		}
	}

	cout << sol << endl;


	return 0;
}