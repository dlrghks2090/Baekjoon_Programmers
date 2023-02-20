#include<iostream>

using namespace std;

int N;
int arr[10] = { 0, };

void dfs(int count) {

	if (count == N) {
		for (int i = 1; i <= N; i++) {

			cout << arr[i];
			if (i != N) {
				cout << " ";
			}
			else {
				cout << '\n';
			}
		}
		return;
	}



	for (int i = 1; i <= N; i++) {
		int flag = 0;
		for (int j = 1; j <= count; j++) {
			if (arr[j] == i) {
				flag = 1;
			}
		}

		if (flag == 1) {
			continue;
		}

		arr[count + 1] = i;
		dfs(count + 1);
	}
}

int main() {

	cin >> N;

	dfs(0);


	return 0;
}