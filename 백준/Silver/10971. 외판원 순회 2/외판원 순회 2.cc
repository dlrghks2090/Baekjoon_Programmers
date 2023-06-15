#include<iostream>

using namespace std;

int N;
int arr[12][12] = { 0, };
int visit[12] = { 0, };
int order[12] = { 0, };
int sol = 100000000;

void dfs(int now_idx, int count, int total) {
	if (count == N) {
		if (arr[now_idx][order[1]] != 0) {
			total += arr[now_idx][order[1]];
			if (total < sol) {
				sol = total;
			}
		}
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (count == 0) {
			visit[i] = 1;
			order[count + 1] = i;
			dfs(i, count + 1, total);
			visit[i] = 0;
		}
		else if (arr[now_idx][i] != 0) {
			if (visit[i] == 0) {
				visit[i] = 1;
				order[count + 1] = i;
				dfs(i, count + 1, total + arr[now_idx][i]);
				visit[i] = 0;
			}
		}
	}
}

int main() {


	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << sol;


	return 0;
}