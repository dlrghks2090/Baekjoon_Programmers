#include<iostream>

using namespace std;

int sol = 0;

void dfs(int n, int s, int* arr,int idx, int total) {
	if (total == s) {
		++sol;
	}

	for (int i = idx; i <= n; i++) {
		total += arr[i];
		dfs(n, s, arr, i + 1, total);
		total -= arr[i];
	}
}

int main() {

	int N, S;
	int* arr;

	cin >> N >> S;

	arr = new int[N+1];

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	if (S == 0) {
		sol = -1;
	}

	dfs(N, S, arr, 1, 0);

	cout << sol;

	delete[] arr;
	return 0;
}