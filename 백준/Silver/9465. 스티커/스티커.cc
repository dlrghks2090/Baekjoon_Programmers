#include<iostream>
#include<algorithm>

using namespace std;

int arr[2][100001];
int dp[3][100001];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	int n;
	int sol;
	int tmp;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		dp[1][1] = arr[0][1];
		dp[2][1] = arr[1][1];

		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = max(dp[0][i - 1] + arr[0][i], dp[2][i - 1] + arr[0][i]);
			dp[2][i] = max(dp[0][i - 1] + arr[1][i], dp[1][i - 1] + arr[1][i]);
		}

		sol = max({ dp[0][n], dp[1][n], dp[2][n] });

		cout << sol << '\n';
	}


	return 0;
}