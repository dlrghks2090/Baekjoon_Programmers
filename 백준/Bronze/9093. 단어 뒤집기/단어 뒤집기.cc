#include<iostream>
#include<string>
#include<vector>

using namespace std;


// 단어들을 뒤집기 위한 함수
void reverse(string& a, int start, int end, int count) {

	char tmp;
	int k = 0;

	if (count == 1)
		return;

	for (int i = start; i < start + count / 2; i++) {
		tmp = a[i];
		a[i] = a[end - k];
		a[end - k] = tmp;
		++k;
	}


}

int main() {

	int T;
	int count = 0;
	int start = 0;
	int end = 0;
	string str;
	vector<string> v;
	string s;

	cin >> T;


	// cin으로 숫자를 입력하다가 문자열을 입력하니깐 입력 오류가 발생했다.
	// cin.ignore() 을 사용해 입력버퍼를 비워 오류를 해결했다.
	cin.ignore();
	for (int i = 0; i < T; i++) {
		getline(cin,str);
		v.push_back(str);
	}
	
	

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] != ' ') {
				++count;

				// 마지막 단어를 뒤집기위한 코드
				if (j == v[i].size() - 1) {
					end = j;
					reverse(v[i], start, end, count);
				}
			}
			else {
				end = j-1;

				reverse(v[i], start, end, count);

				start = j + 1;
				count = 0;
			}
		}
		start = 0;
		end = 0;
		count = 0;
	}

	for (int i = 0; i < T; i++) {
		cout << v[i] << '\n';
	}


	return 0;
}