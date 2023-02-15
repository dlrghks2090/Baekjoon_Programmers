#include<iostream>
#include<queue>
#include<string>

#define INF 1000000

using namespace std;

int N, M;
int dp[102][102];
int map[102][102];

int d_row[4] = { 0, 1, 0, -1 };
int d_col[4] = { 1, 0, -1, 0 };


void bfs() {
	queue<pair<int, int>> que;
	
	que.push({ 1,1 });
	dp[1][1] = 0;

	while (!que.empty()) {
		int r_row = que.front().first;
		int r_col = que.front().second;

		que.pop();


		//cout << "======== 개수 : " << dp[N][M] << endl;

		for (int i = 0; i < 4; i++) {
			int t_row = r_row + d_row[i];
			int t_col = r_col + d_col[i];

			if (t_col < 1 || t_col > N || t_row < 1 || t_row > M) {
				continue;
			}

			if (map[t_row][t_col] == 1) {
				if (dp[t_row][t_col] > dp[r_row][r_col] + 1) {
					dp[t_row][t_col] = dp[r_row][r_col] + 1;
					que.push({ t_row, t_col });
				}
			}
			else if (map[t_row][t_col] == 0) {
				if (dp[t_row][t_col] > dp[r_row][r_col]) {
					dp[t_row][t_col] = dp[r_row][r_col];
					que.push({ t_row, t_col });
				}
			}
		}

	}


}

void init() {
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			map[i][j] = INF;
			dp[i][j] = INF;
		}
	}
}

int main() {

	cin >> N >> M;

	init();

	for (int i = 1; i <= M; i++) {
		string str;

		cin >> str;

		for (int j = 1; j <= N; j++) {
			map[i][j] = str[j - 1] - '0';
		}
	}

	bfs();

	cout << dp[M][N];


	return 0;
}