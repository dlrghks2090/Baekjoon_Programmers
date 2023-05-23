#include<iostream>
#include<string>

using namespace std;



int main() {

	string* str;
	int* sol_of_str;
	int T;
	int count = 0;

	cin >> T;
	str = new string[T];
	sol_of_str = new int[T];


	for (int i = 0; i < T; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < T; i++) {
		sol_of_str[i] = 0;
		//cout << i << " 번째 분석----------------" << '\n';
		for (int j = 0; j < str[i].size(); j++) {
			
			if (str[i][j] == '(') {
				++count;
				//cout << '(' << " 확인 count+1 :" << count <<'\n';
			}
				
			else if (str[i][j] == ')') {
				--count;
				// 닫는괄호가 먼저 나올 때 no로 확정시킨다.  ex> ())(
				if (count < 0)
					break;
				//cout << ')' << " 확인 count-1 :"<< count << '\n';
			}
				
		}
		if (count == 0)
			sol_of_str[i] = 1;
		else
			sol_of_str[i] = 0;
		count = 0;
	}

	for (int i = 0; i < T; i++) {
		if (sol_of_str[i] == 1)
			cout << "YES" << '\n';
		else if (sol_of_str[i] == 0)
			cout << "NO" << '\n';
	}

	delete[] str;
	delete[] sol_of_str;

	return 0;
}