#include<iostream>
#include<string>

using namespace std;

int main() {

	string str;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			if (str[i] <= 'M') {
				str[i] = str[i] + 13;
			}
			else {
				str[i] = 'a' + 13 - ('z' - str[i]) - 1;
			}
			
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			if (str[i] <= 'm') {
				str[i] = str[i] + 13;
			}
			else {
				str[i] = 'a' + 13 - ('z' - str[i]) - 1;
			}
		}

	}

	cout << str;
	

	return 0;
}