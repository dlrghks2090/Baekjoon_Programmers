#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int w, h;
int map[52][52] = { 0, };
int visit[52][52] = { 0, };
int sol = 0;


void bfs(int a, int b) {
	queue<pair<int, int>> que;
	pair<int, int> p;
	int x, y;

	p.first = a;
	p.second = b;

	que.push(p);
	visit[a][b] = 1;

	while (1) {
		if (que.empty() == true) {
			break;
		}
		x = que.front().first;
		y = que.front().second;
		que.pop();

		if (map[x + 1][y] == 1 && visit[x + 1][y] == 0) {
			p.first = x + 1;
			p.second = y;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x - 1][y] == 1 && visit[x - 1][y] == 0) {
			p.first = x - 1;
			p.second = y;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x][y + 1] == 1 && visit[x][y + 1] == 0) {
			p.first = x;
			p.second = y + 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x][y - 1] == 1 && visit[x][y - 1] == 0) {
			p.first = x;
			p.second = y - 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}

		if (map[x + 1][y + 1] == 1 && visit[x + 1][y + 1] == 0) {
			p.first = x + 1;
			p.second = y + 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x + 1][y - 1] == 1 && visit[x + 1][y - 1] == 0) {
			p.first = x + 1;
			p.second = y - 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x - 1][y + 1] == 1 && visit[x - 1][y + 1] == 0) {
			p.first = x - 1;
			p.second = y + 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
		if (map[x - 1][y - 1] == 1 && visit[x - 1][y - 1] == 0) {
			p.first = x - 1;
			p.second = y - 1;
			que.push(p);
			visit[p.first][p.second] = 1;
		}
	}
}

void init() {
	for (int i = 1; i <= 51; i++) {
		for (int j = 1; j <= 51; j++) {
			map[i][j] = visit[i][j] = 0;
		}
	}
}

int main() {

	while (1) {

		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j);
					sol++;
				}
			}
		}

		//cout << '\n';
		cout << sol << endl;
		sol = 0;
		init();

	}


	return 0;
}