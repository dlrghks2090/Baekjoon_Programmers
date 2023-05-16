#include<iostream>
#include<algorithm>

using namespace std;

int map[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };

int main() {

	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	dp[1][1] = map[1][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			if (i == 1 && j == 1) {
				continue;
			}
			
			dp[i][j] = max({ dp[i - 1][j] + map[i][j], dp[i - 1][j - 1] + map[i][j], dp[i][j - 1] + map[i][j] });
		}
	}

	cout << dp[N][M];


	return 0;
}