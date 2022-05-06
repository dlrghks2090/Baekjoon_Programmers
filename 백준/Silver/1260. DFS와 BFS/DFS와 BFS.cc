#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int map[1001][1001];
int visit[1001];
int N;
queue<int> q;
stack<int> st;






void dfs(int v) {
	
	cout << v << " ";
	visit[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visit[i] == 0) {
			dfs(i);
		}
	}



}

void bfs(int start) {
	
	cout << start << " ";
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (map[node][i] == 1 && visit[i] == 0) {
				visit[node] = 1;
				visit[i]=1;
				cout << i << " ";
				q.push(i);
			}
		}
		//cout << '\n';

	}



}


int main() {

	int M, V;
	

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}


	dfs(V);
	cout << '\n';
	//cout << "---------------" << '\n';
	fill_n(visit, N + 1, 0);

	bfs(V);




	return 0;
}