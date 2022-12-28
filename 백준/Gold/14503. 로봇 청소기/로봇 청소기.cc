#include<iostream>

using namespace std;

int N, M;
int map[52][52] = { 0, };
int visit[52][52] = { 0, };
//int visit_2[52][52] = { 0, };
int r, c, d;
int sol = 0;

int four_total;
int dir_r;
int dir_c;
int dir_map[4] = { -1, 1, 1, -1 };

void dfs(int x, int y, int direction) {
	int r1 = x;
	int c1 = y;
	int dir = direction;

	if (visit[r1][c1] == 0) {
		visit[r1][c1] = 1;
		
		sol += 1;
		/*visit_2[r1][c1] = sol + 2;

		cout << "================= 방문한 지점들 표시 ================" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << visit_2[i][j] << "   ";
			}
			cout << endl << endl;;
		}*/
	}

	if (dir % 2 == 0) {
		dir_r = dir_map[dir];
		dir_c = 0;
	}
	else {
		dir_c = dir_map[dir];
		dir_r = 0;
	}
	four_total = visit[r1 + 1][c1] + visit[r1 - 1][c1] + visit[r1][c1 + 1] + visit[r1][c1 - 1];
	if (four_total == 4) {
		if (map[r1 + dir_r * -1][c1 + dir_c * -1] == 0) {
			r1 = r1 + dir_r * -1;
			c1 = c1 + dir_c * -1;
			dfs(r1, c1, dir);
		}
	}
	else {
		dir = dir - 1;
		if (dir == -1) {
			dir = 3;
		}

		if (dir % 2 == 0) {
			dir_r = dir_map[dir];
			dir_c = 0;
		}
		else {
			dir_c = dir_map[dir];
			dir_r = 0;
		}

		if (map[r1 + dir_r][c1 + dir_c] == 0 && visit[r1 + dir_r][c1 + dir_c] == 0) {
			r1 = r1 + dir_r;
			c1 = c1 + dir_c;

			dfs(r1, c1, dir);
		}
		else {
			dfs(r1, c1, dir);
		}

	}
}


int main() {

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visit[i][j] = map[i][j];
			//visit_2[i][j] = map[i][j];
		}
	}

	dfs(r, c, d);

	cout << sol << endl;

	/*cout << "================= 방문한 지점들 표시 ================" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}