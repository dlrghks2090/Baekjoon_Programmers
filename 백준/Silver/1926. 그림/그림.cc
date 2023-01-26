#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[502][502] = { 0, };
int visit[502][502] = { 0, };
int sol = 0;
int count;

int bfs(int row, int col) {
	queue<pair<int, int>> que;
	pair<int, int> p;
	int count = 1;

	p.first = row;
	p.second = col;
	que.push(p);
	visit[row][col] = 1;
	
	while (1) {
		int r, c;

		if (que.empty() == true) {
			return count;
		}

		r = que.front().first;
		c = que.front().second;
		que.pop();

		if (map[r + 1][c] == 1 && visit[r + 1][c] == 0) {
			p.first = r + 1;
			p.second = c;
			que.push(p);
			visit[r + 1][c] = 1;
			count++;
		}
		if (map[r - 1][c] == 1 && visit[r - 1][c] == 0) {
			p.first = r - 1;
			p.second = c;
			que.push(p);
			visit[r - 1][c] = 1;
			count++;
		}
		if (map[r][c + 1] == 1 && visit[r][c + 1] == 0) {
			p.first = r;
			p.second = c + 1;
			que.push(p);
			visit[r][c + 1] = 1;
			count++;
		}
		if (map[r][c - 1] == 1 && visit[r][c - 1] == 0) {
			p.first = r;
			p.second = c - 1;
			que.push(p);
			visit[r][c - 1] = 1;
			count++;
		}
	}
}

int main() {
	
	int num;
	int count = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				num = bfs(i, j);
				if (sol < num) {
					sol = num;
				}
				count++;
			}
		}
	}

	cout << count << endl;
	cout << sol;

	return 0;
}