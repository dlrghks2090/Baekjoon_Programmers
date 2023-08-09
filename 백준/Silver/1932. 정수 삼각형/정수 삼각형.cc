#include<iostream>

using namespace std;

int arr[501][501] = { 0, };
int dp[501][501] = { 0, };

int main() {

	int n;
	
	int sol = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (dp[i][j] < dp[i - 1][j] + arr[i][j]) {
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			if (dp[i][j+1] < dp[i - 1][j] + arr[i][j+1]) {
				dp[i][j+1] = dp[i - 1][j] + arr[i][j+1];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sol < dp[n][i]) {
			sol = dp[n][i];
		}
	}

	cout << sol;

	return 0;
}