#include<iostream>

using namespace std;

int dp[1001] = { 0, };
int arr[1001] = { 0, };

int main() {

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (dp[i - j] + arr[j] > dp[i]) {
				dp[i] = dp[i - j] + arr[j];
			}
		}
	}

	cout << dp[N];


	return 0;
}