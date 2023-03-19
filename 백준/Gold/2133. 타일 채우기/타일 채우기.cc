#include<iostream>


int dp[31];

using namespace std;

int main() {

	int N;

	cin >> N;


	dp[0] = 1;
	for (int i = 2; i <= N; i = i + 2) {
		for (int j = i - 2; j >= 0; j = j - 2) {
			if (j == i - 2) {
				dp[i] += dp[j] * 3;
			}
			else {
				dp[i] += dp[j] * 2;
			}
		}
	}

	cout << dp[N];



	return 0;
}