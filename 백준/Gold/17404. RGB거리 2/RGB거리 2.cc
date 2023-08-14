#include<iostream>
#include<algorithm>
#define MAX 1000001;

using namespace std;

int arr[1001][3];


int main() {

	int N;
	int sol = MAX;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int color = 0; color < 3; color++) {
		//cout << "========== " << color << "번째 ==========" << '\n';
		int dp[1001][3] = { 0, };
		for (int i = 0; i < 3; i++) {
			if (i == color)
				dp[1][i] = arr[1][i];
			else
				dp[1][i] = MAX;

			//cout << "dp[1][" << i << "] = " << dp[1][i] << '\n';
		}

		
		for (int i = 2; i <= N; i++) {
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];

			/*cout << "dp[" << i << "][0] = " << dp[i][0] << '\n';
			cout << "dp[" << i << "][1] = " << dp[i][1] << '\n';
			cout << "dp[" << i << "][2] = " << dp[i][2] << '\n';*/
		}
		for (int i = 0; i < 3; i++) {
			if (color != i) {
				sol = min(sol, dp[N][i]);
			}
		}
	}
	cout << sol;

	return 0;
}