#include<iostream>
#include<algorithm>

using namespace std;

int arr[9] = { 0, };
int visit[9] = { 0, };
int sol[9] = { 0, };


void dfs(int n, int m, int count) {
	if (count == m) {
		for (int i = 1; i <= m; i++) {
			cout << sol[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] != 1) {
			visit[i] = 1;
			sol[count + 1] = arr[i];
			dfs(n, m, count + 1);
			visit[i] = 0;
		}
	}
}

int main() {

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr+1, arr + N+1);



	dfs(N, M, 0);



	return 0;
}