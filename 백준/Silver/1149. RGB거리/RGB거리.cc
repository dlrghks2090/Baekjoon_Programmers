#include<iostream>
#include<algorithm>

using namespace std;

int dp[1001][4];
int main() {

	int N;
	int arr[1001][4] = { 0, };	// 모든 갑승ㄹ 0으로 초기화
	int sol = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}

	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	dp[1][3] = arr[1][3];


	for (int i = 2; i <= N; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
	}


	sol = min({ dp[N][1], dp[N][2], dp[N][3] });

	cout << sol;


	return 0;
}