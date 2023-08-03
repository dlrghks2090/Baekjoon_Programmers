#include<iostream>

using namespace std;

int N;
long long dp[1001][10] = { 0, };
long long sol = 0;


int main() {

	

	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int t = 0; t <= j; t++) {
				dp[i][j] += dp[i - 1][t];
			}
			dp[i][j] %= 10007;
		}
	}

	for (int i = 0; i < 10; i++) {
		sol = sol + dp[N][i];
	}

	//cout << sol << '\n';
	cout << sol%10007;


	return 0;
}