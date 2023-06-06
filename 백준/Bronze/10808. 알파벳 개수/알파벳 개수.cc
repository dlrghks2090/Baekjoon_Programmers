#include<iostream>
#include<string>

int arr[26] = { 0, };

using namespace std;

int main() {

	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		arr[(str[i] - '0') - ('a' - '0')] += 1;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}