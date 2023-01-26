#include<iostream>
#include<queue>

using namespace std;

int M, N, H;

int map[102][102][102];
int visit[102][102][102] = { 0, };
int sol = 0;

void map_init() {

	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			for (int k = 0; k < 102; k++) {
				map[i][j][k] = -1;
			}
		}
	}
}

int check() {
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (map[i][j][k] == 0) {
					return -1;
				}
			}
		}
	}

	return 0;
}


void bfs() {
	queue<pair<int, int>> que_1;
	queue<pair<int,int>> que_2;

	pair<int, int> p1;
	pair<int, int> p2;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (map[i][j][k] == 1) {
					p1.first = i;
					p1.second = j;
					que_1.push(p1);

					p2.first = k;
					p2.second = 0;
					que_2.push(p2);

					visit[i][j][k] = 1;
				}
			}
		}
	}

	while (1) {
		int x, y, z;
		int count;

		if (que_1.empty() == true) {
			if (check() == -1) {
				cout << -1;
			}
			else {
				cout << p2.second;
			}

			break;
		}

		x = que_1.front().first;
		y = que_1.front().second;
		z = que_2.front().first;
		count = que_2.front().second;

		que_1.pop();
		que_2.pop();

		if (map[x + 1][y][z] == 0 && visit[x + 1][y][z] == 0) {
			p1.first = x + 1;
			p1.second = y;
			p2.first = z;
			p2.second = count + 1;

			que_1.push(p1);
			que_2.push(p2);
			map[x + 1][y][z] = 1;
			visit[x + 1][y][z] = 1;
		}

		if (map[x - 1][y][z] == 0 && visit[x - 1][y][z] == 0) {
			p1.first = x - 1;
			p1.second = y;
			p2.first = z;
			p2.second = count + 1;

			que_1.push(p1);
			que_2.push(p2);
			map[x - 1][y][z] = 1;
			visit[x - 1][y][z] = 1;
		}

		if (map[x][y + 1][z] == 0 && visit[x][y + 1][z] == 0) {
			p1.first = x;
			p1.second = y + 1;
			p2.first = z;
			p2.second = count + 1;

			que_1.push(p1);
			que_2.push(p2);
			map[x][y + 1][z] = 1;
			visit[x][y + 1][z] = 1;
		}

		if (map[x][y - 1][z] == 0 && visit[x][y - 1][z] == 0) {
			p1.first = x;
			p1.second = y - 1;
			p2.first = z;
			p2.second = count + 1;

			que_1.push(p1);
			que_2.push(p2);
			map[x][y - 1][z] = 1;
			visit[x][y - 1][z] = 1;
		}

		if (map[x][y][z + 1] == 0 && visit[x][y][z + 1] == 0) {
			p1.first = x;
			p1.second = y;
			p2.first = z + 1;
			p2.second = count + 1;

			que_1.push(p1);
			que_2.push(p2);
			map[x][y][z + 1] = 1;
			visit[x][y][z + 1] = 1;
		}

		if (map[x][y][z - 1] == 0 && visit[x][y][z - 1] == 0) {
			p1.first = x;
			p1.second = y;
			p2.first = z - 1;
			p2.second = count + 1;

			que_1.push(p1);
			que_2.push(p2);
			map[x][y][z - 1] = 1;
			visit[x][y][z - 1] = 1;
		}

	}


}

int main() {

	cin >> M >> N >> H;

	map_init();

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> map[i][j][k];
			}
		}
	}

	if (check() == 0) {
		cout << 0;
		return 0;
	}

	bfs();


	return 0;
}