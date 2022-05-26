#include<iostream>
#include<queue>

using namespace std;

int N;
int map[101][101] = { 0, };
int visit[101] = { 0, };
queue<int> q;

int bfs(int n) {
	int count = 0;
	int node;

	q.push(n);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		//cout << node <<'\n';
		++count;
		visit[node] = 1;
		for (int i = 1; i <= N; i++) {
			if (map[node][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
			}
		}

	}

	return (count);
}

int main() {

	int a, b;
	int edge;

	cin >> N;
	cin >> edge;
	for (int i = 1; i <= edge; i++) {
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	cout << bfs(1) - 1 << endl;


	return 0;
}