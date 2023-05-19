#include<iostream>

using namespace std;

int coin[101] = { 0, };
int dp[10001] = { 0, };


void init_dp() {
	for (int i = 0; i < 10001; i++) {
		dp[i] = 100000000;
	}
}

int main() {

	int n, k;

	cin >> n >> k;

	init_dp();

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];

		if (coin[i] <= k)
			dp[coin[i]] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j],1 + dp[j - coin[i]]);
		}
	}

	if (dp[k] == 100000000) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
	return 0;
}