#include<iostream>
#include<algorithm>

using namespace std;

int dp[100001];
int main() {

	int N;
	int sol = 0;
	int ox = 0;

	cin >> N;

	fill(dp, dp + 100001, 10000);
	dp[1] = 1;

	if (N == 1) {
		sol = 1;
	}
	for (int i = 2; i <= N; i++) {

		for (int j = 1; j*j <= i; j++) {
			if (j * j == i) {
				dp[i] = min(dp[i], 1);
				
			}
			else {
				dp[i] = min(1 + dp[i - j * j], dp[i]);
			}
		}
	

	}

	cout << dp[N];

	return 0;
}