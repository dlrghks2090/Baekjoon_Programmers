// 백준_실버2_DP_연속합

/*

*/

#include<iostream>

using namespace std;

int main() {

	int n;
	int* arr;
	int* dp;
	int sol;

	cin >> n;
	arr = new int[n + 1]{ 0, };
	dp = new int[n + 1]{ 0, };


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];

	sol = dp[1];

	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] + arr[i] > arr[i]) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {
			dp[i] = arr[i];
		}

		if (sol < dp[i]) {
			sol = dp[i];
		}
	}

	cout << sol;

	delete[] arr;
	delete[] dp;

	return 0;
}