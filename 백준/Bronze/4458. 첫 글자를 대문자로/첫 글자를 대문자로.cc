#include<iostream>
#include<string>

using namespace std;

int main() {

	int N;
	string* str;

	cin >> N;
	str = new string[N];
	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin,str[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= str[i].size(); j++) {
			if (97 <= str[i][0] && str[i][0] <= 122) {
				str[i][0] = str[i][0] - 32;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << str[i] << endl;
	}

	delete[] str;
	return 0;
}