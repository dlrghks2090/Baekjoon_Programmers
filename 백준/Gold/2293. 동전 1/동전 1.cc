#include<iostream>

using namespace std;

int map[101] = { 0, };
int dp[10001] = { 0, };

int main() {

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = map[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - map[i]];
		}
	}

	cout << dp[k];

	return 0;
}