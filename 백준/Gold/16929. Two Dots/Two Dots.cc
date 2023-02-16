#include<iostream>
#include<string>

using namespace std;

int N, M;
bool sol;
char map[51][51] = { 0, };
int visit[51][51] = { 0, };

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int start_y;
int start_x;

void dfs(int y, int x, int count) {

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ry = y + dy[i];
		int rx = x + dx[i];

		if (ry >= 0 && ry < N && rx >= 0 && rx < M && map[y][x] == map[ry][rx] && visit[ry][rx] == 0) {
			dfs(ry, rx, count + 1);
		}
		else if (start_y == ry && start_x == rx && count >= 4) {
			sol = true;
			return;
		}
	}

}

void init_visit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			start_y = i;
			start_x = j;
			dfs(i, j, 1);

			if (sol == true) {
				cout << "Yes";
				return 0;
			}

			init_visit();
		}
	}

	cout << "No";
	return 0;
}