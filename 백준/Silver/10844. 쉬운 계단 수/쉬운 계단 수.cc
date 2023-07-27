#include<iostream>
#include<algorithm>

using namespace std;

unsigned long long dp[101][10];

int main() {

	int N;
	unsigned long long sol = 0;

	cin >> N;

	fill(dp[1]+1, dp[1]+10, 1);

	//cout << dp[1][0] << '\n';
	

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {

			if (j != 0 && j != 9) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			else {
				if (j == 0) {
					dp[i][j] = dp[i - 1][j + 1];
				}
				else if (j == 9) {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}

			if (dp[i][j] > 2000000000) {
				dp[i][j] %= 1000000000;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sol += dp[N][i];
	}

	//cout << dp[N][0] << '\n' << sol << '\n';
	
	cout << sol % 1000000000;



	return 0;
}