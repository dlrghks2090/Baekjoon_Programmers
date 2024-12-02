#include<iostream>

using namespace std;

int dp[201][201] = { 0, };

int main() {

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= N; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
		}
	}

	cout << dp[N][K];



	return 0;
}


//		1	2	3	4
// 1	1	2	3	4
// 2	1	3	6	10
// 3	1
// 4	1