#include<iostream>

using namespace std;

int main() {

	int N;

	int arr[1001] = { 0, };
	int dp[1001] = { 0, };
	int sol = 1;

	cin >> N;

	fill_n(dp, 1001, 1);

	//cout << dp[1000] << endl;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		if (sol < dp[i]) {
			sol = dp[i];
		}
	}

	cout << sol;


	return 0;
}