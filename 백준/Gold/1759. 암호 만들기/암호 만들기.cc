#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int L, C;
char arr[16] = { 0, };
char sol[16] = { 0, };
string mo = "aeiou";


void dfs(int idx, int count) {

	if (count == L) {
		int mo_n = 0;
		int ja_n = 0;
		
		for (int i = 1; i <= L; i++) {
			for (int j = 0; j < mo.size(); j++) {
				if (sol[i] == mo[j]) {
					mo_n++;
					break;
				}
			}
		}

		ja_n = L - mo_n;

		if (mo_n >= 1 && ja_n>= 2) {
			for (int k = 1; k <= L; k++) {
				cout << sol[k];
			}
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i <= C; i++) {
		sol[count+1] = arr[i];
		dfs(i+1, count + 1);
	}
}

int main() {

	cin >> L >> C;

	for (int i = 1; i <= C; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + C);

	dfs(1,0);


	return 0;
}