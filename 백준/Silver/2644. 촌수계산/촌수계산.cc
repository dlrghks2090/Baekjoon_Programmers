#include<iostream>

using namespace std;


int map[102][102] = { 0, };
int visit[102] = { 0, };
int n, m;
int people1, people2;
int sol = -1;

void dfs(int num, int count) {
	if (num == people2) {
		sol = count;
		return;
	}
	visit[num] = 1;

	for (int i = 1; i <= n; i++) {
		if (map[num][i] == 1 && visit[i] == 0) {
			dfs(i, count + 1);
			
		}
	}
}

int main() {

	int x;
	int y;

	cin >> n;
	cin >> people1 >> people2;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	dfs(people1, 0);

	cout << sol;

	return 0;
}