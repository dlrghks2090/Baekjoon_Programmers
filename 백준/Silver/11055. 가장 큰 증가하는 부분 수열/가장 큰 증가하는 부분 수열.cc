#include<iostream>

using namespace std;

int main() {

	int N;
	int arr[1001] = { 0, };
	int dp[1001] = { 0, };
	int sol;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	sol = arr[1];

	for (int i = 2; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + arr[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
		}
		if (sol < dp[i]) {
			sol = dp[i];
		}
	}

	cout << sol;


	return 0;
}