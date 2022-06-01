#include<iostream>
#include<algorithm>

using namespace std;

int visit[1001] = { 0, };
int map[1001][1001] = { 0, };
int N, M;

void dfs(int n) {
	visit[n] = 1; // 방문한 곳을 1로 처리한다.
	for (int i = 1; i <= N; i++) {
		if (map[n][i] && visit[i] == 0)
			dfs(i);
	}
}

int main() {


	int a, b;
	int sol = 0;

	cin >> N >> M;


	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	dfs(1);
	++sol;
	for (int i = 2; i <= N; i++) {
		if (visit[i] == 0) {
			dfs(i);
			++sol;
		}
	}

	cout << sol;

	return 0;
}