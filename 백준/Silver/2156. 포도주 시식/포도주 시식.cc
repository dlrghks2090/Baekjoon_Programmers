#include<iostream>
#include<algorithm>

using namespace std;

int arr[10001] = { 0, };
int dp[10001][3] = { 0, };


int main() {

	int n;
	int sol = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	
	dp[1][1] = arr[1];

	dp[2][0] = dp[1][1];
	dp[2][1] = arr[2];
	dp[2][2] = arr[2] + dp[1][1];

	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i-1][0]);
		dp[i][1] = arr[i] + dp[i-1][0];
		dp[i][2] = arr[i] + dp[i - 1][1];
	}

	sol = max(max(dp[n][0], dp[n][1]), dp[n][2]);

	cout << sol;

	return 0;
}