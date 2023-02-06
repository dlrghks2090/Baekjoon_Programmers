#include<iostream>
#include<string>

using namespace std;

int N;
string str1;
string str2;
string str1_tmp = "";
int sol = 0;

int real_sol = 0;


void change_A(int i, int flag, string &str) {

	if (i == 0) {
		if (flag == 0) {

			if (str[i] == '0') {
				str[i] = '1';
			}
			else {
				str[i] = '0';
			}


			if (str[i + 1] == '0') {
				str[i + 1] = '1';
			}
			else {
				str[i + 1] = '0';
			}
			sol++;
			return;
		}
		
	}
	else if (i == N - 1) {
		if (str[i] != str2[i]) {

			if (str[i] == '0') {
				str[i] = '1';
			}
			else {
				str[i] = '0';
			}


			if (str[i - 1] == '0') {
				str[i - 1] = '1';
			}
			else {
				str[i - 1] = '0';
			}
			sol++;
		}
		return;
	}
	else {
		if (str[i - 1] != str2[i - 1]) {
			if (str[i] == '0') {
				str[i] = '1';
			}
			else {
				str[i] = '0';
			}


			if (str[i - 1] == '0') {
				str[i - 1] = '1';
			}
			else {
				str[i - 1] = '0';
			}

			if (str[i + 1] == '0') {
				str[i + 1] = '1';
			}
			else {
				str[i + 1] = '0';
			}
			sol++;
		}

	}
}

int isSame(string str) {
	for (int i = 0; i < N; i++) {

		//cout << i << "번째 항목 비교 " << "str1 : " << str1[i] << "  str2 : " << str2[i] << endl;
		if (str[i] != str2[i]) {
			return -1;
		}
	}

	return 0;
}

int main() {

	cin >> N;

	cin >> str1;
	cin >> str2;

	str1_tmp += str1;

	for (int i = 0; i < N; i++) {
		change_A(i, 0, str1);
	}

	if (isSame(str1) == -1) {
		real_sol = -1;
	}
	else {
		real_sol = sol;
	}

	sol = 0;

	for (int i = 0; i < N; i++) {
		change_A(i, 1, str1_tmp);
	}

	if (isSame(str1_tmp) == -1) {
		
	}
	else {
		if (real_sol == -1) {
			real_sol = sol;
		}
		else {
			if (real_sol > sol) {
				real_sol = sol;
			}
		}
	}
	

	cout << real_sol;


	return 0;
}