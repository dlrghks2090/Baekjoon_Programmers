#include<iostream>

using namespace std;

int main() {

	int N;
	int* dp;

	cin >> N;

	dp = new int[N + 1]{ 0, };

	for (int i = 1; i <= N; i++) {
		cin >> dp[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i / 2; j++) {
			if (dp[j] + dp[i - j] > dp[i]) {
				dp[i] = dp[j] + dp[i - j];
			}
		}
	}
	

	cout << dp[N];

	delete[] dp;
	return 0;
}