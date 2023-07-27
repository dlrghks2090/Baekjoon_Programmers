#include<iostream>
#include<vector>

using namespace std;

long long dp[100001][4] = { 0, };
long long dp2[100001] = { 0, };
vector<int> arr;

int main() {

	int T;
	int n;
	
	int  max = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		
		cin >> n;
		arr.push_back(n);
		if (max < n) {
			max = n;
		}
	}

	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;
	dp2[1] = 1;
	
	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 0;
	dp2[2] = 1;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	dp2[3] = 3;


	for (int i = 4; i <= max; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
		dp2[i] = (dp[i][1] + dp[i][2] + dp[i][3]) % 1000000009;
	}

	for (int i = 0; i < T; i++) {
		cout << dp2[arr[i]] << '\n';
	}



	return 0;
}

/*
1

2

1 2 / 2 1 / 3 == 3

1 2 1 / 3 1 / 1 3 == 3

2 1 2 / 3 2 / 2 3 / 1 3 1 == 4

1 2 1 2 / 2 1 2 1 / 1 2 3 /

*/