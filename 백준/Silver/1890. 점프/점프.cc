#include<iostream>

using namespace std;


int main() {

	int N;
	int arr[101][101] = { 0, };
	long long dp[101][101] = { 0, };

	cin >> N;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0)
				continue;
			if (dp[i][j] == 0)
				continue;
			if (i + arr[i][j] <= N) {
				dp[i + arr[i][j]][j] += dp[i][j];
			}
			if (j + arr[i][j] <= N) {
				dp[i][j + arr[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[N][N];

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}*/




	return 0;
}