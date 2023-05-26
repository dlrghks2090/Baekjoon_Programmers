#include<iostream>
#include<string>

using namespace std;

int main() {

	string str;
	int sol = 0;
	int fe = 0;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			fe += 1;
		}
		else if (str[i] == ')') {
			if (str[i - 1] == '(') {
				fe -=1;
				sol += fe;
			}
			else {
				sol += 1;
				fe -= 1;
			}
		}
	}
	cout << sol;


	return 0;
}