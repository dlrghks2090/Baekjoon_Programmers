#include<iostream>
#include<queue>

using namespace std;


int map[52][52] = { 0, };
int visit[52][52] = { 0, };

void init() {

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

void bfs(int h, int w) {
	queue < pair<int, int>> que;
	pair<int, int> p;
	int check_w[8] = {0,1,1,1,0,-1,-1,-1};
	int check_h[8] = {-1,-1,0,1,1,1,0,-1};

	p.first = h;
	p.second = w;
	que.push(p);
	visit[h][w] = 1;

	while (!que.empty()) {
		int h1 = que.front().first;
		int w1 = que.front().second;
		que.pop();

		for (int k = 0; k < 8; k++) {
			if (map[h1 + check_h[k]][w1 + check_w[k]] == 1 && visit[h1 + check_h[k]][w1 + check_w[k]] == 0) {
				p.first = h1 + check_h[k];
				p.second = w1 + check_w[k];
				que.push(p);
				visit[h1 + check_h[k]][w1 + check_w[k]] = 1;
			}
		}
	}
}

int main() {

	int w, h;
	int sol = 0;

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

		cout << sol << endl;

		sol = 0;
		init();
	}



	return 0;
}