#include<iostream>

using namespace std;

long long dp[91];

int main() {

	int N;

	cin >> N;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; i++) {

		// dp[i-1]은 맨 오른쪽 수가 0일때의 개수, dp[i-2]는 맨 오른쪽 수가 1일때의 개수
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];


	return 0;
}