#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arr[1001][1001] = { 0, };
int visit[1001] = { 0, };
int sol[10001] = { 0, };
int flag = 0;
int N, M, V;
int a, b;


void init_visit(int n) {

	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
}


void dfs(int idx) {
	cout << idx << " ";
	visit[idx] = 1;

	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0 && arr[idx][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int idx, int n) {
	queue<int> que;

	que.push(idx);
	visit[idx] = 1;

	while (!que.empty()) {
		int tmp = que.front();
		que.pop();
		cout << tmp << " ";

		for (int i = 1; i <= n; i++) {
			if (arr[tmp][i] == 1 && visit[i] == 0) {
				que.push(i);
				visit[i] =1;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	cin >> N >> M >> V;

	

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}

	dfs(V);
	cout << '\n';
	init_visit(N);
	bfs(V, N);
	


	return 0;
}
