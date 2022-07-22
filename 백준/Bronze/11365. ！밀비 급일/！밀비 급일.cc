#include<iostream>
#include<string>

using namespace std;

int main() {

	while (1) {
		string str;

		getline(cin, str);

		if (str.compare("END") == 0) {
			break;
		}
		else {
			for (int i = str.size() - 1; i >= 0; i--) {
				cout << str[i];
			}
			cout << endl;
		}
	}

	return 0;
}