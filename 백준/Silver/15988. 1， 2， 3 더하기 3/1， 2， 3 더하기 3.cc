#include<iostream>

using namespace std;

long long dp[1000001];

int main() {

	int T;
	int n;

	cin >> T;


	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	/*
	dp[4] = 7;
	dp[5] = 13;
	*/

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = ( dp[i - 1] + dp[i - 2] + dp[i - 3] ) % 1000000009;
	}

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	

	return 0;
}