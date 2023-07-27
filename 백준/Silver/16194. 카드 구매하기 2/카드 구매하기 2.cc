#include<iostream>

using namespace std;

int main() {

	int N;
	int arr[1001] = { 0, };
	int dp[1001] = { 0, };


	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];

	for (int i = 2; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <= i; j++) {
			if (arr[i - j] + dp[j] < dp[i]) {
				dp[i] = arr[i - j] + dp[j];
			}
		}
	}

	cout << dp[N];


	return 0;
}