#include<iostream>

using namespace std;

int arr[9] = { 0, };
int check[9] = { 0, };


void dfs(int n, int count) {
	if (count > n) {
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {

		if (check[i] != 1) {
			arr[count] = i;
			check[i] = 1;
			dfs(n, count + 1);
			check[i] = 0;
		}
	}
}

int main() {

	int N;

	cin >> N;

	dfs(N, 1);


	return 0;
}